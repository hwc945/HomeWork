#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"LinkStack.h"
typedef char SElemType;
typedef double SElemType2;

bool In(char c,char op[]);

SElemType Precede(SElemType a, SElemType b);

SElemType2 Operate(SElemType2 a, SElemType x, SElemType2 b);

SElemType2 calculate();
