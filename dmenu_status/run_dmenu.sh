#!/bin/bash

echo "$(for script in $(ls bin) ; do bin/$script ; done)" | dmenu -fn "BlexMono Nerd Font Mono:pixelsize=22" 
