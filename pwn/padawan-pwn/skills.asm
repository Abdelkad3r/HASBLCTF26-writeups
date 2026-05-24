section .text

global attack
global dodge
global finish

attack:
 mov rax,0x1337
 xor ecx,ecx
l:
 cmp ecx,47
 je attack
 inc rax

 pop rdi
 ret

dodge:
 mov rdi, 0x4444
 mov rsi, 0x123456
 mov rdx, 0x721321
 xor rbx,rbx
 push rbx
 ret

 xor eax,eax
 pop rsi
 ret

finish:
 db "bang",0
 pop rdx
 ret

