
#include <stdio.h>
#include <stdlib.h>

#ifndef LINKSTACK_H
#define LINKSTACK_H

#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define MAXSIZE 100
typedef int Status;

typedef int SElemType;

typedef struct StackNode {
    SElemType data;
    struct StackNode *next;
} StackNode, *LinkStack;

Status InitStack(LinkStack *S);

Status Push(LinkStack *S, SElemType e);

Status Pop(LinkStack *S, SElemType *e);

SElemType GetTop(LinkStack S);

#endif
