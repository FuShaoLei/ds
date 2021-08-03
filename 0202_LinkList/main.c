#include <stdlib.h>
#include <stdio.h>
#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int Status;
typedef char ElemType;

// 单链表的存储结构
typedef struct LNode {
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;

Status InitList(LinkList *L);
Status GetElem(LinkList L, int i, ElemType *e);
LNode *LocateElem(LinkList L, ElemType e);
Status ListInsert(LinkList *L, int i, ElemType e);
Status ListDelete(LinkList *L, int i);
void CreateList_H(LinkList *L, int n);
void CreateList_R(LinkList *L, int n);
void TraverList(LinkList L);

int main() {
    LinkList L;
    InitList(&L);
    CreateList_R(&L,4);
    ListInsert(&L,1,'z');
    ListDelete(&L,2);
    TraverList(L);
    return 0;
}


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
    if (!L) return NULL;
    LNode *p = L->next;
    while (p && p->data != e) {
        p = p->next;
    }
    return p;
}

/**
 * 单链表的插入
 */
Status ListInsert(LinkList *L, int i, ElemType e) {
    // 简单的合法性判断
    if (!L || i <= 0) return ERROR;
    // 获取首元结点
    LNode *p = (*L)->next;
    int j = 0;
    // 通过循环，获取位置为i-1的结点
    while (p && (j < (i - 1))) {
        p = p->next;
        ++j;
    }
    if (!p || j > i - 1) return ERROR;
    // 开辟一个大小为LNode的空间，用于存放新的结点
    LNode *s = (LNode *) malloc(sizeof(LNode));

    s->data = e;
    s->next = p->next;
    p->next = s;
    return OK;
}

/**
 * 前插法创建单链表
 * 课本上是从控制台输入，我这里省去了这一步，默认 a，b 交替
 */
void CreateList_H(LinkList *L, int n) {
    if (!L) return;
    for (int i = 0; i < n; ++i) {
        LNode *p = (LNode *) malloc(sizeof(LNode));

        if (i % 2 == 0) {
            p->data = 'a';
        } else {
            p->data = 'b';
        }

        p->next = (*L)->next;
        (*L)->next = p;
    }
}

/**
 * 遍历输出
 * 这个方法主要是为了测试
 */
void TraverList(LinkList L) {
    if (!L || !L->next) return;
    LNode *p = L->next;
    while (p) {
        printf("%c\n", p->data);
        p = p->next;
    }
}

/**
 * 单链表的删除
 */
Status ListDelete(LinkList *L, int i) {
    if (!L || i <= 0) return ERROR;
    // 获取首元结点
    LNode *p = (*L)->next;
    int j = 0;
    // 通过循环，获取第i-1位的结点
    while (p && (j < i - 1)) {
        p = p->next;
        ++j;
    }
    if (!(p->next) || (j > i - 1)) return ERROR;
    // 临时存储待释放结点
    LNode *q = p->next;
    // 将第i-1个结点的指针域指向第i+1个结点
    p->next = q->next;
    // 释放第i个结点
    free(q);

    return OK;
}

/**
 * 尾插法创建单链表
 */
void CreateList_R(LinkList *L, int n) {
    if (!L) return;
    LNode *r = *L;
    for (int i = 0; i < n; ++i) {
        LNode *p = (LNode *) malloc(sizeof(LNode));

        if (i % 2 == 0) {
            p->data = 'a';
        } else {
            p->data = 'b';
        }

        p->next = NULL;
        r->next = p;
        r = p;
    }
}