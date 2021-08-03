#include <stdlib.h>
#include <stdio.h>

#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define MAXSIZE 10
typedef int Status;
typedef int ElemType;
typedef struct { // 线性表的顺序存储结构
    ElemType *elem;
    int length;// 线性表的长度，当长度为 0 时为称为空表
} SqList;

Status InitList(SqList *L); // 初始化操作，建立一个空的线性表L
Status ListEmpty(SqList L); // 若线性表L为空，返回OK，否则返回ERROR
void ClearList(SqList L); // 将线性表清空
Status GetElem(SqList L, int i, ElemType *e); // 将线性表L中的第i个元素赋值给e
int LocateElem(SqList L, ElemType e); // 查找给定e相等的元素，成功返回下标，失败返回0
Status ListInsert(SqList *L, int i, ElemType e); // 在线性表中第i个位置插入元素e
Status ListDelete(SqList *L, int i); //删除线性表中第i个位置的元素
int ListLength(SqList L); // 返回线性表L的元素个数

void DestroyList(SqList *L);

void TraverseList(SqList L);

int main() {
    SqList L;
    InitList(&L);
    ListInsert(&L, 0, 2);
    ListInsert(&L, 0, 3);
    TraverseList(L);
    return 0;
}

Status InitList(SqList *L) {
    (*L).elem = (int *) malloc(MAXSIZE * sizeof(ElemType));
    if ((*L).elem == NULL) return ERROR;
    (*L).length = 0; // 表示空表
    return OK;
}

Status GetElem(SqList L, int i, ElemType *e) {
    if (L.elem == NULL || i < 1 || i > L.length)
        return ERROR;
    *e = L.elem[i - 1];
    return OK;
}

int LocateElem(SqList L, ElemType e) {
    if (!L.elem) return ERROR;
    for (int i = 0; i < L.length; i++) {
        if (L.elem[i] == e) return i;
    }
    return ERROR;
}

Status ListInsert(SqList *L, int i, ElemType e) {
    if (L->length == MAXSIZE) return ERROR;
    if (i < 0 || i > L->length) return ERROR;

    if (i <= L->length) {
        for (int j = L->length - 1; j > i; j--) {
            L->elem[j] = L->elem[j - 1]; // 向后移动一位
        }
    }

    L->elem[i] = e;
    L->length++;
    return OK;
}

Status ListDelete(SqList *L, int i) {
    if (L->length == 0) return ERROR;
    if (i < 0 || i >= L->length) return ERROR;

    for (int j = i; j < L->length - 1; j++) {
        L->elem[j] = L->elem[j + 1]; // 向前移动一个位置
    }
    L->length--;
    return OK;
}


void DestroyList(SqList *L) {
    if ((*L).elem) free(L);
}

void ClearList(SqList L) {
    if (L.elem) L.length = 0;
}

int ListLength(SqList L) {
    if (L.elem) return L.length;
    return ERROR;
}

Status ListEmpty(SqList L) {
    if (L.elem && L.length > 0) return OK;
    return ERROR;
}

void TraverseList(SqList L) {
    if (L.elem == NULL || L.length == 0)
        return;
    printf("L.length = %d\n", L.length);
    for (int i = 0; i < L.length; i++)
        printf("L.elem[%d] = %d\n", i, L.elem[i]);
}