#include "SqQueue.h"
#include <stdlib.h>

/**
 * 队列
 */
Status InitQueue(SqQueue *Q) {
    Q->base = malloc(MAXSIZE * sizeof(SqQueue));
    if (!Q->base)exit(OVERFLOW);
    Q->front = Q->rear = 0; // 表示队空
    return OK;
}

/**
 * 求队列长度
 */
int QueueLength(SqQueue Q) {
    return (Q.rear - Q.front + MAXSIZE) % MAXSIZE;
}

/**
 * 入队，由队尾入队
 */
Status EnQueue(SqQueue *Q, char e) {
    // 判满
    if ((Q->rear + 1) % MAXSIZE == Q->front) return ERROR;
    Q->base[Q->rear] = e;
    Q->rear = (Q->rear + 1) % MAXSIZE;
    return OK;
}

/**
 * 出队，由队头出队
 */
Status DeQueue(SqQueue *Q, char *e) {
    // 判空
    if (Q->rear == Q->front) return ERROR;
    e = Q->base[Q->front];
    Q->front = (Q->front + 1) % MAXSIZE;
    return OK;
}

ElemType GetHead(SqQueue Q) {
    if (Q.rear != Q.front) {
        return Q.base[Q.front];
    }
    return NULL;
}
