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
} Book2;

typedef struct LNode
{
	Book2 data;
	struct LNode *next;
}LNode,*LinkList;

/*��������*/
Status InitLinkList(LinkList &L);  //��ʼ��

Status PrintAll_LinkList(LinkList &L);//���������Ϣ 

Status AddBook_LinkList(LinkList &L);//���ͼ�� 

Status LinkSort(LinkList &L);//��������
 
Status InsertBook_LinkList(LinkList &L,int pos);//ָ��λ�ò��� 

Status DeleteBookByPos_LinkList(LinkList &L,int pos);//ɾ��ָ��λ��ͼ����Ϣ

void LinkListMain();
