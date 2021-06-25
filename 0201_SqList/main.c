#include <stdio.h>
#include "SqList.h"

int main() {
	SqList L;
	InitList(&L);
	InsertList(&L,0,1);
	InsertList(&L, 0, 2);
	InsertList(&L, 0, 3);
	InsertList(&L, 0, 4);
	InsertList(&L, 0, 5);
	InsertList(&L, 0, 6);
	TraverseList(L);
	return 0;
}