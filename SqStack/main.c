#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int SElemType;
typedef int Status;

#define STACK_INIT_SIZE 100 // 初始分配量
#define STACK_INCREMENT 10 // 增量

typedef struct {
    SElemType *base; // 栈底指针
    SElemType *top; // 栈顶指针，灵魂所在
    int stackSize; // 分配的空间
} SqStack;

Status initStack(SqStack *S) {
    S->base = (SElemType *) malloc(STACK_INIT_SIZE * sizeof(SqStack));
    if (S->base == NULL) exit(OVERFLOW);
    S->top = S->base;
    S->stackSize = STACK_INIT_SIZE;
    return OK;
}

/**
 * 进栈操作
 * 1，如果栈的长度为stackSize，扩大空间
 */
Status push(SqStack *S, SElemType e) {
    if (S->top - S->base == S->stackSize) {
        SElemType *newBase = realloc(S->base, (STACK_INIT_SIZE + STACK_INCREMENT) * sizeof(SqStack));
        if (newBase == NULL) exit(OVERFLOW);
        S->top = S->base + S->stackSize;
        S->base = newBase;
        S->stackSize += STACK_INCREMENT;
    }
    *(S->top) = e;
    S->top++;
    return OK;
}

/*
 * 出栈操作
 */
Status pop(SqStack *S) {
    if (S->top == S->base) return ERROR;
    --S->top; // 向下移动一个位置
    SElemType elem = *(S->top);
    printf("SqStack pop elem = %d\n", elem);
    return OK;
}


void getTop(SqStack S) {
    if (S.top == S.base) return;
    SElemType top = *(S.top - 1);
    printf("SqStack top = %d\n", top);
}

/*
 * 遍历
 */
void traverseStack(SqStack S) {
    SElemType *p = S.base;
    printf("SqStack = [");
    while (p < S.top) {
        printf("%d", *p);
        ++p;
        if (p != S.top) printf(", ");
    }
    printf("]\n");
}


int main() {
    SqStack S;
    initStack(&S);
    push(&S, 2);
    push(&S, 6);
    traverseStack(S);
    getTop(S);
    pop(&S);
    traverseStack(S);
    return 0;
}
