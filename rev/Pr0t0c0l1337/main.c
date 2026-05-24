#include "filehandler.h"

int main(){
    unsigned char* buf = malloc(256);
    if(buf == NULL) {
        return -1;
    }
    puts("Say the magic words:");
    read(0,buf,256);
    return InputHandler(buf,256);
}