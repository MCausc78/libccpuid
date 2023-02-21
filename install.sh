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
${TAB}-32, --32${TAB}Install 32-bit x86 binaries
${TAB}-64, --64${TAB}Install 64-bit x86 binaries
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

cp bin/libccpuid$BITS.so /usr/lib
cp include/ccpuid.h /usr/include
