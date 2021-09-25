#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int QElemType;
typedef int Status;

typedef struct QNode {
    QElemType data;
    struct QNode *next;
} QNode, *QueuePtr;

typedef struct {
    QueuePtr front; // 队头
    QueuePtr rear; // 队尾
} LinkQueue;

Status initQueue(LinkQueue *Q) {
    Q->front = Q->rear = (QueuePtr) malloc(sizeof(QNode));
    if (Q->front == NULL)exit(OVERFLOW);
    Q->front->next = NULL;
    return OK;
}

int main() {
    printf("Hello, World!\n");
    return 0;
}
