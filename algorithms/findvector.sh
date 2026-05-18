#!/bin/sh

find "$1" -type f -name "*.cpp" -exec grep -l "#include *<vector>" {} +
