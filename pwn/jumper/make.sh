#!/bin/bash

nasm -f elf64 -o source.o source.asm && gcc -s -no-pie -T link.ld -Wl,--no-warn-rwx-segments -o main main.c source.o