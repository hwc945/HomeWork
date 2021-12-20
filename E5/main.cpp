#include<stdio.h>
#include<stdlib.h>
#define MaxVertex 100
#include "ALGraph.h"

int main(){
	ALGraph G;
	while(1){
		scanf("%d%d",&G.n,&G.e);
		if(G.n==0&&G.e==0)
			break;
		Init(G);
		BFSTraverse(G);
	}
	return 0;
} 
/**

10 9
1 2
2 3
3 4
4 5
5 6
6 7
7 8
8 9
9 10

10 8
1 2
2 3
3 4
4 5
5 6
6 7
7 8
9 10
*/
