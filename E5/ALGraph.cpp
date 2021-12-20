#include "ALGraph.h"

// 初始化 
void Init(ALGraph &G){
		
	ArcNode* NewNode;
	VertexType v1,v2;
	// 初始化点，从 1—N 
	for(int i= 1;i<=G.n;i++){
		G.vertices[i].data = i;
		G.vertices[i].firstarc = NULL;
	}
	// 初始化边 
	for(int i=0;i<G.e;i++){
		scanf("%d%d",&v1,&v2);
		NewNode = (ArcNode*)malloc(sizeof(ArcNode));
		NewNode->adjvex = v2;
		NewNode->nextarc = G.vertices[v1].firstarc;
		G.vertices[v1].firstarc=NewNode;
		
		NewNode = (ArcNode*)malloc(sizeof(ArcNode));
		NewNode->adjvex = v1;
		NewNode->nextarc = G.vertices[v2].firstarc;
		G.vertices[v2].firstarc=NewNode;
	}
}

void BFSTraverse(ALGraph &G){
	bool visit[MAXV];  // 是否访问 
	int count;
	for(int i=1;i<=G.n;i++){
		// 每次初始化访问数组 
		InitVisit(G,visit); 
		count = BFS(G,visit,i);
		output((100.0*count)/G.n,i);
	}
}


int BFS(ALGraph &G,bool visit[],VertexType v){
	SqQueue q;
	InitQueue(q);
	VertexType tmp;
	int level = 0;
	int last = v;  // 该层最后一次访问的结点 
	int tail = v;  // 每次在变的结点 
	ArcNode* node;
	visit[v] = true;
	int count = 1;  // 统计关系数 
	EnQueue(q,v);
	while(!empty(q)){
		DeQueue(q,tmp);
		// G[i]第一个结点存自己的下标 
		node = G.vertices[tmp].firstarc;
		while(node){
			if(!visit[node->adjvex]){
				visit[node->adjvex] = true;
				EnQueue(q,node->adjvex);
				count++;
				tail = node->adjvex; // 每次更新该结点 
			}
			node = node->nextarc;
		} 
		// 如果该当前结点是这层最后一个结点 
		if(tmp == last){  
			level++;    // 层数 +1  
			last = tail;   // 更改 last 
		}
		if(level==6)
		   break;
	}
	return count; 
} 



// 初始化访问状态 
void InitVisit(ALGraph &G,bool visit[]){
	for(int i=1;i<=G.n;i++)
		visit[i] = false;
}

void output(double result,int i){
	printf("%d: %.2f%%\n",i,result);
}
