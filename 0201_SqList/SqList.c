#include "SqList.h"
#include <stdlib.h>
#include <stdio.h>

Status InitList(SqList* L) {
	log("InitList");
	(*L).elem = (int*)malloc(MAX_SIZE * sizeof(ElemType));
	if ((*L).elem == NULL) {
		log("InitList ERROR");
		return ERROR;
	}
	(*L).length = 0;
	log("InitList OK");
	return OK;
}

Status GetElem(SqList L, int i, ElemType* e) {
	if (L.elem != NULL && i >= 1 && i <= L.length)
	{
		e = L.elem[i - 1];
		return OK;
	}
	return ERROR;
}

int LocateElem(SqList L, ElemType e)
{
	if (!L.elem) return ERROR;
	for (int i = 0; i < L.length; i++)
	{
		if (L.elem[i] == e) return i;
	}
	return ERROR;
}



Status InsertList(SqList* L, int i, ElemType e)
{
	if ((*L).elem == NULL) {
		return ERROR;
	} 
	for (int j = (*L).length; i!= (*L).length && j > i; j--)
	{
		(*L).elem[j] = (*L).elem[j - 1];
	}
	(*L).elem[i] = e;
	++(*L).length;
	return OK;
}

void DestroyList(SqList* L) {
	if ((*L).elem) free(L);
}

void ClearList(SqList L)
{
	if (L.elem) L.length = 0;
}

int GetLength(SqList L)
{
	if (L.elem) return L.length;
	return ERROR;
}

int IsEmpty(SqList L)
{
	if (L.elem && L.length > 0) return OK;
	return ERROR;
}

void TraverseList(SqList L)
{
	log("TraverseList begin");
	if (L.elem == NULL || L.length == 0) {
		log("list is null or empty");
		return;
	} 
	for (int i = 0; i < L.length; i++)
	{
		log_num(L.elem[i]);
	}
	log("TraverseList finish");
}

void log(char text[]) {
	printf("=============> %s\n", text);
}
void log_num(int num) {
	printf("=============> %d\n", num);
}