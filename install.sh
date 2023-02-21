#!/bin/bash
TARGET=$(uname -m)-linux-gnu
cp bin/libccpuid.so /usr/lib/$TARGET/
cp include/ccpuid.h /usr/include/$TARGET/
