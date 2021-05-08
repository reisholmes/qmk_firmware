#!/bin/sh

# Left Half
make clean
make crkbd:reisholmes
mv crkbd_rev1_legacy_reisholmes.hex crkbd_rev1_reisholmes-left.hex

# Right Half
make clean
make crkbd:reisholmes RGB_MATRIX_SPLIT_RIGHT=yes
mv crkbd_rev1_legacy_reisholmes.hex crkbd_rev1_reisholmes-right.hex
# must have different checksums
md5sum crkbd_rev1_reisholmes-*


mv crkbd_rev1_reisholmes* /mnt/c/Documents\ and\ Settings/reis_/Desktop/


#Userspace method
# Left Half
make clean
qmk compile ~/qmk_firmware/users/reisholmes/json/crkbd.json -e WPM=YES
mv crkbd_rev1_common_reisholmes.hex crkbd_rev1_reisholmes-left.hex

# Right Half
make clean
qmk compile ~/qmk_firmware/users/reisholmes/json/crkbd.json -e WPM=YES -e RGB_MATRIX_SPLIT_RIGHT=yes
mv crkbd_rev1_common_reisholmes.hex crkbd_rev1_reisholmes-right.hex
# must have different checksums
md5sum crkbd_rev1_reisholmes-*


mv crkbd_rev1_reisholmes* /mnt/c/Documents\ and\ Settings/reis_/Desktop/
