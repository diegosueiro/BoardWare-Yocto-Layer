DESCRIPTION = "Linux Kernel for mini2440 development board"
SECTION = "kernel"
LICENSE = "GPL"
PR = "r2"

GGSRC = "http://www.xora.org.uk/oe/patches/"

SRCREV = "${AUTOREV}"

SRC_URI = "git://repo.or.cz/linux-2.6/mini2440.git;protocol=git;branch=mini2440-stable-v2.6.32 \
           file://defconfig-bw-b100 \
	   file://bw-b100.patch;patch=1 \
           file://bw-b100-2.patch;patch=1 \
	   file://bw-b100-3.patch;patch=1 \
	   "
LIC_FILES_CHKSUM = "file://COPYING;md5=d7810fab7487fb0aad327b76f1be7cd7"

S = "${WORKDIR}/git"

KERNEL_IMAGETYPE = "uImage"
UBOOT_ENTRYPOINT = "30008000"

inherit kernel

COMPATIBLE_HOST = "arm.*-linux"
COMPATIBLE_MACHINE = "(bw-b100)"



do_configure() {
	install ${WORKDIR}/defconfig-bw-b100 ${S}/.config
	oe_runmake oldconfig
}

KERNEL_RELEASE = "2.6.32"
