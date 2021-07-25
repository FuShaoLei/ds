#include "LinkStack.h"

/**
 * 初始化链栈
 */
Status InitStack(LinkStack *S) {
    *S = NULL;
    return OK;
}

/**
 * 链栈的入栈操作
 */
Status Push(LinkStack *S, SElemType e) {
    // 开辟一块新的空间
    StackNode *p = (StackNode *) malloc(sizeof(StackNode));
    p->data = e;
    p->next = *S;
    *S = p;
    return OK;
}

/**
 * 链栈的出栈操作
 */
Status Pop(LinkStack *S, SElemType *e) {
    if (S == NULL) return ERROR;
    *e = (*S)->data;
    StackNode *p = *S;
    (*S) = (*S)->next;
    free(p);
    return OK;
}

SElemType GetTop(LinkStack S) {
    if (S != NULL) {
        return S->data;
    }
    return 0;
}



