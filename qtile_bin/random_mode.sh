#!/bin/bash

THEMES=("dracula" "nord_strict" "nord_colorful")

SELECT=${THEMES[$(shuf -i 0-2 -n 1)]}

QTILE="/home/jonah/.config/qtile"

cp $QTILE/config.py $QTILE/config.py.copy

sed "s/^theme *= *.*/theme = $(echo $SELECT)_theme/g" $QTILE/config.py.copy > $QTILE/config.py

qtile cmd-obj -o cmd -f restart
