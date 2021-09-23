#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define MAXSIZE 50
typedef int ElemType;
typedef int Status;

typedef struct {
    ElemType data;
    int cur;
} Component, StaticLinkList[MAXSIZE];

Status initList(StaticLinkList space) {
    for (int i = 0; i < MAXSIZE - 1; ++i) {
        space[i].cur = i + 1;
    }
    space[MAXSIZE - 1].cur = 0;
    return OK;
}

int main() {
    printf("Hello, World!\n");
    return 0;
}
