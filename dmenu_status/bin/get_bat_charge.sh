#!/bin/bash

echo -n "Battery: "
echo $(upower -i /org/freedesktop/UPower/devices/battery_BAT0 | rg 'percentage') |  cut -d " " -f 2
