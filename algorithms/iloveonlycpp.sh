#!/bin/sh

find . -mindepth 1 \( ! -name "*.cpp" -a ! -name "*.hpp" -a ! -name "iloveonlycpp.sh" \) -delete
