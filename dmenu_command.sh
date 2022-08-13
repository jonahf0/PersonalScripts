#!/bin/bash

#launches dmenu by echoing a newline, then run whatever the user types in bash;
#similar to something like klauncher 

/bin/bash -c $( echo -n | dmenu )
