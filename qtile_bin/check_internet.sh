#!/bin/bash

line=$(nmcli -f name,device -t -m tabular connection | rg wlp2s0)

dev="$(echo -n $line | cut -d ":" -f 2)"
ssid="$(echo -n $line | cut -d ":" -f 1)"

string="$dev: $ssid"

#if test $(echo -n $string | wc -c) -gt 12 ; then
#	echo -n "${string:0:15}..."
#else
#	echo -n $string
#fi

echo -n $string
