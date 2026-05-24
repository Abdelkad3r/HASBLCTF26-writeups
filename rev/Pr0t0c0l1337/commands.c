#include "commands.h"

void* arr[COMMAND_NUM] = {0};

void ping(){
    puts("pong");
}

void help(){
    puts("You're the only person that can help yourself.");
}

void cexit(){
    exit(1);
}

void flag(){
    int fd = open("./flag.txt",O_RDONLY);
    char* flag = NULL;
    if(fd == -1) {
        puts("Couldn't open up the flag.txt file. Contact to an administrator!");
        exit(-1);
    }
    flag = malloc(256);
    if(flag == NULL){
        puts("malloc failed.");
        exit(-1);
    }
    read(fd,flag,256);
    printf("Congratulations! Here's your flag: %s\n",flag);
    free(flag);
    exit(0);
}

void Init(){
  arr[0] = ping;
  arr[1] = help;
  arr[2] = exit;
  arr[3] = flag;
}

void CommandHandler(unsigned char cmd){
    void (*pcmd)() = NULL;
    for(int i = 0; i < COMMAND_NUM;i++){
        if(arr[i] == NULL){
            Init();
            if (arr[i] == NULL){
                exit(-1);
            }
        }
    }
    switch(cmd) {
        case PING:
        pcmd = (void(*)())arr[PING];
        break;
        case HELP:
        pcmd = (void(*)())arr[HELP];
        break;
        case EXIT:
        pcmd = (void(*)())arr[EXIT];
        break;
        case FLAG:
        pcmd = (void(*)())arr[FLAG];
        break;
        default:
        puts("Invalid command!");
        exit(1);
        break;
    }
    pcmd();
}