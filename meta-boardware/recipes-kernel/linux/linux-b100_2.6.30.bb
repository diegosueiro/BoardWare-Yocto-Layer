DESCRIPTION = "Linux Kernel for b100 development boards"
SECTION = "kernel"
LICENSE = "GPLv2"
#PR = "r0"

LIC_FILES_CHKSUM = "file://COPYING;md5=d7810fab7487fb0aad327b76f1be7cd7"

require linux.inc

SRCREV = ""
#DEFAULT_PREFERENCE = "-1"
#DEFAULT_PREFERENCE_bw-b100 = "1"
#DEFAULT_PREFERENCE_micro2440 = "1"

SRC_URI = "file:///home/dev/sources/linux-2.6.30.4-bw-b100.tar.gz \
           file://defconfig"

S = "${WORKDIR}/linux-2.6.30.4"

COMPATIBLE_HOST = "arm.*-linux"
COMPATIBLE_MACHINE = "(bw-b100)"


KERNEL_IMAGETYPE = "uImage"
UBOOT_ENTRYPOINT = "30008000"

#do_configure() {
#        install ${WORKDIR}/config_G35_64MB ${S}/.config
#        oe_runmake oldconfig
#}
KERNEL_RELEASE = "2.6.30"
