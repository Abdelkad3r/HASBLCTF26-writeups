#include <float.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define BOOL unsigned char

enum Swords {
    nothing,
    WoodenSword,
    IronSword,
    DiamondSword,
    AdminSword = 5
};


typedef struct {
 int Health;
 float XP;
 unsigned int Coin;
 unsigned int Damage;
 unsigned char CurrentSword;
} PamukStats;

enum EnemyType {
    StreetPunk,
    ScriptKiddie,
    SchoolBully,
    IgnorantIdiot,
};


typedef struct {
    unsigned char EnemyType;
    int Health;
    unsigned int Damage;
    float XP;
    unsigned int Coin;
} EnemyStats;

BOOL Init();
void menu();