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
    Q->front->next = NULL; // 此处也可以写成 Q->rear->next = null
    return OK;
}

/**
 * 队尾入队
 * 算法：
 * 1，声明结点p并分配空间
 * 2，rear-next = p
 * 3，rear = p
 */
Status enQueue(LinkQueue *Q, QElemType e) {
    QNode *p = (QNode *) malloc(sizeof(QNode));
    if (p == NULL) exit(OVERFLOW);
    p->data = e;
    p->next = Q->rear->next; // p->next = NULL;
    Q->rear->next = p;
    Q->rear = p;
    return OK;
}

/**
 * 队头出队
 */
Status deQueue(LinkQueue *Q, QElemType *e) {
    if (Q->rear == Q->front) return ERROR;
    QNode *p = Q->front->next; // 队头
    *e = p->data;
    Q->front->next = p->next;
    if (Q->rear == p) Q->rear = Q->front; // 特殊情况
    free(p);
    return OK;
}

void traverQueue(LinkQueue Q) {
    QNode *p = Q.front->next;
    printf("LinkQueue = [");
    while (p != NULL) {
        printf("%d", p->data);
        p = p->next;
        if (p != NULL)printf(", ");
    }
    printf("]\n");
}


int main() {
    LinkQueue Q;
    initQueue(&Q);
    enQueue(&Q, 77);
    enQueue(&Q, 8);
    enQueue(&Q, 12);
    enQueue(&Q, 35);
    traverQueue(Q);
    QElemType elem;
    deQueue(&Q, &elem);
    traverQueue(Q);
    return 0;
}
