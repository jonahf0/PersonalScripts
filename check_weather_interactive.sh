#!/bin/bash

LOCATION=${1:-'Boston'}

curl --silent https://wttr.in/$LOCATION | less -R
