#include"SqString.h"


void insertSqString(SqString &S){
	scanf("%s",S.data);
	S.length=strlen(S.data);
}


void GetNext(SqString t,int next[]){
	int j,k;
	j=0;
	k=-1;
	next[0]=-1;
	while(j<t.length){
		if(k==-1||t.data[j]==t.data[k]){
			j++;
			k++;
			if (t.data[j] != t.data[k]){
				next[j] = k;
			}
			else{
				next[j] = next[k];
			}
		}
		else 
			k=next[k];
	}
}

int KMPIndex(SqString s,SqString t){
	int next[MaxSize];
	int i,j,n;
	char tt;
	n=t.length+1;
	while(n--){
		i=0;
		j=0;
		for (int m=0;m<t.length; m++){
			GetNext(t,next);
			while(i<s.length&&j<t.length){
				if(j==-1||s.data[i]==t.data[j]){
					i++;
					j++;
				}
				else 
					j=next[j];
			}
		}
		
		if(j==t.length)
			return (i-t.length+1);
		else {
			tt=t.data[0];
			for (int k=0;k<t.length-1;k++)
			{
				t.data[k] =t.data[k+1];
			}
			t.data[t.length-1]=tt;
		}
	}	
	return (-1);
}


void operate(){
	SqString s,t;
	int result;	
	while (1)
	{
		printf("请输入A和B的DNA序列，中间以空格分开："); 
		insertSqString(t);
		insertSqString(s);
		if (!strcmp(s.data,"0") && !strcmp(t.data, "0"))//停止输入
			break;
		else{
			result=KMPIndex(s,t);
			printf("患者是否感染病毒："); 
			if(result>0)
				printf("YES\n");
			if(result==-1)
				printf("NO\n");
		}			
	}	
}

