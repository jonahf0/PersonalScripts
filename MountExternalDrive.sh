#!/bin/bash

sudo mount $( sudo fdisk -l | rg "HPFS/NTFS/exFAT" | rg -o "/dev/sd.." ) /media/Drive
