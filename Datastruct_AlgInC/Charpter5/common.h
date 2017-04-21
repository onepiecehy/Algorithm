#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef unsigned char BYTE;
typedef unsigned char *PBYTE;
typedef unsigned int WORD;
typedef unsigned long DWORD;
extern PBYTE getUB(WORD size);
extern void retUB(void* wildpointer);