#!/bin/bash

TERMS=("alacritty" "st")
SHELLS=("bash" "fish") #"pwsh -nol")

R_TERM=$(shuf -i 0-100 -n 1)
R_SHELL=$(shuf -i 0-100 -n 1)

TERM=${TERMS[$(expr $R_TERM % 2)]}
SHELL=${SHELLS[$(expr $R_SHELL % 2)]}

eval "$TERM -e $SHELL"
