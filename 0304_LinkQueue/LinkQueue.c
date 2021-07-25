#include "LinkQueue.h"
#include <stdlib.h>

Status InitQueue(LinkQueue *Q) {
    Q->front = Q->rear = malloc(sizeof(QNode));
    Q->front->next = NULL;
    return OK;
}

/**
 * 链队的入队
 */
Status EnQueue(LinkQueue *Q, char e) {
    QNode *p = malloc(sizeof(QNode));
    p->data = e;
    p->next = NULL;
    Q->rear->next = p; // 将p插入到队尾
    Q->rear = p; // 尾指针指向p
    return OK;
}

/**
 * 链队的出队
 */
Status DeQueue(LinkQueue *Q, char *e) {
    // 判空
    if (Q->rear == Q->front) return ERROR;
    QNode *p = Q->front->next;
    e = p->data;
    Q->front->next = p->next; // 头指针指向下一个结点
    if (Q->rear == p)Q->rear = Q->front;
    free(p);
    return OK;
}
