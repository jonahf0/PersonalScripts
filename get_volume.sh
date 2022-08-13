#!/bin/bash

echo -n "Volume: "
amixer -D pulse sget Master | rg "Front Left: Playback" | rg -o --color never "[0-9][0-9]%"
