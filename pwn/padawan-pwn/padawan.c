#include <stdio.h>
#include <unistd.h>
#include <stdint.h>
#include <fcntl.h>
#include <stdlib.h>

extern int attack();
extern int dodge();
extern int finish();


void strike(uint64_t skill1,uint64_t skill2, uint64_t skill3){
    int fd = open("flag.txt", O_RDONLY);
    char* flag = malloc(256);
    if(fd == -1){
        puts("Couldn't open the flag.txt file, contact to an administrator!");
        exit(-1);
    }
    if(skill1 != 0xdeadcafe){
        puts("You couldn't attack!");
        exit(1);
    }
    puts("[The Darth Vader]: Not bad! Now I'll show you the power of the dark side!");

    if(skill2 != 0xcafebabe) {
        puts("You couldn't dodge!\n");
        exit(1);
    }

    puts("End him now!");

    if(skill3 != 0xdeadc0de) {
        puts("[The Darth Vader] You dont have whatever it takes!");
        exit(1);
    }
    read(fd,flag,256);
    printf("%s\n",flag);
    close(fd);
}


void banner(){
    for(char i = 0;  i < 44; i++) {
        printf("#");
    }
    puts("\nA long time ago in a server far, far away....\n");
    puts("\nSTAR WARS\n");
    puts("\nEpisode 0x90\n\n");
    puts("THE ORDER OF THE BUFFER OVERFLOW");
    puts("The galaxy is under the iron grip of the Dark Side. Darth vader has deployed the ultimate defense:\n");
    puts("a binary completely shielded by the dreaded nx bit, rendering traditional shellcode and overflow tricks useless.\n");
    puts("Desperate to defeat his father and restore a shell to the system, young jedi Luke Skywalker journeys to the murky memory dumps of the Dagobah cluster.\n");
    puts("There, he seeks the wisdom of Jedi Master Yoda, the legendary grandmaster of ROPFU.\n");
}

int main(){
    char skills[32] = {0};
    banner();
    puts("\n\nThe Darth Vader strikes and Luke perfectly dodges it!\n");
    puts("[The Darth Vader]: Not bad at all! Now, show me what you got:\n> ");
    read(0,skills,128);
    return 0;
}
