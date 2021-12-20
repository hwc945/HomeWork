#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define INITSIZE 100   //�洢�ռ��ʼ������
#define INCREMENT 10 //�洢�ռ��������

#define ERROR 0
#define OVERFLOW -2
#define OK 1
#define MAXSIZE 100 //���п��ܴﵽ����󳤶� 
typedef int VertexType;
typedef int QElemType ;
typedef int Status ;

typedef struct 
{	  
	QElemType  *base;
	int   front,   rear;  //��ͷ�Ͷ�β��ָ�롱
} SqQueue;

//��ʼ������InitQueue( &Q)
Status InitQueue(SqQueue &Q);

//����г���QueueLength(Q)
int QueueLength(SqQueue Q);
//�����EnQueue(&Q, e) 
int EnQueue(SqQueue &Q, QElemType e);

//������DeQueue(&Q, &e)
int DeQueue(SqQueue &Q,VertexType& e);

//�����Ƿ�Ϊ��
bool empty (SqQueue &Q);

