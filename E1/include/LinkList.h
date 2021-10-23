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

/*函数声明*/
Status InitLinkList(LinkList &L);  //初始化

Status PrintAll_LinkList(LinkList &L);//输出所有信息 

Status AddBook_LinkList(LinkList &L);//添加图书 

Status LinkSort(LinkList &L);//链表排序
 
Status InsertBook_LinkList(LinkList &L,int pos);//指定位置插入 

Status DeleteBookByPos_LinkList(LinkList &L,int pos);//删除指定位置图书信息

void LinkListMain();
