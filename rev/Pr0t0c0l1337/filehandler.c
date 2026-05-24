#include "filehandler.h"

int InputHandler(unsigned char* input,size_t size){
    int ret = 1;
    uint16_t MagicHeader = 0;
    size_t i = 0; unsigned int j = 0;
    if(input == NULL || size == 0) {
        goto end;
    }
    
    MagicHeader = *(uint16_t*)input;
    if(MagicHeader != MAGIC_HEADER){
        printf("Invalid Magic Header: 0x%04x\n",MagicHeader);
        goto end;
    }

    for (i = 2,j = 0; i < size && j != 144; i++){
        if(input[i] == 0x84){
            j++;
        } else {
            printf("Invalid payload! j = %d\n",j);
            goto end;
        }
    }

    while(i < size){
        if(input[i] == 'r') {
            i++;
        } else {
            goto end;
        }
        if(input[i] == 'o') {
            i++;
        } else {
            goto end;
        }
        if(input[i] == 'o') {
            i++;
        } else {
            goto end;
        }
        if(input[i] == 't') {
            i++;
        } else {
            goto end;
        }
        break;
    }
    ret = 0; 
    CommandHandler(input[i]);
end:
    return ret;    
}