#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int ElemType;
typedef int Status;


typedef struct LNode {
    ElemType data; // 数据域
    struct LNode *next; // 指针域
} LNode;

// 指向单链表的指针，由此唯一确定一个单链表
typedef LNode *LinkList;

Status initList(LinkList *head) {
    (*head) = (LinkList) malloc(sizeof(LNode)); // 头指针指向头节点
    (*head)->next = NULL;
    return OK;
}

// 头插法创建链表
void createList_h(LinkList *head, int n) {
    // 创建链表
    (*head) = (LinkList) malloc(sizeof(LNode));
    (*head)->next = NULL;

    // 循环写入
    printf("please enter n element: \n");
    LNode *p;
    for (int i = 0; i < n; ++i) {
        p = (LNode *) malloc(sizeof(LNode));
        scanf("%d", &(p->data));
        printf("you enter %d\n", p->data);

        p->next = (*head)->next;
        (*head)->next = p;
    }
}

void traverList(LinkList L) {
    LNode *p = L->next;
    int i = 1;
    while (p) {
        printf("the %d element is %d\n", i, p->data);
        p = p->next;
        ++i;
    }
}


int main() {
    LinkList head;
    createList_h(&head,3);
    traverList(head);
    return 0;
}
