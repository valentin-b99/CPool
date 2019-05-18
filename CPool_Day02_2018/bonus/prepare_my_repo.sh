#!/bin/bash
blih -u valentin.bonnet@epitech.eu repository create $1
blih -u valentin.bonnet@epitech.eu repository setacl $1 ramassage-tek r
blih -u valentin.bonnet@epitech.eu repository getacl $1
