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

SElemType Precede(SElemType a, SElemType b){//�ж������ջ�� ջ��Ԫ��a�Ͷ���Ԫ��b�����ȼ� 
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
int Operate(int a, SElemType x, int b){//��������ĺ��� 
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

