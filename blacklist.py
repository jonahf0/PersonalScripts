#!/bin/python3

'''
Used to create a blacklist file for including on /etc/unbound/unbound.conf;
pulls from firebog.net
'''

from requests import get
from re import findall

response = get("https://v.firebog.net/hosts/lists.php?type=tick")

conf_lines = []

for link in response.content.splitlines():

    for line in [ line.decode().strip() for line in get(link).content.splitlines()]:
	
        if not len(line) or line[0] == "#":	
            continue

        capture = findall(r'([-a-zA-Z0-9@:%._\+~#=]{1,256}\.[a-zA-Z0-9()]{1,6}\b([-a-zA-Z0-9()@:%_\+.~#?&//=]*))', line)

        if capture:

            conf_lines.append(f"local-zone: {capture[len(capture)-1][0]} always_refuse")
#            else:
#                print(f"local-zone: {capture[0][0]} always_refuse")

for line in set(conf_lines):
    print(line)

        
