#include <stdio.h>
#include <malloc.h>		
#include <assert.h>
#include<stdlib.h>

#define LIST_INIT_SIZE 100                
#define LISTINCREMENT 10                   
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2


typedef int Status;

typedef struct
{
	char no[20];
	char name[50];
	float price;
} Book1;

typedef struct 
{
	Book1 *elem;
	int length;
}SqList;

//��������

Status InitList_Sq(SqList &L);  //��ʼ��

Status PrintAll_Sq(SqList &L);//���������Ϣ 

Status AddBook(SqList &L);//���ͼ�� 

Status TopBookPrice(SqList &L);//����߼۸� 


Status InsertBook(SqList &L,int pos);//ָ��λ�ò��� 

Status DeleteBookByPos(SqList &L,int pos);//ɾ��ָ��λ��ͼ����Ϣ

void SqListMain();

