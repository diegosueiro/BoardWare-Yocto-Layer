#
# Copyright (C) 2007 OpenedHand Ltd.
#
IMAGE_INSTALL = "task-poky-boot ${ROOTFS_PKGMANAGE} update-rc.d dropbear mtd-utils task-base kernel-modules \
		 \
		"

IMAGE_LINGUAS = " "

LICENSE = "MIT"

inherit poky-image

# remove not needed ipkg informations
ROOTFS_POSTPROCESS_COMMAND += "remove_packaging_data_files ; "
