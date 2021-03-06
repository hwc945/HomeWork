#include<stdio.h>
#include<stdlib.h>
#define MaxVertex 10005
#include "SqQueue.h"
typedef int vertex;
typedef struct Node *AdjList;
struct Node{
	vertex Adjv;  // 当前下标 
	AdjList Next;  // 下一个 
};
AdjList G[MaxVertex];
bool visit[MaxVertex];  // 是否访问 
int N;  // 结点数
int M;  // 边数 

// 初始化访问状态 
void InitVisit(){
	for(int i=1;i<=G.Next;i++)
		visit[i] = false;
}

// 初始化 
void Init(){
	vertex v1,v2;
	AdjList NewNode;
	//cin>>N>>M;
	scanf("%d%d",&N,&M);
	// 初始化点，从 1—N 
	for(int i=1;i<=N;i++){
		G[i] = (AdjList)malloc(sizeof(struct Node));
		G[i]->Adjv = i;
		G[i]->Next = NULL;
	}
	// 初始化边 
	for(int i=0;i<M;i++){
		//cin>>v1>>v2;
		scanf("%d%d",&v1,&v2);
		NewNode = (AdjList)malloc(sizeof(struct Node));
		NewNode->Adjv = v2;
		NewNode->Next = G[v1]->Next;
		G[v1]->Next = NewNode;
		
		NewNode = (AdjList)malloc(sizeof(struct Node));
		NewNode->Adjv = v1;
		NewNode->Next = G[v2]->Next;
		G[v2]->Next = NewNode;
	}
}

int BFS(vertex v){
	SqQueue q;
	InitQueue(q);
	vertex tmp,xx;
	int level = 0;
	int last = v;  // 该层最后一次访问的结点 
	int tail = v;  // 每次在变的结点 
	AdjList node;
	visit[v] = true;
	int count = 1;  // 统计关系数 
	EnQueue(q,v);
	while(!empty(q)){
		tmp = front(q);
		DeQueue(q,xx);
		// G[i]第一个结点存自己的下标 
		node = G[tmp]->Next;
		while(node){
			if(!visit[node->Adjv]){
				visit[node->Adjv] = true;
				EnQueue(q,node->Adjv);
				count++;
				tail = node->Adjv; // 每次更新该结点 
			}
			node = node->Next;
		} 
		// 如果该当前结点是这层最后一个结点 
		if(tmp == last){  
			level++;    // 层数 +1  
			last = tail;   // 更改 last 
		}
		// 层数够了结束 
		if(level==6)
		   break;
	}
	return count; 
} 


void output(double result,int i){
	printf("%d: %.2f%%\n",i,result);
}

void SDS(){
	int count;
	for(int i=1;i<=N;i++){
		// 每次初始化访问数组 
		InitVisit(); 
		count = BFS(i);
		output((100.0*count)/N,i);
	}
}


//int main(){
//	Init();
//	SDS();
//	
//	return 0;
//} 

