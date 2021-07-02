#ifndef LINKLIST_H
#define LINKLIST_H

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

Status InitList(LinkList* L);


#endif
