#include"include/SqList.h" 
#include"include/LinkList.h"


int main()
{
	int x;
	while(1){
		printf("\n*****************ͼ����Ϣ����ϵͳ*********************\n");
		printf("1.ѡ��˳��洢�ṹ\n");
		printf("2.ѡ����ʽ�洢�ṹ\n");
		printf("0.�˳��˵�\n");
		printf("*******************************************************\n");
		printf("������˵�ѡ��:> ");
		scanf("%d",&x);
		if(x==0){
			printf("ллʹ��ͼ�����ϵͳ��\n");
			break;
		}
		switch (x)
		{
			case 1: 
				printf("�ѽ���˳��洢�ṹ\n");
				SqListMain();
				break;
			case 2: 
				printf("�ѽ�����ʽ�洢�ṹ\n");
				LinkListMain();
				break;
			default:
				printf("�޴�ѡ�\n");
				break;
		}
	}
	return 0;	
}

