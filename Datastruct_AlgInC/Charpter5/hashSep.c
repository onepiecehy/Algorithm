#include<stdio.h>

//define variable
#define TABLESIZE 1000
typedef struct{
    char *key = NULL;
    char *value = NULL;
    Node *next = NULL;
}Node;

Node *table[TABLESIZE];

//define hash function

//define conflict handle function

