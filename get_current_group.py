#!/bin/python3

'''
Grabs info from "xprop -root" command, then searches for info about the current desktop and all desktop names;
this is for grabbing info about things like group names in qtile or tags in dwm (if it's patched)
'''

from subprocess import check_output

output = check_output(["xprop", "-root"])

lines = [ line.split(" = ") for line in  output.decode().strip().split("\n") ]

mapped_lines = { val[0]:val[1] for val in lines if len(val) > 1 }

current_group = int(mapped_lines["_NET_CURRENT_DESKTOP(CARDINAL)"])

groups = mapped_lines["_NET_DESKTOP_NAMES(UTF8_STRING)"].replace("\"", "").split(", ")

current_name = groups[current_group]

print(
	" ".join(
		[ f'[{val}]' if val == current_name else val for val in groups ] 
	)
)
