#include "CycleChain.h"

CycleLinkList* Init_CycleLinkList(void)											//初始化
{
	CycleLinkList* clist = (CycleLinkList*)malloc(sizeof(CycleLinkList));
	clist->head.next = &(clist->head);
	clist->size = 0;
	return clist;
}
void Insert_CycleLinkList(CycleLinkList* clist, int pos, CycleLinkNode* data)   //插入
{
	if (clist == NULL || data == NULL)
	{
		return;
	}
	if (pos < 0 || pos >= clist->size)
	{
		pos = clist->size;
	}
	CycleLinkNode* pCurrent = &(clist->head);
	for (int i = 0; i < pos; i++)
	{
		pCurrent = pCurrent->next;
	}
	data->next = pCurrent->next;
	pCurrent->next = data;
	clist->size++;
}
CycleLinkNode* Front_CycleLinkList(CycleLinkList* clist)						//头节点
{
	return clist->head.next;
}
void RemoveByPos(CycleLinkList* clist, int pos)									//根据位置删除
{
	if (clist == NULL || pos < 0 || pos >= clist->size)
	{
		return;
	}
	CycleLinkNode* pCurrent = &(clist->head);
	for (int i = 0; i < pos; i++)
	{
		pCurrent = pCurrent->next;
	}
	CycleLinkNode* temp = pCurrent->next;
	pCurrent->next = temp->next;
	clist->size--;
}
void RemoveByValue_CycleLinkList(CycleLinkList* clist, CycleLinkNode* data, COMPARENODE compare)		//根据值删除
{
	if (clist == NULL || data == NULL)
	{
		return;
	}
	CycleLinkNode* pPrev = &(clist->head);
	CycleLinkNode* pCurrent = clist->head.next;
	for (int i = 0; i < clist->size; i++)
	{
		if (compare(pCurrent, data) == CYCLELINKLIST_TRUE)
		{
			pPrev->next = pCurrent->next;                                       //删除
			break;
		}
		pPrev = pCurrent;
		pCurrent = pPrev->next;
	}
}
int Size_CycleLinkList(CycleLinkList* clist)									//长度
{
	return clist->size;
}
int IsEmpty_CycleLinkList(CycleLinkList* clist)									//判断是否为空
{
	if (clist->size == 0)
	{
		return CYCLELINKLIST_TRUE;
	}
	return CYCLELINKLIST_FALSE;
}
int Find_CycleLinkList(CycleLinkList* clist, CycleLinkNode* data, COMPARENODE compare)//查找
{
	if (clist == NULL || data == NULL)
	{
		return -1;
	}
	CycleLinkNode* pCurrent = clist->head.next;
	int index= -1;
	for (int i = 0; i < clist->size; i++)
	{
		if (compare(pCurrent, data) == CYCLELINKLIST_TRUE)
		{
			index = i;
			break;
		}
		pCurrent = pCurrent->next;
	}
	return index;
}
void Print_CycleLinkList(CycleLinkList* clist, PRINTNODE print)					//打印
{
	if (clist == NULL)
	{
		return;
	}
	CycleLinkNode* pCurrent = clist->head.next;
	for (int i = 0; i < clist->size* PrintCount; i++)
	{
		if (pCurrent == &(clist->head))
		{
			pCurrent = pCurrent->next;
		}
		print(pCurrent);
		pCurrent = pCurrent->next;
	}
}
void Free_CycleLinkList(CycleLinkList* clist)
{
	if (clist == NULL)
	{
		return;
	}
	free(clist);
}