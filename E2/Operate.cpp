#include "Operate.h"


bool In(char c,char op[]){
	
	int i;
	int length=strlen(op);
	for(i=0;i<length;i++){
		if(c==op[i])
			return 1;
	}
	return 0;
}

SElemType Precede(SElemType a, SElemType b){//判断运算符栈的 栈顶元素a和读入元素b的优先级 
    if(a=='+'||a=='-'){
        if(b=='+'||b=='-'||b=='>'||b=='#'||b==')'||b==']')
            return '>';
        else return '<';
    }
    if(a=='*'||a=='/'){
        if(b=='('||b=='[')
            return '<';
        else return '>';
    }
    if(a=='('){
        if(b==')')
            return '=';
        else return '<';
    }
    if(a=='['){
        if(b==']')
            return '=';
        else return '<';
    }
    if(a=='#'){
        if(b=='#')
            return '=';
        else return '<';
    }
}
int Operate(int a, SElemType x, int b){//进行运算的函数 
     switch (x){
     case '+':
         return a+b;
     case '-':
         return a-b;
     case '*':
         return a*b;
     case '/':
         return a/b;
     }
}

