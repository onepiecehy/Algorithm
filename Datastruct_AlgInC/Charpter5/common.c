#include"common.h"

PBYTE getUB(WORD size)
{
	unsigned char* pMemory = (unsigned char *)malloc(size);
	if(pMemory != NULL)
		memset(pMemory,0,size);
	return pMemory;
}

void retUB(void* wildpointer)
{
    free(wildpointer);
	wildpointer = NULL;
}