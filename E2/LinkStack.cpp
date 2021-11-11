#include"LinkStack.h"

//��ʼ��ջInitStack( &s )
void InitStack( LinkStack &s )
{
	s=NULL;
}

void InitStack2( LinkStack2 &s )
{
	s=NULL;
}

//����ջDestroyStack( &s )
void DestroyStack( LinkStack &s )
{	
	LinkStack p;
	while (s!=NULL)
	{	
		p=s->next;
		free( s );  
		s=p;
	}
}

//�ж�ջ�Ƿ�Ϊ��StackEmpty(s)
status StackEmpty( LinkStack s )
{
	return( s==NULL );
}

//��ջ Push( &s, e )	
void Push( LinkStack &s, SElemType e)
{
	LinkStack p;
	p=(LinkStack)malloc(sizeof(StackNode));
	p->data=e;
	p->next=s; 
	s=p;
}

void Push2( LinkStack2 &s, SElemType2 e)
{
	LinkStack2 p;
	p=(LinkStack2)malloc(sizeof(StackNode2));
	p->data=e;
	p->next=s; 
	s=p;
}

//��ջ Pop( &s, &e )
SElemType Pop( LinkStack &s, SElemType &e )
{	
	LinkStack p;
	if (s==NULL)   
		return ERROR; 
	e=s->data;
	p=s;
	s=s->next;
	free(p);
	return OK;
}

SElemType2 Pop2( LinkStack2 &s, SElemType2 &e )
{	
	LinkStack2 p;
	if (s==NULL)   
		return ERROR; 
	e=s->data;
	p=s;
	s=s->next;
	free(p);
	return OK;
}

//ȡջ��Ԫ��GetTop(s) 
SElemType GetTop(LinkStack s)
{
	if (s==NULL) 
		return ERROR; 
	return s->data; 
} 

SElemType2 GetTop2(LinkStack2 s)
{
	if (s==NULL) 
		return ERROR; 
	return s->data; 
} 


