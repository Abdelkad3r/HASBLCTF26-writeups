#!/bin/bash

nasm -f elf64 skills.asm -o skills.o
gcc -no-pie -fno-stack-protector padawan.c skills.o -o padawan
