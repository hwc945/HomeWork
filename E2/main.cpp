#include"LinkStack.h"
#include "Operate.h"
int main(){
	
	LinkStack optr;//‘ÀÀ„∑˚’ª 
	LinkStack2 opnd;//‘ÀÀ„ ˝’ª 
	
	InitStack(optr);
	InitStack2(opnd);
	
	Push(optr,'#');
	char c,prec;
	char x;
	int temp=0;
	char theta;
	int a,b;
	char op[]={'+','-','*','/','(',')','#'};
	prec='0';
	c=getchar(); 
	while(c!='#'||GetTop(optr)!='#'){
		if(!In(c,op)){
			if(!In(prec,op)){
				temp*=10; 
				temp+=((int)c-48);
				prec=c;
				c=getchar();
			}
			else{
				temp=(int)c-48;
				prec=c;
				c=getchar();
			}
			
		} else {
			switch(Precede(GetTop(optr),c)){
				case '<':
					Push(optr,c);
					if(temp!=-1&&c!='(')
						Push2(opnd,temp);
					temp=0;
					prec=c;
					c=getchar();
					break;
				case '=':
					Pop(optr,x);
					prec=c;
					c=getchar();
					break;
				case '>':
					if(temp!=-1)
						Push2(opnd,temp);
					temp=-1;
					
					Pop(optr,theta);
					Pop2(opnd,b);
					Pop2(opnd,a);
					Push2(opnd,Operate(a,theta,b));
					break;
			}
			
		}
	}
	printf("%d",GetTop(opnd));
	
	return 0;
}

//1+2*((1+2)*3)#
