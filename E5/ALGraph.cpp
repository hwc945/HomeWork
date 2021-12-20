#include "ALGraph.h"

// ��ʼ�� 
void Init(ALGraph &G){
		
	ArcNode* NewNode;
	VertexType v1,v2;
	// ��ʼ���㣬�� 1��N 
	for(int i= 1;i<=G.n;i++){
		G.vertices[i].data = i;
		G.vertices[i].firstarc = NULL;
	}
	// ��ʼ���� 
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
	bool visit[MAXV];  // �Ƿ���� 
	int count;
	for(int i=1;i<=G.n;i++){
		// ÿ�γ�ʼ���������� 
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
	int last = v;  // �ò����һ�η��ʵĽ�� 
	int tail = v;  // ÿ���ڱ�Ľ�� 
	ArcNode* node;
	visit[v] = true;
	int count = 1;  // ͳ�ƹ�ϵ�� 
	EnQueue(q,v);
	while(!empty(q)){
		DeQueue(q,tmp);
		// G[i]��һ�������Լ����±� 
		node = G.vertices[tmp].firstarc;
		while(node){
			if(!visit[node->adjvex]){
				visit[node->adjvex] = true;
				EnQueue(q,node->adjvex);
				count++;
				tail = node->adjvex; // ÿ�θ��¸ý�� 
			}
			node = node->nextarc;
		} 
		// ����õ�ǰ�����������һ����� 
		if(tmp == last){  
			level++;    // ���� +1  
			last = tail;   // ���� last 
		}
		if(level==6)
		   break;
	}
	return count; 
} 



// ��ʼ������״̬ 
void InitVisit(ALGraph &G,bool visit[]){
	for(int i=1;i<=G.n;i++)
		visit[i] = false;
}

void output(double result,int i){
	printf("%d: %.2f%%\n",i,result);
}
