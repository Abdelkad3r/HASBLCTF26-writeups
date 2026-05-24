#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

void win(){
    int fd = open("flag.txt",O_RDONLY);
    unsigned char flag[256] = {0};
    if(fd == -1){
        puts("Couldn't open the flag.txt file. Contact to an administrator!");
        return;
    }
    read(fd,flag,sizeof(flag));
    printf("[!!!!] %s\n",flag);
    close(fd);
}


int main(){
    unsigned char a[32];
    puts("Baby shark doo-doo,doo-doo,doo-doo");
    read(0,a,64);
}