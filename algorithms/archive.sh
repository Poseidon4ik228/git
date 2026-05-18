#!/bin/sh

zip -r archive.zip "$1" -x $(cat "$1/.gitignore")
