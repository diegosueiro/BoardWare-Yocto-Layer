DESCRIPTION = "Linux Kernel"
SECTION = "kernel"
LICENSE = "GPL"

inherit kernel

DEPENDS_append_em-x270 = " mtd-utils "

RPSRC = "http://www.rpsys.net/openzaurus/patches/archive"

# Specify the commandline for your device

#boot from mmc
CMDLINE_at91sam9263ek = "mem=64M console=ttyS0,115200 root=/dev/mmcblk0p1 rootfstype=ext2 rootdelay=5"
#boot from nfs
#CMDLINE_at91sam9263ek = "mem=64M console=ttyS0,115200 root=301 root=/dev/nfs nfsroot=172.20.3.1:/data/at91 ip=172.20.0.5:::255.255.0.0"

# Support for device tree generation
FILES_kernel_devicetree = "/boot/devicetree*"
KERNEL_DEVICETREE_FLAGS = "-R 8 -p 0x3000"

python __anonymous () {
    import bb

    devicetree = bb.data.getVar("KERNEL_DEVICETREE", d, 1) or ''
    if devicetree:
        depends = bb.data.getVar("DEPENDS", d, 1)
        bb.data.setVar("DEPENDS", "%s dtc-native" % depends, d)
        packages = bb.data.getVar("PACKAGES", d, 1)
        bb.data.setVar("PACKAGES", "%s kernel-devicetree" % packages, d)
}

do_configure_prepend() {
        echo "" > ${S}/.config

        #
        # logo support, if you supply logo_linux_clut224.ppm in SRC_URI, then it's going to be used
        #
        if [ -e ${WORKDIR}/logo_linux_clut224.ppm ]; then
                install -m 0644 ${WORKDIR}/logo_linux_clut224.ppm drivers/video/logo/logo_linux_clut224.ppm
                echo "CONFIG_LOGO=y"                    >> ${S}/.config
                echo "CONFIG_LOGO_LINUX_CLUT224=y"      >> ${S}/.config
        fi

        #
        # oabi / eabi support
        #
        if [ "${TARGET_OS}" = "linux-gnueabi" -o  "${TARGET_OS}" = "linux-uclibcgnueabi" ]; then
                echo "CONFIG_AEABI=y"                   >> ${S}/.config
                echo "# CONFIG_OABI_COMPAT is not set"             >> ${S}/.config
        else
                echo "# CONFIG_AEABI is not set"        >> ${S}/.config
                echo "# CONFIG_OABI_COMPAT is not set"  >> ${S}/.config
        fi

        echo "CONFIG_CMDLINE=\"${CMDLINE}\"" >> ${S}/.config

        sed -e '/CONFIG_AEABI/d' \
            -e '/CONFIG_OABI_COMPAT=/d' \
            -e '/CONFIG_CMDLINE=/d' \
            -e '/CONFIG_LOGO=/d' \
            -e '/CONFIG_LOGO_LINUX_CLUT224=/d' \
            < '${WORKDIR}/defconfig' >>'${S}/.config'

        #
        # root-over-nfs-over-usb-eth support. Limited, but should cover some cases.
        # Enable this by setting a proper CMDLINE_NFSROOT_USB.
        #
        if [ ! -z "${CMDLINE_NFSROOT_USB}" ]; then
                oenote "Configuring the kernel for root-over-nfs-over-usb-eth with CMDLINE ${CMDLINE_NFSROOT_USB}"
                sed -e '/CONFIG_INET/d' \
                    -e '/CONFIG_IP_PNP=/d' \
                    -e '/CONFIG_USB_GADGET=/d' \
                    -e '/CONFIG_USB_GADGET_SELECTED=/d' \
                    -e '/CONFIG_USB_ETH=/d' \
                    -e '/CONFIG_NFS_FS=/d' \
                    -e '/CONFIG_ROOT_NFS=/d' \
                    -e '/CONFIG_CMDLINE=/d' \
                    -i ${S}/.config
                echo "CONFIG_INET=y"                     >> ${S}/.config
                echo "CONFIG_IP_PNP=y"                   >> ${S}/.config
                echo "CONFIG_USB_GADGET=y"               >> ${S}/.config
                echo "CONFIG_USB_GADGET_SELECTED=y"      >> ${S}/.config
                echo "CONFIG_USB_ETH=y"                  >> ${S}/.config
                echo "CONFIG_NFS_FS=y"                   >> ${S}/.config
                echo "CONFIG_ROOT_NFS=y"                 >> ${S}/.config
                echo "CONFIG_CMDLINE=\"${CMDLINE_NFSROOT_USB}\"" >> ${S}/.config
        fi
        yes '' | oe_runmake oldconfig
}



do_install_prepend() {
        if test -e arch/${ARCH}/boot/Image ; then
             ln -f arch/${ARCH}/boot/Image arch/${ARCH}/boot/uImage
        fi

        if test -e arch/${ARCH}/boot/images/uImage ; then
             ln -f arch/${ARCH}/boot/images/uImage arch/${ARCH}/boot/uImage
        fi

        if test -e arch/${ARCH}/kernel/vmlinux.lds ; then
             ln -f arch/${ARCH}/kernel/vmlinux.lds arch/${ARCH}/boot/vmlinux
        fi
}

do_install_append() {
    if test -n "${KERNEL_DEVICETREE}"; then
        dtc -I dts -O dtb ${KERNEL_DEVICETREE_FLAGS} -o devicetree ${KERNEL_DEVICETREE}
        install -m 0644 devicetree ${D}/boot/devicetree-${KERNEL_VERSION}
        install -d ${DEPLOY_DIR_IMAGE}
        install -m 0644 devicetree ${DEPLOY_DIR_IMAGE}/${KERNEL_IMAGE_BASE_NAME}.dtb
        cd ${DEPLOY_DIR_IMAGE}
        rm -f ${KERNEL_IMAGE_SYMLINK_NAME}.dtb
        ln -sf ${KERNEL_IMAGE_BASE_NAME}.dtb ${KERNEL_IMAGE_SYMLINK_NAME}.dtb
    fi
}
