#ifndef SQLIST_H
#define SQLIST_H

#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define MAX_SIZE 10 // 最大长度
typedef int Status;
typedef int ElemType; // 元素类型


typedef struct {
	ElemType* elem;// 用于存放元素的数组
	int length;// 线性表的长度，当长度为 0 时为称为空表
}SqList;




/*
 * 初始化线性表，并将长度置为零
 */
Status InitList(SqList* L);

/*
 * 从线性表中取数据
 * 前提：
 *	1.存在这个线性表
 *	2.i的取值范围合理，即 1 <= i <= length
 */
Status GetElem(SqList L, int i, ElemType* e);


/*
 * 查找顺序表，并返回其序号
 * 前提：存在线性表L
 */
int LocateElem(SqList L, ElemType e);

/*
 * 线性表的插入，并将length+1
 * 前提：
 *	1.存在线性表L
 *	2.L.length+1<MAX_SIZE
 *	3.0<=i<L.length
 */
Status InsertList(SqList* L,int i,ElemType e);

/*
 * 销毁线性表
 * 前提：存在线性表L
 */
void DestroyList(SqList* L);

/*
 * 清空数据表
 * 前提：存在线性表L
 */
void ClearList(SqList L);

/*
 * 获取线性表长度
 * 前提：存在线性表L
 */
int GetLength(SqList L);

/*
 * 判断线性表是否为空
 * 前提：存在线性表L
 */
int IsEmpty(SqList L);

/*
 * 遍历线性表，并对每个节点进行访问
 */
void TraverseList(SqList L);

/*
 * 日志帮助类
 */
void log(char text[]);
void log_num(int num);

#endif