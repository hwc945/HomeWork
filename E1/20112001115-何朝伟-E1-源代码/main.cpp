#include"include/SqList.h" 
#include"include/LinkList.h"


int main()
{
	int x;
	while(1){
		printf("\n*****************图书信息管理系统*********************\n");
		printf("1.选择顺序存储结构\n");
		printf("2.选择链式存储结构\n");
		printf("0.退出菜单\n");
		printf("*******************************************************\n");
		printf("请输入菜单选项:> ");
		scanf("%d",&x);
		if(x==0){
			printf("谢谢使用图书管理系统！\n");
			break;
		}
		switch (x)
		{
			case 1: 
				printf("已进入顺序存储结构\n");
				SqListMain();
				break;
			case 2: 
				printf("已进入链式存储结构\n");
				LinkListMain();
				break;
			default:
				printf("无此选项！\n");
				break;
		}
	}
	return 0;	
}

