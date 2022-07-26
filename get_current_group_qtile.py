#!/usr/bin/python3

'''
Similar to the more generic script, but this one came first;
Launches an interactive command client to grab desktops info from qtile
'''

from libqtile.command.client import InteractiveCommandClient

client = InteractiveCommandClient()

groups = client.groups()

group_list = []

'''
for group in groups:
	if groups[group]['screen'] != None:
		print(f"[{group}]", end=" ")

	elif groups[group]['windows']:
		print(group, end=" ")
'''

group_list = [ f"[{group}]" if groups[group]['screen'] != None else group for group in groups if groups[group]['windows'] ] 

print(" ".join(group_list))
