#!/bin/bash

#opens a markdown file in a web browser;
#first arg is browser, 2nd arg is the file to open, 3rd is probably not needed 
#but represents the time to wait for before deleting the tmp file created

BROWSER=${1:-firefox}
FILE=${2:-README.md}
TIME=${3:-".1"}

tmpfile=$(mktemp /tmp/abc-script.XXXXXX)
exec 3>"$tmpfile"
exec 4<"$tmpfile"

markdown $FILE >&3 "$tmpfile"
$BROWSER "$tmpfile"
sleep $TIME
rm "$tmpfile"
