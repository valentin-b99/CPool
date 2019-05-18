#!/bin/bash
sed "1d" | sed -n "1~2"p | cut -d: -f 1 | rev | sort -r | sed -n "$MY_LINE1,$MY_LINE2 p" | tr "\n" "," | sed -e "s/,/, /g" -e "s/,.$/.\n/g"
