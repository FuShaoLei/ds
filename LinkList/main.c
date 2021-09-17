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

// 头插法创建链表（为了方便测试，选择接受一个数组后写入）
void createList_h(LinkList *head, int n, int arr[]) {
    // 创建链表
    (*head) = (LinkList) malloc(sizeof(LNode));
    (*head)->next = NULL;
    // 循环写入
    LNode *p;
    for (int i = n - 1; i >= 0; --i) {
        p = (LNode *) malloc(sizeof(LNode));
        p->data = arr[i];

        p->next = (*head)->next;
        (*head)->next = p;
    }
}

// 遍历输出
void traverList(LinkList L) {
    LNode *p = L->next;
    printf("\nLinkList = [");
    while (p) {
        printf("%d", p->data);
        p = p->next;
        if (p) printf(", ");
    }
    printf("]\n");
}

/**
 * 插入算法
 * 1，找到位置为i-1的元素
 * 2，生成新结点
 * 3，新节点的指针域指向位置为i的元素，位置为i-1的元素的指针域指向新结点
 */
Status insertList(LinkList *head, int i, ElemType e) {
    LNode *p = *head;
    int k = 0;
    while (p && k < i - 1) {
        p = p->next;
        ++k;
    }
    if (p == NULL || k > i - 1) return ERROR; // 很明显，这里k是不可能大于i-1的，这里体现了代码的健壮性

    LNode *s = (LNode *) malloc(sizeof(LNode));
    s->data = e;

    s->next = p->next;
    p->next = s;
    return OK;
}

/**
 * 删除算法
 * 1，找到位置为i-1的元素
 * 2，令位置为i-1的元素指向位置为i+1的元素
 * 3，释放位置为i的空间
 */
Status deleteList(LinkList *head, int i) {
    LNode *p = *head;
    int k = 0;
    while (p->next && k < i - 1) {
        p = p->next;
        ++k;
    }
    if (p->next == NULL || k > i - 1) return ERROR;
    LNode *q = p->next; // 位置是i
    p->next = p->next->next;
    free(q);
    return OK;
}

int main() {
    LinkList head;
    int a[] = {1, 2, 3};
    createList_h(&head, 3, a);
    traverList(head);
    insertList(&head, 2, 8);
    traverList(head);
    deleteList(&head, 3);
    traverList(head);


    return 0;
}
