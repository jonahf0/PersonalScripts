#!/bin/bash

QTILE="/home/jonah/.config/qtile"

cp $QTILE/config.py $QTILE/config.py.copy

sed 's/^theme *= *.*/theme = whiscash_theme/g' $QTILE/config.py.copy > $QTILE/config.py

qtile cmd-obj -o cmd -f restart

qtile cmd-obj -o screen -f set_wallpaper --args ~/Pictures/Wallpapers/whiscash.jpg
