#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//定义变量及结构
typedef unsigned int Index;
struct Node;
typedef struct Node *ListNode;

struct Node{
    char *key;
    char *value;
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
void HashtableInit(unsigned int tablesize)
{
    int i;
    Table *tbl = (Table*)malloc(sizeof(Table));
    tbl->listnode = (ListNode*)malloc(sizeof(struct Node)*tbl->tablesize);
    for(i=0;i<tbl->tablesize;i++)
    {
        tbl->listnode[i]->next = NULL;
    }
}
ListNode seach(Table *table,char * key)
{
    Index index = Hashkey(table,key);
    ListNode position = table->listnode[index]; 
    while(position->next != NULL && (strcmp(position->key,key) != 0))
    {
        position = position->next;
    }
    return position;
}
//insert
void insert(Table *table,char* key,char* value)
{
    if(seach(table,key) == NULL)
    {
        ListNode newest = (ListNode)malloc(sizeof(struct Node));
       if(newest != NULL)
       {
           strcpy(newest->key,key);
           strcpy(newest->value,value);
           newest->next =  table->listnode[Hashkey(table,key)];
           table->listnode[Hashkey(table,key)] = newest;
       }
    }
}
//
void main(void)
{
   char teststring[]="a";
   getchar();
}
