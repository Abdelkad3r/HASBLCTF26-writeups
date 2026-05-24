#include "game.h"

void intro(){
    puts("Once upon a time, There was a cat called Pamuk.");
    puts("Pamuk was a very lucky cat because he had a lovely family. Additionally, his brother was a master hacker.");
    puts("By two of em spending more time together, his brother taught him some reversing and hacking skills.");
    puts("Being amazed by how skillful he is, Pamuk started learning more from him.");
    puts("Whenever his brother puts on his magical red hoodie and starts hacking, Pamuk jumps on his lap and starts hacking with him.");
    puts("\nOnce, Umut came home from school but this time he didn't play with Pamuk and went to bed directly. He looked tired.");
    puts("Pamuk knew that how much his brother hates going school and doing his homework. So, he decided to help him.");
    puts("This time he wears the magical red hoodie and starts hacking...");
}

int main(){
    intro();
    if(!Init()){
        return -1;
    }
    menu();
    return 0;
}