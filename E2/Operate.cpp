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
SElemType2 Operate(SElemType2 a, SElemType x, SElemType2 b){//进行运算的函数 
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
SElemType2 calculate(){
	LinkStack optr;//运算符栈 
	LinkStack2 opnd;//运算数栈 
	
	InitStack(optr);
	InitStack2(opnd);
	
	Push(optr,'#');
	char c,prec;
	char x;
	char theta;
	SElemType2 a,b,number;
	int n,negative=0;
	char op[]={'+','-','*','/','(',')','#'};
	prec='0';
	c=getchar(); 
	if(c=='-')
		Push2(opnd,0);
	while(c!='#'||GetTop(optr)!='#'){
		if(!In(c,op)){
			number=0;
			while(!In(c,op)){
				if(c=='.')
					break;
				number=number*10+(c-48);
				prec=c;
				c=getchar();
			}
			if(c=='.'){
				n=1;
				prec=c;
				while(!In(c=getchar(),op)){
					number=number+(c-48)*(double)pow(0.1,n);
					n++;
					prec=c;
				}
			}
			if(negative){
				number*=(-1);
			}
			if(!In(prec,op)&&In(c,op))
				Push2(opnd,number);
			negative=0;			
		} else {
			if(c=='-'&&prec=='('){
				c=getchar();
				negative=1;
				continue;
			}			
			switch(Precede(GetTop(optr),c)){
				case '<':
					Push(optr,c);
					prec=c;
					c=getchar();
					break;
				case '=':
					Pop(optr,x);
					prec=c;
					c=getchar();
					break;
				case '>':
					Pop(optr,theta);
					Pop2(opnd,b);
					Pop2(opnd,a);
					Push2(opnd,Operate(a,theta,b));
					break;
			}
			
		}
	}
	return GetTop2(opnd);
	
}

