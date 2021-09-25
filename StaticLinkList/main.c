#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define MAXSIZE 50
typedef int ElemType;
typedef int Status;

typedef struct {
    ElemType data;
    int cur;
} Component, StaticLinkList[MAXSIZE];

/**
 * 初始化
 */
Status initList(StaticLinkList space, int i, ElemType arr) {
    for (int i = 0; i < MAXSIZE - 1; ++i) {
        space[i].cur = i + 1;
    }
    space[MAXSIZE - 1].cur = 0; // 此时静态链表为空
    return OK;
}

int Malloc_SLL(StaticLinkList space) {
    int i = space[0].cur; // 获取备用链表的第一个下标
    if (space[0].cur) {
        int j = space[i].cur;
        space[0].cur = j; // 指向下一个备用链表
    }
    return i;
}

/**
 * 插入操作
 * 算法思路
 * 1，获取备用结点的下标
 * 2，将下标对应的元素赋值
 */
Status insertList(StaticLinkList L, int i, ElemType e) {
    int j = Malloc_SLL(L); // 获取备用结点的下标
    L[j].data = e;

    int k = MAXSIZE - 1;
    for (int l = 1; l < i - 1; ++l) {
        k = L[l].cur;
    }
    L[j].cur = L[k].cur;
    L[k].cur = j;
    return OK;
}

int main() {
    StaticLinkList L;
    ElemType arr[] = {50, 22, 14, 67, 99, 133};
    initList(L, 6, arr);
    return 0;
}
