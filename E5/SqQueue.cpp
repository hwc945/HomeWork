#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "SqQueue.h"

//��ʼ������InitQueue( &Q)
Status InitQueue(SqQueue &Q)
{
    Q.base=(QElemType *)malloc(MAXSIZE*sizeof(QElemType));
     if (!Q.base)   
	 	exit(OVERFLOW);
     Q.front=Q.rear=0;   //��ʼʱ��Ϊ0
     return OK;
}
//�����EnQueue(&Q, e) 
int EnQueue(SqQueue &Q, QElemType e)
{
	if ((Q.rear+1)%MAXSIZE==Q.front) 
		return ERROR;   //����
	Q.base[Q.rear]=e;
	Q.rear=(Q.rear+1)%MAXSIZE; //��βλ�÷����仯
	return OK;
}

//������DeQueue(&Q, &e)
int DeQueue(SqQueue &Q,VertexType& e)
{
	if ( Q.front==Q.rear ) 
		return ERROR; //�ӿ�
	e=Q.base[Q.front];
	Q.front=(Q.front+1)%MAXSIZE; //��ͷλ�÷����仯
	return OK;
}

//�����Ƿ�Ϊ��
bool empty (SqQueue &Q) {
	return (Q.front==Q.rear);
}

