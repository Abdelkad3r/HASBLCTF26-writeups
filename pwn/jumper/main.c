#include <sys/mman.h>
#include <stddef.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

extern void _b0(void);

#define MEMORY_SIZE 9

int main(){
    unsigned char* buf = (unsigned char*)mmap(NULL,MEMORY_SIZE,PROT_READ|PROT_WRITE|PROT_EXEC,MAP_PRIVATE | MAP_ANONYMOUS,-1,0);
    if(buf == MAP_FAILED){
        perror("mmap failed");
        return -1;
    }
    puts("Another mission right boss?");
    memset(buf,0x00,MEMORY_SIZE);
    read(0,buf,7);
    buf[7] = 0xff;
    buf[8] = 0xe2;
    ((void(*)())buf)();
    munmap(buf,MEMORY_SIZE);
    return 0;
}
