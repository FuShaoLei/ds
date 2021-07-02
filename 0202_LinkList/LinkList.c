#include "LinkList.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * 初始化单链表
 */
Status InitList(LinkList *L) {
    // 使指针指向一块大小为LNode的结点
    (*L) = (LinkList) malloc(sizeof(LNode));
    if ((*L) == NULL) {
        return ERROR;
    }
    // 将指针域置为空，表示空表
    (*L)->next = NULL;
    return OK;
}

/**
 * 单链表的取值
 * 和顺序表不同的是，在单链表中我们无从得知表的长度
 * 而且单链表是一种顺序存取的结构
 */
Status GetElem(LinkList L, int i, ElemType *e) {
    // 简单判断合理性
    if (L == NULL || i < 0) return ERROR;
    LNode *p = L->next;
    int j = 0;
    // 此循环会在 j == i 的时候停下(时候的p指针指向的就是i位置的LNode)或者当 p 为 null 的时候停下
    while (p && j < i) {
        p = p->next;
        ++j;
    }
    // TODO 这里为何是 j>i ?
    if (!p || j > i) return ERROR;
    e = &p->data;
    printf("======>%s", e);
    return OK;
}

/**
 * 单链表的查找
 */
LNode *LocateElem(LinkList L, ElemType e) {
    LNode *p = L->next;
    while (p && p->data != e) p = p->next;
    return p;
}

Status ListInsert(LinkList *L, int i, ElemType e) {
    if (!*L || i < 0) return ERROR;
    LNode *p = (*L)->next;
    int j = 0;
    while (p && (j < i - 1)) {
        p = p->next;
        ++j;
    }
    if (!p || j > i - 1) return ERROR;
    LNode *s = (LNode *) malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return OK;
}

void TraverList(LinkList L) {
    if (!L) return;
    if (!L->next) {
        printf("======> L->next = NULL");
        return;
    }
    LNode *p = L->next;
    while (p) {
        printf("======>%c\n", p->data);
        p = p->next;
    }
}

/**
 * 前插法创建单链表
 */
void CreateList_H(LinkList *L, int n) {
    if (!*L) return;
    for (int i = 0; i < n; ++i) {
        LNode *p = (LNode *) malloc(sizeof(LNode));
        if (i % 2 == 0) {
            p->data = 'a';
        } else{
            p->data = 'c';
        }
        p->next = (*L)->next;
        (*L)->next = p;
    }
    printf("=====> CreateList_H Over\n");
}
