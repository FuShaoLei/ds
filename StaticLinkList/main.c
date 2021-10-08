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
    int cur; // 游标，用来替代next的
} Component, StaticLinkList[MAXSIZE];



/**
 * 初始化
 * 静态链表的第一个元素的cur存放备用链表的第一个结点的下标
 * 最后一个元素的下标的cur存放有效元素的第一个结点的下标
 */
Status initList(StaticLinkList space) {
    for (int j = 0; j < MAXSIZE - 1; ++j) {
        space[j].cur = j + 1;
    }
    space[MAXSIZE - 1].cur = 0; // 此时静态链表为空，将最后一个结点的cur置为0
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

// 回收结点，将这个结点插入到备用链表的第一个位置
void Free_SSL(StaticLinkList space, int j) {
    space[j].cur = space[0].cur;
    space[0].cur = j;
}
/**
 * 插入操作
 * 算法思路
 * 1，获取备用结点的下标
 * 2，将下标对应的元素赋值
 */
Status insertList(StaticLinkList L, int i, ElemType e) {
    int j = Malloc_SLL(L); // 获取备用结点的下标
    L[j].data = e; // 给数据域赋值
    int k = MAXSIZE - 1;
    for (int l = 1; l <= i - 1; ++l) {
        k = L[k].cur;
    }
    L[j].cur = L[k].cur;
    L[k].cur = j;
    return OK;
}

Status deleteList(StaticLinkList L, int i, ElemType *e) {
    int k = MAXSIZE - 1;
    // 找到第i-1位置元素
    for (int l = 1; l <= i - 1; ++l) {
        k = L[k].cur;
    }
    int j =  L[k].cur;
    L[k].cur = L[j].cur; // 下标等于下一个
    Free_SSL(L,j);
    return OK;
}


void traverList(StaticLinkList L) {
    int k = L[MAXSIZE - 1].cur;
    while (k != 0) {
        printf("%d\n", L[k].data);
        k = L[k].cur;
    }
}

int getLength(StaticLinkList L) {
    int k = L[MAXSIZE - 1].cur;
    int length = 0;
    while (k != 0) {
        length++;
        k = L[k].cur;
    }
    return length;
}

int main() {
    // 初始化
    StaticLinkList L;
    initList(L);
    // 插入数据
    insertList(L, 1, 55);
    insertList(L, 1, 89);
    // 遍历
    traverList(L);
    return 0;
}
