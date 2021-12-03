#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MaxSize 400  


typedef  struct {
	int weight;
	int parent, lchild, rchild; 
}HTNode, *HuffmanTree; //��̬��������洢��������

//���ÿ��������������������������£� 
typedef struct{     
	char cd[MaxSize];	//��ŵ�ǰ���Ĺ���������
	int start;     //��Ź�����������cd�е���ʼλ�� 
} HCode;  


void Select(HuffmanTree &HT, int i,int &s1,int &s2);

void  CreateHTree( HuffmanTree &HT, int *w, int n);

void HuffmanCoding (HTNode ht[], HCode hcd[], int n);

void operate();
