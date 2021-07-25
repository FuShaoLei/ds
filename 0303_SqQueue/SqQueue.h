#ifndef SQQUEUE_H
#define SQQUEUE_H

#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define Status int
#define ElemType char
#define MAXSIZE 10

typedef struct {
    ElemType *base;
    int front; // 队头指针
    int rear; // 队尾指针
} SqQueue;

Status InitQueue(SqQueue *Q);

int QueueLength(SqQueue Q);

Status EnQueue(SqQueue *Q, ElemType e);

Status DeQueue(SqQueue *Q, ElemType *e);

ElemType GetHead(SqQueue Q);


#endif
