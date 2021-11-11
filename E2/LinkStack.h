#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#define INITSIZE 100   //存储空间初始分配量
#define INCREMENT 10 //存储空间分配增量

#define ERROR 0;
#define OK 1;
typedef char SElemType ;
typedef double SElemType2 ;
typedef int status ;

//链栈类型定义
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

//初始化栈InitStack( &s )
void InitStack( LinkStack &s );
void InitStack2( LinkStack2 &s );

//销毁栈DestroyStack( &s )
void DestroyStack( LinkStack &s );

//判断栈是否为空StackEmpty(s)
status StackEmpty( LinkStack s );

//进栈 Push( &s, e )	
void Push( LinkStack &s, SElemType e);
void Push2( LinkStack2 &s, SElemType2 e);

//出栈 Pop( &s, &e )
SElemType Pop( LinkStack &s, SElemType &e );
SElemType2 Pop2( LinkStack2 &s, SElemType2 &e );

//取栈顶元素GetTop(s) 
SElemType GetTop(LinkStack s);
SElemType2 GetTop2(LinkStack2 s);



