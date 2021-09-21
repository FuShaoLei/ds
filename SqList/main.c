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
    int length; // 有效长度
    int listSize; // 分配的空间
} SqList;

/**
 * 初始化
 */
Status initList(SqList *L) {
    L->elem = (ElemType *) malloc(LIST_INIT_SIZE * sizeof(ElemType)); // 开辟初始空间
    if (L->elem == NULL) {
        return ERROR;
    }
    L->length = 0;
    L->listSize = LIST_INIT_SIZE;
    return OK;
}

/**
 * 销毁
 */
Status destroyList(SqList *L) {
    free(L);
    return OK;
}

/**
 * 插入算法
 * 1，判断插入位置i的合法性
 * 2，若存储空间满了则增空间
 * 3，将i-1位置以及其往后的元素像后移动一位
 * 4，将i-1位置的元素赋值为e
 * 5，有效长度增加1
 */
Status insertList(SqList *L, int i, ElemType e) {
    if (i < 1 || i > L->length + 1) { // 当i == L->length + 1 是插入在末尾的
        return ERROR;
    }
    if (L->length >= L->listSize) {
        ElemType *newbase = (ElemType *) realloc(L->elem, (L->listSize + LIST_INCREMENT) * sizeof(ElemType));
        if (newbase == NULL) exit(OVERFLOW);
        L->elem = newbase;
        L->listSize += LIST_INCREMENT;
    }
    for (int j = L->length - 1; j >= i - 1; --j) {
        L->elem[j + 1] = L->elem[j];
    }
    L->elem[i - 1] = e;
    ++L->length;
    return OK;
}

/**
 * 删除操作
 * 1，判断删除位置i的合理性
 * 2，将i-1位置往后的元素前移一个位置
 * 3，有效长度减一
 */
Status deleteList(SqList *L, int i) {
    if (i < 1 || i > L->length) return ERROR;
    for (int j = i - 1; j < L->length; ++j) {
        L->elem[j] = L->elem[j+1];
    }
    --L->length;
    return OK;
}
/**
 * 遍历
 */
void traverseList(SqList L) {
    printf("SqList = [");
    for (int i = 0; i < L.length; ++i) {
        printf("%d", L.elem[i]);
        if (i != L.length - 1)printf(", ");
    }
    printf("]\n");
}

/**
 * 测试
 */
int main() {
    SqList L;
    initList(&L);
    insertList(&L, 1, 54);
    insertList(&L, 1, 78);
    insertList(&L, 1, 20);
    insertList(&L, 2, 19);
    traverseList(L);
    deleteList(&L,1);
    traverseList(L);
    return 0;
}
