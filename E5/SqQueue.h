#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define INITSIZE 100   //存储空间初始分配量
#define INCREMENT 10 //存储空间分配增量

#define ERROR 0
#define OVERFLOW -2
#define OK 1
#define MAXSIZE 100 //队列可能达到的最大长度 
typedef int VertexType;
typedef int QElemType ;
typedef int Status ;

typedef struct 
{	  
	QElemType  *base;
	int   front,   rear;  //队头和队尾“指针”
} SqQueue;

//初始化队列InitQueue( &Q)
Status InitQueue(SqQueue &Q);

//求队列长度QueueLength(Q)
int QueueLength(SqQueue Q);
//入队列EnQueue(&Q, e) 
int EnQueue(SqQueue &Q, QElemType e);

//出队列DeQueue(&Q, &e)
int DeQueue(SqQueue &Q,VertexType& e);

//队列是否为空
bool empty (SqQueue &Q);

