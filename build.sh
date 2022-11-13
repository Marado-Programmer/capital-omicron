#!/bin/sh

set -xe

mkdir -p bin
cc -g -Og -o "bin/$1" "$1.c" -Wall -Wextra -Werror -pedantic -std=c99
