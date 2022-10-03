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
}CycleLinkNode;																		//�ڵ�

typedef struct CYCLELINKLIST
{
	CycleLinkNode head;
	int size;
}CycleLinkList;																		//��ҵ����

typedef int(*COMPARENODE)(CycleLinkList*, CycleLinkList*);
typedef void(*PRINTNODE)(CycleLinkList*);

CycleLinkList* Init_CycleLinkList(void);											//��ʼ��
void Insert_CycleLinkList(CycleLinkList* clist, int pos, CycleLinkNode* data);      //����
CycleLinkNode* Front_CycleLinkList(CycleLinkList* clist);							//ͷ�ڵ�  
void RemoveByPos(CycleLinkList* clist, int pos);									//����λ��ɾ��
void RemoveByValue_CycleLinkList(CycleLinkList* clist, CycleLinkNode* data,COMPARENODE compare);		//����ֵɾ��
int Size_CycleLinkList(CycleLinkList* clist);										//����
int IsEmpty_CycleLinkList(CycleLinkList* clist);									//�ж��Ƿ�Ϊ��
int Find_CycleLinkList(CycleLinkList* clist, CycleLinkNode* data, COMPARENODE compare);//����
void Print_CycleLinkList(CycleLinkList* clist, PRINTNODE print);					//��ӡ
void Free_CycleLinkList(CycleLinkList* clist);
#endif
