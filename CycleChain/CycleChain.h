#ifndef CYCLECHAIN__H
#define CYCLECHAIN__H

#include <stdio.h>
#include <malloc.h>
#include <string.h>
#define CYCLELINKLIST_TRUE  1
#define CYCLELINKLIST_FALSE 0
#define PrintCount          1
typedef struct CYCLELINKNODE
{
	struct CYCLELINKNODE* next;
}CycleLinkNode;																		//节点

typedef struct CYCLELINKLIST
{
	CycleLinkNode head;
	int size;
}CycleLinkList;																		//企业链表

typedef int(*COMPARENODE)(CycleLinkList*, CycleLinkList*);
typedef void(*PRINTNODE)(CycleLinkList*);

CycleLinkList* Init_CycleLinkList(void);											//初始化
void Insert_CycleLinkList(CycleLinkList* clist, int pos, CycleLinkNode* data);      //插入
CycleLinkNode* Front_CycleLinkList(CycleLinkList* clist);							//头节点  
void RemoveByPos(CycleLinkList* clist, int pos);									//根据位置删除
void RemoveByValue_CycleLinkList(CycleLinkList* clist, CycleLinkNode* data,COMPARENODE compare);		//根据值删除
int Size_CycleLinkList(CycleLinkList* clist);										//长度
int IsEmpty_CycleLinkList(CycleLinkList* clist);									//判断是否为空
int Find_CycleLinkList(CycleLinkList* clist, CycleLinkNode* data, COMPARENODE compare);//查找
void Print_CycleLinkList(CycleLinkList* clist, PRINTNODE print);					//打印
void Free_CycleLinkList(CycleLinkList* clist);
#endif
