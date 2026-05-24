#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

void win(){
    char flag[256] = {0};
    int fd = open("./flag.txt",O_RDONLY);
    if(fd == -1){
        puts("Couldn't open the flag file, contact to an administrator!");
        exit(1);
    }
    read(fd,flag,sizeof(flag));
    printf("[!!!] Here's your FLAG: %s\n",flag);
}

void banner(){
    puts("\n######################");
    puts("Choices:\n1-\tChocolate: $65\n2-\tTurkish Delight: $250\n3-\tFLAG: $32,400\n4-\tExit");
    puts("######################");
}


void menu(){
    int choice = 0;
    int16_t balance = 1337; 
    while(choice != 4){
        banner();
        scanf("%d",&choice);
        if(choice == 1) {
            balance -= 65;
        } else if (choice == 2){
            balance -= 250;
        } else if (choice == 3) {
            if(balance < 32400) {
                puts("You don't have enough to buy the FLAG kiddo!");
            } else {
                balance -= 32400;
                win();
            }
        } else {
            puts("Unknown choice!");
        }
        printf("[!] Current balance: %d\n",balance);
    }
}

int main(){
    menu();
    return 0;
}
