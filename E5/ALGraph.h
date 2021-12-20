#include <stdio.h>
#include<stdlib.h>
#include "SqQueue.h"
#define MAXV 10//<最大顶点个数>

typedef struct ANode //定义边（弧）结点 
{	
	int  adjvex;     //该弧的终点位置 
   	struct ANode *nextarc;     //指向下一条边（弧）的指针 
} ArcNode;
typedef struct Vnode    //定义表头结点
{	
 	VertexType data;            //顶点信息 
    ArcNode *firstarc;          //指向第一条边（弧） 
} AdjList[MAXV];
typedef struct 
{       
	AdjList vertices; //存放顶点信息（表头结点）的一维数组
    int  n, e; 	//图中顶点数、边（弧）数
} ALGraph;  //图


// 初始化 
void Init(ALGraph &G);

void BFSTraverse(ALGraph &G);

int BFS(ALGraph &G,bool visit[],VertexType v);

//初始化访问数组 
void InitVisit(ALGraph &G,bool visit[]);

void output(double result,int i); 
