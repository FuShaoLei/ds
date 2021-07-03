#include <stdio.h>
#include "LinkList.h"

int main() {
    LinkList L;
    InitList(&L);
    CreateList_R(&L,4);
    ListInsert(&L,1,'z');
    ListDelete(&L,2);
    TraverList(L);
    return 0;
}
