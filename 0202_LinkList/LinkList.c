#include "LinkList.h"
#include <stdlib.h>

/**
 * 初始化单链表
 */
Status InitList(LinkList *L) {
    // 使指针指向一块大小为LNode的结点
    (*L) = (LinkList) malloc(sizeof(LNode));
    if ((*L) == NULL) {
        return ERROR;
    }
    (*L)->next = NULL;
    return OK;
}
