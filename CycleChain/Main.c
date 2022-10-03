#define _CRT_SECURE_NO_DEPRECATE
#include "CycleChain.h"

typedef struct PERSON
{
	CycleLinkNode node;
	char name[64];
	int age;
	int score;
}Person;

void MyPrint(CycleLinkNode* data)
{
	Person* p = (Person*)data;
	printf("name=%s, age=%d, score=%d\n", p->name, p->age, p->score);
}
int MyCompare(CycleLinkNode* data1, CycleLinkNode* data2)
{
	Person* p1 = (Person*)data1;
	Person* p2 = (Person*)data2;
	if (strcmp(p1->name, p2->name) == 0 && p1->age == p2->age && p1->score == p1->score)
	{
		return CYCLELINKLIST_TRUE;
	}
	return CYCLELINKLIST_FALSE;
}
int main(void)
{
	CycleLinkList* clist = Init_CycleLinkList();
	Person p1, p2, p3;
	strcpy(p1.name, "aaa");
	strcpy(p2.name, "bbb");
	strcpy(p3.name, "ccc");
	p1.age = 18;
	p2.age = 27;
	p3.age = 12;
	p1.score = 90;
	p2.score = 88;
	p3.score = 96;
	Insert_CycleLinkList(clist, 100, (CycleLinkNode*)&p1);
	Insert_CycleLinkList(clist, 100, (CycleLinkNode*)&p2);
	Insert_CycleLinkList(clist, 100, (CycleLinkNode*)&p3);
	Print_CycleLinkList(clist, MyPrint);
	printf("====================================\n");
	Person pDel;
	strcpy(pDel.name, "bbb");
	pDel.age = 27;
	pDel.score = 88;
	RemoveByValue_CycleLinkList(clist, (CycleLinkNode*)&pDel, MyCompare);
	Print_CycleLinkList(clist, MyPrint);
	Free_CycleLinkList(clist);
	return 0;
}