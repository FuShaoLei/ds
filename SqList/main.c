#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define LIST_INIT_SIZ 100 // 初始分配量
#define LIST_INCREMENT 10
typedef int ElemType;
typedef int Status;
typedef struct {
    ElemType *elem;
    int length;
    int listSize;
}SqList;

Status initList(SqList *L){
    L->elem = mall
}

int main() {
    printf("Hello, World!\n");
    return 0;
}
