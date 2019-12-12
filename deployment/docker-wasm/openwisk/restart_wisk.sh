#!/bin/bash

### Clone the repo if the folder is not in found
cd ~
DIR="openwhisk-devtools/docker-compose/"
if [ -d "$DIR" ]; then
  echo "wsk make file found..."
else
  echo "${DIR} not found. Cloning repo..."
  cd ~
  git clone https://github.com/apache/openwhisk-devtools.git
  echo "For first time install use: cd ~/openwhisk-devtools/docker-compose/ && sudo make lean"
fi


### Restart OpenWisk services
cd ~/openwhisk-devtools/docker-compose/

echo -e "\e[7m Stopping wsk services \e[27m"
sudo make stop

echo -e "\e[7m Starting wsk services \e[27m"
sudo make run

echo -e "\e[7m Done! Saving config file \e[27m"
export WSK_CONFIG_FILE=~/openwhisk-devtools/docker-compose/.wskprops
source ~/.bashrc

