#!/bin/bash

slstatus -s | lemonbar \
    -f 'Fira Mono' -f 'FontAwesome:size=16'\
    -g 1910x40+4+4 \
    -B "#282a36" \
    -F "#f8f8f2" \
    -U "#f8f8f2" \
    -u 4 \
    | /bin/bash &
