#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int ElemType;
typedef int Status;

#define LIST_INIT_SIZE 100 // 初始分配量
#define LIST_INCREMENT 10 // 增量

typedef struct {
    ElemType *elem;
    int length;
    int listSize;
} SqList;

Status initList(SqList *L) {
    L->elem = (ElemType *) malloc(LIST_INIT_SIZE * sizeof(ElemType)); // 开辟初始空间
    if (L->elem == NULL) {
        return ERROR;
    }
    L->length = 0;
    L->listSize = LIST_INIT_SIZE;
    return OK;
}

Status destroyList(SqList *L) {
    free(L);
    return OK;
}

Status insertList(SqList *L, int i, ElemType e) {
    if (i < 1 || i > L->length + 1) {
        return ERROR;
    }
    if (L->length >= L->listSize) {
        ElemType* newbase = (ElemType *) realloc(L->elem, (L->listSize + LIST_INCREMENT) * sizeof(ElemType));
        if(newbase == NULL) exit(OVERFLOW);
        L->elem = newbase;
        L->listSize+=LIST_INCREMENT;
    }
    // 将i-1位置以及其往后的元素像后移动一位
    for (int j = L->length-1; j >=i-1 ; --j) {
        L->elem[j+1] = L->elem[j];
    }
    L->elem[i-1] = e;
    ++L->length;
    return OK;
}

void traverseList(SqList L){
    if(L.elem == NULL) {
        printf("L.elem == NULL");
    }
    for (int i = 0; i < L.length; ++i) {
        printf("L.elem[%d] = %d\n",i,L.elem[i]);
    }
}


int main() {
    SqList L;
    initList(&L);
    insertList(&L,1,54);
    insertList(&L,1,78);
    traverseList(L);
    return 0;
}
