#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#define MaxSize 100   

typedef char ElemType;
             		            
typedef struct{ 
	char data[MaxSize];
	int length;
}SqString;

void insertSqString(SqString &S);

void GetNext(SqString t,int next[]);

int KMPIndex(SqString s,SqString t);

void operate();
