#!/bin/bash
i=1
BITS=64
while [ $i -le $# ]; do
 arg=${!i}
 case "$arg" in
  --*)
   arg="${arg:2}"
   ;;
  -*)
   arg="${arg:1}"
   ;;
  *)
   continue
 esac
 case "$arg" in
  32|64)
   BITS=$arg
   ;;
  "?"|h|H|help)
   TAB=$'\t'
   cat <<EOF
usage: $0 [--OPTION'S]

where OPTION is:
${TAB}-32, --32${TAB}Target 32-bit x86
${TAB}-64, --64${TAB}Target 64-bit x86
${TAB}-h, --help${TAB}Show information

EOF
   exit 0
   ;;
  *)
   echo "unknown option: \"$arg\"" 1>&2
   exit 1   
 esac
 i=$(expr $i + 1)
done

rm -frv bin/ obj/
mkdir -pv bin/ obj/

AS=as
ASFLAGS=
CC=clang
CCFLAGS='-O2 -Wall -Werror -fPIC'
CPPFLAGS='-Iinclude'
LD=clang
LDFLAGS=

shopt -s globstar

LDEMU=elf_x86_64
case $BITS in
 32)
  LDEMU=elf_i386
  ;;
 64)
  LDEMU=elf_x86_64
  ;;
esac

echo " AS ccpuid${BITS}.s"
$AS --$BITS $ASFLAGS -o obj/ccpuid.s.o ccpuid${BITS}.s
echo " CC ccpuid.c"
$CC -m$BITS $CCFLAGS -DCCPUID_BITS=${BITS} $CPPFLAGS -c -o obj/ccpuid.c.o ccpuid.c
echo " LD"
$LD -m$BITS -shared $LDFLAGS -o bin/libccpuid.so obj/**/**.o
