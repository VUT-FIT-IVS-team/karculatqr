#!/bin/bash
sudo apt-get -y install libqt5widgets5 libqt5gui5

sudo cp ./karculatqr /usr/bin/karculatqr

chmod a+x uninstall.sh
sudo cp ./uninstall.sh /usr/bin/uninstall_karculatqr

sudo cp karculatqr.desktop /usr/share/applications/karculatqr.desktop
