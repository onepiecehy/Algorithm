#include"common.h"
#include<ctype.h>
//定义变量及结构
#define MAX_KEY_LEN 20
#define MAX_VALUESTRING_LEN 20
#define STRINGVALUE
typedef unsigned int Index;
struct Node;
typedef struct Node *ListNode;
typedef struct Node *Position;

#ifdef STRINGVALUE
typedef char ValueType[MAX_VALUESTRING_LEN];
#else
typedef int ValueType;
#endif

typedef struct{
    char key[MAX_KEY_LEN];
	ValueType value;
}Element;

struct Node{
    Element element;
    ListNode next;
};

typedef struct{
    unsigned int tablesize;
    ListNode *listnode;
}Table;

// 定义散列函数
Index Hashkey(Table *table,char* key)
{
    unsigned int hashValue = *(key++) ;
    while(*key != '\0') 
        hashValue +=(*(key++))<<5;
    return hashValue%(table->tablesize);
}

//初始化散列表
Table* HashtableInit(unsigned int tablesize)
{
    int i;
    Table *tbl = (Table*)malloc(sizeof(Table));
	tbl->tablesize = tablesize;
	tbl->listnode = (ListNode*)getUB(sizeof(ListNode)*tablesize);
	tbl->listnode[0] = (ListNode)getUB(sizeof(struct Node)*tablesize);
	if(tbl->listnode != NULL && tbl->listnode[0]!=NULL)
	{
		for(i=1;i<tablesize;i++)
		{
			tbl->listnode[i] = tbl->listnode[i-1]+1;			
		}
		return tbl;
	}
}
Position seach(Table *table,char * key)
{
    Index index = Hashkey(table,key);
    ListNode position = table->listnode[index]; 
	while(position->next != NULL && (strcmp(position->element.key,key) != 0))
    {
        position = position->next;
    }
    return position;
}
//insert
void insert(Table *table,char* key,ValueType value)
{
	if(seach(table,key)->next == NULL)
    {
		Index index =  Hashkey(table,key);
		ListNode pNewNode = (ListNode)getUB(sizeof(struct Node));

       if(pNewNode != NULL)
       {
		   strcpy(pNewNode->element.key,key);
		   #ifdef STRINGVALUE
		   strcpy(pNewNode->element.value,value);
           #else
		   pNewNode->element.value = value;
           #endif
		   pNewNode->next =  table->listnode[index];
           table->listnode[index] = pNewNode;
       }
    }
}
//
void main(void)
{
	int cnt;
	char teststring[][10]={"apple","peal","banana","water","peach","Lemon","Grape","orange","Mango"};
	char valuestring[][5]={"20","10","3","9","12","91","33","28","15"};
   int size = 5;
   Table *tbl = HashtableInit(size);
   for(cnt=0;cnt<9;cnt++)
   {
	   insert(tbl,teststring[cnt],valuestring[cnt]);
   }
   
   getchar();
}
