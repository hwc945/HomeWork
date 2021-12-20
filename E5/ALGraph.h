#include <stdio.h>
#include<stdlib.h>
#include "SqQueue.h"
#define MAXV 10//<��󶥵����>

typedef struct ANode //����ߣ�������� 
{	
	int  adjvex;     //�û����յ�λ�� 
   	struct ANode *nextarc;     //ָ����һ���ߣ�������ָ�� 
} ArcNode;
typedef struct Vnode    //�����ͷ���
{	
 	VertexType data;            //������Ϣ 
    ArcNode *firstarc;          //ָ���һ���ߣ����� 
} AdjList[MAXV];
typedef struct 
{       
	AdjList vertices; //��Ŷ�����Ϣ����ͷ��㣩��һά����
    int  n, e; 	//ͼ�ж��������ߣ�������
} ALGraph;  //ͼ


// ��ʼ�� 
void Init(ALGraph &G);

void BFSTraverse(ALGraph &G);

int BFS(ALGraph &G,bool visit[],VertexType v);

//��ʼ���������� 
void InitVisit(ALGraph &G,bool visit[]);

void output(double result,int i); 
