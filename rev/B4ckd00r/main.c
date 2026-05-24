#include "malware.h"

int main(){
    if(geteuid()){
        return -1;
    }
    while(1){
        if(CheckProcesses()){
            break;
        }
    }
    win();
    return 0;
}