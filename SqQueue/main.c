#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define MAX_SIZE 100
typedef int QElemType;
typedef int Status;

/**
 * 循环队列
 * 为了判端队列是否为满，少用一个元素，判断(Q->rear + 1) % MAX_SIZE == Q->front，为true则是队满
 */
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

/**
 * 队尾入队
 */
Status enQueue(SqQueue *Q, QElemType e) {
    // 判满
    if ((Q->rear + 1) % MAX_SIZE == Q->front) {
        return ERROR;
    }
    Q->base[Q->rear] = e;
    Q->rear = (Q->rear + 1) % MAX_SIZE; // 循环意义上的加一
    return OK;
}

/**
 * 队头出队
 */
Status deQueue(SqQueue *Q, QElemType *e) {
    // 判空
    if (Q->front == Q->rear) {
        return ERROR;
    }
    *e = Q->base[Q->front];
    Q->front = (Q->front + 1) % MAX_SIZE; // 循环意义的加1,注意，这里也是加1
    return OK;
}

/**
 * 获取队列长度
 */
int getQueueLength(SqQueue Q) {
    return (Q.rear - Q.front + MAX_SIZE) % MAX_SIZE;
}

void traverQueue(SqQueue Q) {
    printf("LinkQueue = [");
    for (int i = Q.front; i < Q.rear; ++i) {
        printf("%d", Q.base[i]);
        if (i + 1 < Q.rear) printf(", ");
    }
    printf("]\n");
}

int main() {
    SqQueue Q;
    initQueue(&Q);
    enQueue(&Q, 54);
    enQueue(&Q, 80);
    enQueue(&Q, 31);
    enQueue(&Q, 26);
    traverQueue(Q);
    int result;
    deQueue(&Q, &result);
    printf("result = %d\n", result);
    traverQueue(Q);
    return 0;
}
