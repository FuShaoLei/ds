#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define MAX_SIZE 100
typedef int QElemType;
typedef int Status;

typedef struct {
    QElemType *base;
    int front;
    int rear;
} SqQueue;

Status initQueue(SqQueue *Q) {
    Q->base = (QElemType *) malloc(MAX_SIZE * sizeof(QElemType));
    if (Q->base == NULL) exit(OVERFLOW);
    Q->front = Q->rear = 0;
    return OK;
}

int getQueueLength(SqQueue Q) {
    return (Q.rear - Q.front + MAX_SIZE) % MAX_SIZE;
}

/**
 * 队尾入栈
 */
Status enQueue(SqQueue *Q, QElemType e) {
    // 判满
    if ((Q->rear + 1) % MAX_SIZE == Q->front) {
        return ERROR;
    }
    Q->base[Q->rear] = e;
    Q->rear = (Q->rear + 1) % MAX_SIZE;
    return OK;
}

/**
 * 队头出队
 */
Status deQueue(SqQueue *Q, QElemType *e) {
    if (Q->front == Q->rear) {
        return ERROR;
    }
    *e = Q->base[Q->front];
    Q->front = (Q->front + 1) % MAX_SIZE; // 注意，这里也是+1
    return OK;
}


int main() {
    printf("Hello, World!\n");
    return 0;
}
