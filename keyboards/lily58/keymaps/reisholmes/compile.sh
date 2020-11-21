#!/bin/sh

# Left Half
make clean
make lily58:reisholmes
mv lily58_rev1_reisholmes.hex lily58_rev1_reisholmes-left.hex

# Right Half
make clean
make lily58:reisholmes RGB_MATRIX_SPLIT_RIGHT=yes
mv lily58_rev1_reisholmes.hex lily58_rev1_reisholmes-right.hex

# must have different checksums
md5sum lily58_rev1_reisholmes-*

mv lily58* /mnt/c/Documents\ and\ Settings/reis_/Desktop/
