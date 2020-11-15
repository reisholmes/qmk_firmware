#!/bin/sh

# Left Half
make clean
make crkbd:reisholmes
mv crkbd_rev1_reisholmes.hex crkbd_rev1_reisholmes-left.hex

# Right Half
make clean
make crkbd:reisholmes RGB_MATRIX_SPLIT_RIGHT=yes
mv crkbd_rev1_reisholmes.hex crkbd_rev1_reisholmes-right.hex

# must have different checksums
md5sum crkbd_rev1_reisholmes-*
