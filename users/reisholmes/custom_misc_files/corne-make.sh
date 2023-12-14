qmk compile -e WPM=yes  users/reisholmes/json/wrapper-corne.json
mv crkbd_rev1_reisholmes.hex crkbd_rev1_reisholmes_left.hex
qmk compile -e WPM=yes -e RIGHT=yes users/reisholmes/json/wrapper-corne.json 
mv crkbd_rev1_reisholmes.hex crkbd_rev1_reisholmes_right.hex
mv crkbd_rev1_reisholmes_* /mnt/c/tmp/