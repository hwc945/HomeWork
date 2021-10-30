#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define INITSIZE 100   //�洢�ռ��ʼ������
#define INCREMENT 10 //�洢�ռ��������

#define ERROR 0;
#define OVERFLOW -2;
#define OK 1;
typedef char SElemType ;
typedef int status ;

//��ջ���Ͷ���
 typedef struct Stacknode
 {  	
      SElemType  data;	
      struct Stacknode  *next; 
 }StackNode, *LinkStack;  
 
 
 typedef struct Stacknode2
 {  	
      int  data;	
      struct Stacknode2  *next; 
 }StackNode2, *LinkStack2;  

//��ʼ��ջInitStack( &s )
void InitStack( LinkStack &s );
void InitStack2( LinkStack2 &s );

//����ջDestroyStack( &s )
void DestroyStack( LinkStack &s );

//�ж�ջ�Ƿ�Ϊ��StackEmpty(s)
status StackEmpty( LinkStack s );

//��ջ Push( &s, e )	
void Push( LinkStack &s, SElemType e);
void Push2( LinkStack2 &s, int e);

//��ջ Pop( &s, &e )
status Pop( LinkStack &s, SElemType &e );
status Pop2( LinkStack2 &s, int &e );

//ȡջ��Ԫ��GetTop(s) 
char GetTop(LinkStack s);
int GetTop(LinkStack2 s);



