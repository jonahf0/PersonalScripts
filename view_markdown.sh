#!/bin/bash

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
