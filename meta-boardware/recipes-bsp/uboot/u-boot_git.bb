require u-boot.inc

LICENSE = "GPLv2+"
LIC_FILES_CHKSUM = "file://COPYING;md5=4c6cde5df68eff615d36789dc18edd3b \
                    file://README;beginline=1;endline=22;md5=3a00ef51d3fc96e9d6c1bc4708ccd3b5"

FILESDIR = "${@os.path.dirname(bb.data.getVar('FILE',d,1))}/u-boot-git/${MACHINE}"

PV = "v2010.12+${PR}+git${SRCPV}"
PR="r0"

SRC_URI = "git://git.denx.de/u-boot.git;branch=master;protocol=git"

SRC_URI_bw-b100 = "git://repo.or.cz/u-boot-openmoko/mini2440.git;protocol=git;branch=dev-mini2440-stable"
LIC_FILES_CHKSUM_bw-b100 = "file://COPYING;md5=4c6cde5df68eff615d36789dc18edd3b \
                    	    file://README;beginline=1;endline=22;md5=ad8b2e82fdb62c692f9eb646748d8fe5"


do_deploy_prepend_bw-b100() {
       cp ${S}/u-boot-nand2k.bin ${S}/u-boot.bin
}


UBOOT_MACHINE_beagleboard = "omap3_beagle_config"
UBOOT_MACHINE_overo = "omap3_overo_config"
UBOOT_MACHINE_bw-b600 = "omap3_beagle_config"
UBOOT_MACHINE_bw-b100 = "mini2440_config"


S = "${WORKDIR}/git"

PACKAGE_ARCH = "${MACHINE_ARCH}"

COMPATIBLE_MACHINE = "(beagleboard|overo|bw-b600|bw-b100)"
