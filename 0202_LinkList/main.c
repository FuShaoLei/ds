#include <stdio.h>
#include "LinkList.h"

int main() {
    LinkList L;
    InitList(&L);
    CreateList_H(&L,4);
    TraverList(L);
    return 0;
}
