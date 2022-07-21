#!/bin/bash

echo -n "Volume: "
amixer -D pulse sget Master | rg "Front Left: Playback" | rg -o "[0-9][0-9]%"
