#Setting up the eeprom for left and right
sudo qmk flash -kb crkbd/rev1/common -km default -bl dfu-split-left
sudo qmk flash -kb crkbd/rev1/common -km default -bl avrdude-split-right
#sudo make crkbd:defaut:avrdude-split-right

#If clean build wanted
make clean

#Left side
qmk flash -e WPM=yes users/reisholmes/json/corne.json

#Right side
qmk flash -e WPM=yes users/reisholmes/json/corne.json -bl avrdude