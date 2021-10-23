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

//函数声明

Status InitList_Sq(SqList &L);  //初始化

Status PrintAll_Sq(SqList &L);//输出所有信息 

Status AddBook(SqList &L);//添加图书 

Status TopBookPrice(SqList &L);//求最高价格 


Status InsertBook(SqList &L,int pos);//指定位置插入 

Status DeleteBookByPos(SqList &L,int pos);//删除指定位置图书信息

void SqListMain();

