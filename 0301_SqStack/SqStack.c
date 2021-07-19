#include "SqStack.h"
#include <stdlib.h>

/**
 * 初始化
 */
Status InitStack(SqStack *S) {
    // 分配空间，并让栈底指针指向这块空间
    (*S).base = (SElemType *) malloc(sizeof(SElemType) * MAXSIZE);
    if ((*S).base == NULL) return ERROR;
    // 栈顶指针指向栈顶，表示空栈
    (*S).top = (*S).base;
    (*S).stacksize = MAXSIZE;
    return OK;
}

/**
 * 入栈
 */
Status Push(SqStack *S, SElemType e) {
    // 简单的判断合法性
    if ((*S).base == NULL) return ERROR;
    // 判满
    if ((*S).top - (*S).base == (*S).stacksize) return ERROR;
    // 将原来top指针所指的空间赋为e，然后top指针的位置加1
    *(S->top++) = e; // 这鸡巴c语言是真滴看不懂啊
    return OK;
}

/**
 * 出栈操作
 */
Status Pop(SqStack *S, SElemType *e) {
    if ((*S).base == NULL) return ERROR;
    if ((*S).top == (*S).base) return ERROR;
    *e = (--(*S).top);
    return OK;
}

SElemType GetTop(SqStack S) {
    if (S.base == NULL || S.top == S.base) return ERROR;
    return *(S.top - 1);
}
