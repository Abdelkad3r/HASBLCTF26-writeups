#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#define COMMAND_NUM 4

enum Commands {
    PING,
    HELP,
    EXIT,
    FLAG,
};

void Init();

void CommandHandler(unsigned char cmd);

//void CommandParser();