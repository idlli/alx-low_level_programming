#!/bin/bash
wget -q https://github.com/Blxee/alx-low_level_programming/raw/main/0x18-dynamic_libraries/libcrack.so -O /tmp/libcrack.so
export LD_PRELOAD='/tmp/libcrack.so'
