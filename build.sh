#!/bin/bash
rm -frv bin/ obj/
mkdir -pv bin/ obj/

AS=as
ASFLAGS=
CC=clang
CCFLAGS='-O2 -Wall -Werror'
CPPFLAGS='-Iinclude'
LD=clang
LDFLAGS=

shopt -s globstar

$AS $ASFLAGS -o obj/ccpuid.s.o ccpuid.s
$CC $CCFLAGS $CPPFLAGS -c -o obj/ccpuid.c.o ccpuid.c
$LD -shared $LDFLAGS -o bin/libccpuid.so obj/**/**.o
