#include "Huffman.h"

void  CreateHTree(HuffmanTree &HT, int *w, int n){ 
	//*w中存有所有叶子结点的权值
	if (n<=1)    
		return; 
	int m=2*n-1;
	int i,s1,s2; 
	HuffmanTree p;
	HT=(HuffmanTree)malloc((m+1)*sizeof(HTNode));
	for(p=HT+1,i=1;  i<=n; ++i,++p,++w){
		p->weight=*w;
		p->parent=0;
		p->lchild=0;
		p->rchild=0;
	}  

	for( ;i<=m; ++i,++p){
		p->weight=0;
		p->parent=0;
		p->lchild=0;
		p->rchild=0;
	}
	for( i=n+1; i<=m; ++i){  //进行n-1次合并，建哈夫曼树
	   Select(HT, i-1, s1, s2);  //选取
	   HT[s1].parent=i;
	   HT[s2].parent=i;
	   HT[i].lchild=s1;       
	   HT[i].rchild=s2;
	   HT[i].weight =HT[s1].weight+ HT[s2].weight;
	}
}

void Select(HuffmanTree &HT, int i,int &s1,int &s2){
	int j;
	int min=-1,mmin=-1;
	HuffmanTree p;
	for(p=HT+1,j=1;j<=i;j++,p++){
		if(p->parent==0){ //找父母为0的 
			if(min==-1){
				min=p->weight;
				s1=j;
			}
			if(min>p->weight){
				mmin=min;
				min=p->weight;
				s2=s1;
				s1=j;
			} else if(min==p->weight){
				mmin=p->weight;
				s2=j;
			}else if(mmin>p->weight||s1==s2){
				mmin=p->weight;
				s2=j;
			}
		}		
	} 
}


void HuffmanCoding (HTNode ht[], HCode hcd[], int n){	
	HCode hc;
	int i,f,c;
	for (i=1; i<=n; i++){ //依哈夫曼树求编码，从第1个叶子开始 
	hc.start=n-1; 
	c=i;  
	f=ht[i].parent;
	while (f!=0){   //循根节点
		if (ht[f].lchild==c)	//当前结点是左孩子结点 
			hc.cd[hc.start--]='0';
		else	  //当前结点是双亲结点的右孩子结点 
			hc.cd[ hc.start--]='1';
		c=f; 
		f=ht[f].parent; //再对双亲结点进行同样的操作 
	}
	hc.start++;   
	hcd[i]=hc;
	}
} 

void operate(){
	char input[MaxSize];
	char zm[26];
	HuffmanTree ht,p;
	HCode hcd[2*MaxSize];
	int weight[MaxSize];
	char countzm[MaxSize],code[MaxSize],tmp[MaxSize];
	char zmCode[MaxSize][MaxSize];
	int i,count,j,k,length;
	while(1){
		memset(zm, 0, 26);
		count=0;
		printf("请输入字符串："); 
		gets(input);
		if (!strcmp(input,"0"))//停止输入
			break;
		length=strlen(input);
		//统计存在在字符串中的字符的数量 
		for(i=0;i<length;i++){
			zm[input[i]-97]++;
		}
		for(i=0;i<26;i++){
			if(zm[i]!=0){
				printf("%c:%d ",i+97,zm[i]);
				weight[count]=zm[i];		
				countzm[count]=i+97;
				count++;				
			}	
		}
		printf("\n");	
		//创建哈夫曼树 
		CreateHTree(ht,weight,count);
		//输出存储结构 
		for(p=ht+1,i=1;i<=2*count-1;i++,p++){
			printf("%2d ",i);
			printf("%2d ",p->weight);
			printf("%2d ",p->parent);
			printf("%2d ",p->lchild);
			printf("%2d\n",p->rchild);
		}
		//统计哈夫曼编码并存到zmCode的二维数组中 
		HuffmanCoding(ht,hcd,count);
		for(i=1;i<=count;i++){
			k=0;
			printf("%c:",countzm[i-1]);
			for(j=hcd[i].start;j<=2*count-1;j++){
				if(hcd[i].cd[j]=='0'||hcd[i].cd[j]=='1'){
					printf("%c",hcd[i].cd[j]);	
					zmCode[i-1][k]=hcd[i].cd[j];
					k++;
				}
			}
			zmCode[i-1][k]='\000';
			printf(" ");
		}
		printf("\n");
		//将字符串编码为二进制 
		for(i=0;i<length;i++){
			for(j=0;j<count;j++){
				if(input[i]==countzm[j]){
					printf("%s",zmCode[j]);
					strncat(code,zmCode[j],strlen(zmCode[j]));
					break;
				}
					
			}
		}
		code[strlen(code)]='\000'; 
		printf("\n");
		//解码 
		for(i=0,k=0;i<strlen(code);i++){
			tmp[k]=code[i];
			k++;
			tmp[k]='\000';
			for(j=0;j<count;j++){
				if(strcmp(tmp,zmCode[j])==0){
					printf("%c",countzm[j]);
					tmp[0]='\000';
					k=0;
					break;
				}
			}
		}

		printf("\n");
		code[0]='\000';
	}
}
//aaaaaaabbbbbccdddd
//dsjsjdcbcbccbjcxsdbjkdsjk
//fbxjkvlvdzfczxm
//vjhxklkvdsnkjxkldskjfl
//nsckkkdfnwefdsnvlkgrwfdl
