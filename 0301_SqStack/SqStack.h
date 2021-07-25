#ifndef SQSTACK_H
#define SQSTACK_H

#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define MAXSIZE 100
typedef int Status;

typedef char SElemType;

/**
 * 顺序栈的存储结构
 */
typedef struct {
    SElemType *base;// 栈底指针，初始化之后将始终指向栈底
    SElemType *top;// 栈顶指针，栈为空时，base = top，当栈非空时，栈顶指针指向栈顶元素的上一个位置
    int stacksize; // 栈可用最大容量
} SqStack;

Status InitStack(SqStack *S);

Status Push(SqStack *S, SElemType e);

Status Pop(SqStack *S, SElemType *e);

SElemType GetTop(SqStack S);

#endif
