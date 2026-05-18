#!/bin/sh

case "$1" in
	"build") mkdir -p "./Build" && clang++ "$2" -o  "./Build/a.out";;

	"run") mkdir -p "./Build" && clang++ "$2" -o "./Build/a.out" && "./Build/a.out";;

	"clean") rm -R "./Build";;

	*) echo "Error";;
esac
