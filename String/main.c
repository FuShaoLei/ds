#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define MAXSTRLEN 255
typedef int Status;

typedef unsigned char SString[MAXSTRLEN + 1]; // 多出一个位置用于存放长度

Status initStr(SString T, const char *chars) {
    int len = (int) strlen(chars);
    if (len > MAXSTRLEN) {
        return ERROR;
    }
    T[0] = len; // 定长字符串第一个元素存储长度
    for (int i = 1; i <= len; ++i) {
        T[i] = chars[i - 1];
    }
    return OK;
}


/**
 * 获得kmp算法要使用的next数组
 * 1，固定的，第一位的next值为0，第二位的next值为1
 * 2，之后每第 j 个的next值时，根据第 j-1 进行比较，有如下情况
 * 3，如果 T[j-1] == T[next[j-1]] ,如果这两个值相等，那么next[j] = next[j-1] +1
 * 4，如果不等，则继续沿着next值进行寻找，若找到了相同的，则next[j] = next[x]+1
 * 5，若找不到，则 next[j] = 1
 */
void getNext(SString T, int next[]) {
    next[1] = 0;
    next[2] = 1;
    for (int i = 3; i <= T[0]; ++i) {
        if (T[i - 1] == T[next[i - 1]]) {
            next[i] = next[i - 1] + 1;
        } else {
            next[i] = 1;
        }
    }
}

void get_next(SString T, int next[]) {
    int i = 1;
    int j = 0;
    next[1] = 0;
    printf("-------------------------\n");
    while (i < T[0]) {
        printf("begin i = %d, j = %d\n", i, j);
        if (j == 0 || T[i] == T[j]) {
            ++i;
            ++j;
            next[i] = j;
            printf("next[%d] = %d\n", i, next[i]);
        } else {
            j = next[j];
            printf("j = %d\n",j);
        }
        printf("end i = %d, j = %d\n", i, j);
        printf("-------------------------\n");
    }
}


void traverString(SString S) {
    printf("SString = [ ");
    for (int i = 1; i <= S[0]; i++) {
        printf("%c", S[i]);
    }
    printf(" ]\n");
}


int main() {
    SString S;
    char *chars = "ababcabcacbab";
    initStr(S, chars);
    traverString(S);
    SString T;
    char *tchars = "ababcbb";
    initStr(T, tchars);
    traverString(T);

    // 测试kmp算法
    // 1，测试获取next数组
    int *next = (int *) malloc((T[0] + 1) * sizeof(int));
    get_next(T, next);
    // 打印测试一下
    printf("next = ");
    for (int p = 1; p <= T[0]; p++) {
        printf("%d", next[p]);
    }
    printf("\n");


    return 0;
}
