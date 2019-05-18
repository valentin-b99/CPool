#!/bin/bash
cut -d";" -f 3 | grep -ci "$1"
