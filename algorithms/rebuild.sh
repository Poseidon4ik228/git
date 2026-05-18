#!/bin/sh

echo "$1" | entr clang++ "$1" -o "main"
