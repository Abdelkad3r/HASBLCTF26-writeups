#include "game.h"

PamukStats* pPamukStats = NULL;
EnemyStats* pEnemyStats = NULL;
EnemyStats* pHomeworkStats = NULL;

unsigned char SwordList[] = {nothing,WoodenSword,IronSword,DiamondSword,AdminSword};
unsigned int SwordDamageList[] = {0,20,40,250,0,99999};
unsigned int SwordPriceList[] = {0,100,200,1000,0,0};

unsigned char EnemyTypeList[] = {StreetPunk,ScriptKiddie,SchoolBully,IgnorantIdiot};
unsigned int EnemyDamageList[] = {20,15,10,5};
float EnemyXPList[] = {6.5,3.5,4,0.5};
unsigned int EnemyCoinList[] = {125,70,85,15};

void Free(){
    if(pPamukStats) {
        free(pPamukStats);
    }
    if(pHomeworkStats) {
        free(pHomeworkStats);
    }
    if(pEnemyStats) {
        free(pEnemyStats);
    }
}


void CreateRandomEnemy(){
    memset(pEnemyStats,0,sizeof(EnemyStats));
    time_t ltime = time(NULL);
    srand(ltime);
    
    pEnemyStats->Health = 100;
    pEnemyStats->EnemyType = rand() % 4;
    pEnemyStats->Damage = EnemyDamageList[pEnemyStats->EnemyType];
    pEnemyStats->Coin = EnemyCoinList[pEnemyStats->EnemyType];
    pEnemyStats->XP = EnemyXPList[pEnemyStats->EnemyType];
}

void FightWithEnemy(EnemyStats* pEnemy){ 
    while(1) {
        if(pPamukStats->Health <= 0) {
            printf("You have lost the fight!\n");
            Free();
            exit(-1);
        }
        
        printf("[!] Pamuk's Health: %%%d\n[!] Pamuk Attacks!\n",pPamukStats->Health);
        pEnemy->Health -= pPamukStats->Damage;
        
        if(pEnemy->Health <= 0) {
            printf("You have won the fight!\n");
            pPamukStats->Coin += pEnemy->Coin;
            pPamukStats->XP += pEnemy->XP;
            pPamukStats->Damage += 3;
            if((pPamukStats->Health + 30) <=100){
                pPamukStats->Health += 30;
            } else if (pPamukStats->Health < 100) {
                pPamukStats->Health += (100 - pPamukStats->Health);
            }
            break;
        }
        printf("[!] Enemy's Health: %%%d\n[!] Enemy Attacks!\n",pEnemy->Health);
        pPamukStats->Health -= pEnemy->Damage;
    }
}

void market(){
    unsigned int choice = 0;
    unsigned char sword = 0;
    unsigned int price = 0;
    printf("################[WELCOME!!!]################\n#\t1- Wooden Sword : 100 Coins\n#\t2- Iron Sword : 200 Coins\n#\t3- Diamond Sword: 1000 Coins\n############################################\nEnter your choice:\n");
    scanf("%d",&choice);
    for(unsigned int i = 1; i < sizeof(SwordList);i++){
        if(SwordList[i] == choice) {
            sword = choice;
            break;
        }
    }

    if(sword && pPamukStats->CurrentSword != sword && (price = SwordPriceList[sword]) <= pPamukStats->Coin && price) {
        pPamukStats->Coin -= price;
        pPamukStats->CurrentSword = sword;
        pPamukStats->Damage = SwordDamageList[sword];  
        printf("Bought a new sword!\nYour current damage: %u\nYour current coin: %u\n",pPamukStats->Damage,pPamukStats->Coin);

    } else {
        printf("Unknown choice!\n");
    }
    printf("See you soon!..\n");
}


void printhealthbar(){
    printf("Pamuk\nHealth: ");
    for(int i = 0; i < (pPamukStats->Health / 4); i++){
        printf("#");
    }
    printf(" %%%d\n",pPamukStats->Health);
}



void menu(){
    unsigned int choice = 0;
    int fd = 0;
    char flag[256] = {0};
    while(choice != 4){
        printf("\n\n##################################################\n");
        printhealthbar();
        printf("XP: %f\n",pPamukStats->XP);
        printf("Coins: %u\n",pPamukStats->Coin);
        printf("Damage: %u\n",pPamukStats->Damage);
        printf("\n\nHomework: Do you really think that you can beat me?\n");
        printf("\n\n##################################################\n");
        printf("#\t1 - Fight with Homework\t\t2 - Market\n#\t3 - Fight with Random Enemies\t4 - Exit\n");
        printf("###################################################\n");
        
        scanf("%u",&choice);
        switch(choice){
            case 1:
            if(pPamukStats->XP <=15.8) {
                printf("Homework: You're not ready to face me yet!\n");
                break;
            }
            FightWithEnemy(pHomeworkStats);
            fd = open("flag.txt",O_RDONLY);
            if(fd == -1){
                printf("Couldn't open the flag.txt file. Contact to an administrator!\n");
                break;
            }
            read(fd,flag,256);
            printf("Homework: You were not bad at all. Here's your flag: %s\n",flag);
            Free();
            exit(1337);
            case 2:
            market();
            break;
            case 3:
            CreateRandomEnemy();
            FightWithEnemy(pEnemyStats);
            break;
            case 10:
            if(pPamukStats->XP >= 18 && pPamukStats->Coin >= 600){
                pPamukStats->Damage = SwordDamageList[AdminSword];
            }
            break;
            default:
            printf("Unknown choice!\n");

        }
    }
    printf("Homework: I knew you couldn't beat me!\n");
    Free();
}


BOOL Init(){
    BOOL r = 0;
    if(pPamukStats == NULL){
        pPamukStats = malloc(sizeof(PamukStats));
        if(pPamukStats == NULL) {
            goto end;
        }
    memset(pPamukStats,0,sizeof(PamukStats));
    pPamukStats->Health = 100;
    pPamukStats->Coin = 150;   
    }
    if(pEnemyStats == NULL){
        pEnemyStats = malloc(sizeof(EnemyStats));
        if(pEnemyStats == NULL){
            goto end;
        }
    memset(pEnemyStats,0,sizeof(EnemyStats));    
    }
    if(pHomeworkStats == NULL){
        pHomeworkStats = malloc(sizeof(EnemyStats));
        if(pEnemyStats == NULL) {
            goto end;
        }
    memset(pHomeworkStats,0,sizeof(EnemyStats));
    pHomeworkStats->Health = 9337;
    pHomeworkStats->Damage = 99;
    pHomeworkStats->Coin = 99999;
    pHomeworkStats->XP = 1337;    
    }
    r = 1;
end:
    return r;    
}

