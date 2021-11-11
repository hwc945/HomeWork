#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#define INITSIZE 100   //�洢�ռ��ʼ������
#define INCREMENT 10 //�洢�ռ��������

#define ERROR 0;
#define OK 1;
typedef char SElemType ;
typedef double SElemType2 ;
typedef int status ;

//��ջ���Ͷ���
 typedef struct Stacknode
 {  	
      SElemType  data;	
      struct Stacknode  *next; 
 }StackNode, *LinkStack;  
 
 
 typedef struct Stacknode2
 {  	
      SElemType2  data;	
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
void Push2( LinkStack2 &s, SElemType2 e);

//��ջ Pop( &s, &e )
SElemType Pop( LinkStack &s, SElemType &e );
SElemType2 Pop2( LinkStack2 &s, SElemType2 &e );

//ȡջ��Ԫ��GetTop(s) 
SElemType GetTop(LinkStack s);
SElemType2 GetTop2(LinkStack2 s);



