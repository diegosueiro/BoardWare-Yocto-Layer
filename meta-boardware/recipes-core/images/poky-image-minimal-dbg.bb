#
# Copyright (C) 2007 OpenedHand Ltd.
#
IMAGE_INSTALL = "task-poky-boot task-poky-tools-debug ${ROOTFS_PKGMANAGE} update-rc.d dropbear"
#IMAGE_INSTALL = "${ROOTFS_PKGMANAGE}"
IMAGE_FEATURES += "debug-tweaks"
IMAGE_LINGUAS = " "

LICENSE = "MIT"

inherit poky-image

# remove not needed ipkg informations
ROOTFS_POSTPROCESS_COMMAND += "remove_packaging_data_files ; "
