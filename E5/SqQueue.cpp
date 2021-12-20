#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "SqQueue.h"

//初始化队列InitQueue( &Q)
Status InitQueue(SqQueue &Q)
{
    Q.base=(QElemType *)malloc(MAXSIZE*sizeof(QElemType));
     if (!Q.base)   
	 	exit(OVERFLOW);
     Q.front=Q.rear=0;   //初始时均为0
     return OK;
}
//入队列EnQueue(&Q, e) 
int EnQueue(SqQueue &Q, QElemType e)
{
	if ((Q.rear+1)%MAXSIZE==Q.front) 
		return ERROR;   //队满
	Q.base[Q.rear]=e;
	Q.rear=(Q.rear+1)%MAXSIZE; //队尾位置发生变化
	return OK;
}

//出队列DeQueue(&Q, &e)
int DeQueue(SqQueue &Q,VertexType& e)
{
	if ( Q.front==Q.rear ) 
		return ERROR; //队空
	e=Q.base[Q.front];
	Q.front=(Q.front+1)%MAXSIZE; //队头位置发生变化
	return OK;
}

//队列是否为空
bool empty (SqQueue &Q) {
	return (Q.front==Q.rear);
}

