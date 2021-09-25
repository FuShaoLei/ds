#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int SElemType;
typedef int Status;

typedef struct StackNode {
    SElemType data;
    struct StackNode *next;
} StackNode, *LinkStackPtr;

typedef struct LinkStack {
    LinkStackPtr top;
    int count;
} LinkStack;

Status push(LinkStack *S, SElemType e) {
    StackNode *p = (StackNode *) malloc(sizeof(StackNode));
    p->data = e;
    p->next = S->top;
    S->top = p;
    S->count++;
    return OK;
}

Status pop(LinkStack *S, SElemType *e) {
    StackNode *p;
    *e = S->top->data;
    p = S->top;
    S->top = S->top->next;
    free(p);
    S->count--;
    return OK;
}

int main() {
    printf("Hello, World!\n");
    return 0;
}
