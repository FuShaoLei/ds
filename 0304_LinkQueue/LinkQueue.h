#ifndef LINKQUEUE_H
#define LINKQUEUE_H

#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define Status int
#define ElemType char
#define MAXSIZE 10

typedef struct QNode {
    ElemType data;
    struct QNode *next;
} QNode, *QueuePtr;

typedef struct {
    QueuePtr front;
    QueuePtr rear;
} LinkQueue;

Status InitQueue(LinkQueue *Q);

Status EnQueue(LinkQueue *Q, ElemType e);

Status DeQueue(LinkQueue *Q, ElemType *e);

ElemType GetHead(LinkQueue Q) {
    if (Q.front != Q.rear) return Q.front->next->data;
}

#endif
