#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MaxSize 400  


typedef  struct {
	int weight;
	int parent, lchild, rchild; 
}HTNode, *HuffmanTree; //动态分配数组存储哈夫曼树

//存放每个结点哈夫曼编码的数据类型如下： 
typedef struct{     
	char cd[MaxSize];	//存放当前结点的哈夫曼编码
	int start;     //存放哈夫曼编码在cd中的起始位置 
} HCode;  


void Select(HuffmanTree &HT, int i,int &s1,int &s2);

void  CreateHTree( HuffmanTree &HT, int *w, int n);

void HuffmanCoding (HTNode ht[], HCode hcd[], int n);

void operate();
