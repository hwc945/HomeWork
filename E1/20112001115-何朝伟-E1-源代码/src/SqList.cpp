#include"../include/SqList.h" 

Status InitList_Sq(SqList &L){
	L.elem = (Book1 *)malloc(LISTINCREMENT*sizeof(Book1));
	if(!L.elem)
		exit(OVERFLOW);
	L.length=0;
	return OK;
}

//���������Ϣ 
Status PrintAll_Sq(SqList &L){
	int i;
	if(L.length==0){
		printf("��ͼ����Ϣ��\n");	
		return OK;
	}
	printf("                ISBN                ����      ����\n");
	for(i=0;i<L.length;i++){
		printf("%20s",L.elem[i].no);
		printf("%20s",L.elem[i].name);
		printf("%10.2f\n",L.elem[i].price);
	}
	return OK; 
}

//���ͼ�� 
Status AddBook(SqList &L){
	int pos,i,l;
	Book1* newbase;
	printf("���ͼ�����Ϊ��");
	scanf("%d",&pos);
	l=L.length+pos;
	newbase=(Book1 *)realloc(L.elem,l*LISTINCREMENT*sizeof(Book1));
	if(!newbase)
		exit(OVERFLOW);
	L.elem=newbase;
	for(i=L.length;i<l;i++){
		scanf("%s",L.elem[i].no);
		scanf("%s",L.elem[i].name);
		scanf("%f",&L.elem[i].price);
		L.length++;
	}
	return OK;
} 

//����߼۸� 
Status TopBookPrice(SqList &L){
	if(L.length==0){
		printf("��ͼ����Ϣ��\n");	
		return OK;
	}
	float topPrice=L.elem[0].price;
	int i; 
	for(i=0;i<L.length;i++){
		if(L.elem[i].price>topPrice)
			topPrice=L.elem[i].price;
	}
	printf("                ISBN                ����      ����\n");
	for(i=0;i<L.length;i++){
		if(L.elem[i].price==topPrice){
			printf("%20s",L.elem[i].no);
			printf("%20s",L.elem[i].name);
			printf("%10.2f\n",L.elem[i].price);
		}
	}
} 

//ָ��λ�ò���
Status InsertBook(SqList &L,int pos){
	int i;
	Book1 tmp;
	Book1* newbase;
	if(pos<=0||pos>L.length){
		printf("����λ�÷Ƿ�!\n"); 
		return ERROR;
	}
	scanf("%s",tmp.no);
	scanf("%s",tmp.name);
	scanf("%f",&tmp.price);
	L.length++;
	newbase=(Book1 *)realloc(L.elem,L.length*LISTINCREMENT*sizeof(Book1));
	if(!newbase)
		exit(OVERFLOW);
	L.elem=newbase;	
	for(i=L.length-1;i>=pos;i--){
		L.elem[i]=L.elem[i-1];
	}
	L.elem[pos-1]=tmp;
	return OK;
} 

//ɾ��ָ��λ��ͼ����Ϣ
Status DeleteBookByPos(SqList &L,int pos){
	if(pos<=0||pos>L.length){
		printf("����λ�÷Ƿ�!\n"); 
		return ERROR;
	}
	int i;
	L.length--;
	for(i=pos-1;i<L.length;i++){
		L.elem[i]=L.elem[i+1];
	}
	return OK;
}

void SqListMain(){
	SqList l;
	InitList_Sq(l);
	int select = 0;
	int pos;              //����Ҫ�����λ��	
	while(1){
		printf("\n*****************ͼ����Ϣ����ϵͳ*********************\n");
		printf("1.���������Ϣ\n");
		printf("2.���ͼ��\n");
		printf("3.����۸���ߵ�ͼ����Ϣ\n");
		printf("4.ָ��λ�ò���ͼ����Ϣ\n");
		printf("5.ɾ��ָ��λ��ͼ����Ϣ\n");
		printf("0.�˳��˵�\n");
		printf("*******************************************************\n");
		printf("������˵�ѡ��:> ");
		scanf("%d",&select);
		if(select==0){
			printf("ллʹ��ͼ�����ϵͳ��\n");
			break;
		}
		switch (select)
		{
			case 1: 
				printf("ͼ����ϢΪ��\n");
				PrintAll_Sq(l);
				break;
			case 2: 
				if(AddBook(l)==1){
					printf("��ӳɹ���\n");
					PrintAll_Sq(l);
				} 
				break;
				
			case 3: 
				printf("�۸���ߵ�ͼ��Ϊ��\n");
				TopBookPrice(l); 
				break;
			case 4: 
				printf("����Ҫ����ͼ����Ϣ��λ�ã�");
				scanf("%d",&pos); 			
				if(InsertBook(l,pos)==1){
					printf("����ɹ�!\n");
					PrintAll_Sq(l);
				} 
				break;
			case 5:  
				printf("������Ҫɾ��ͼ����Ϣ��λ�ã�");
				scanf("%d",&pos); 	
				if(DeleteBookByPos(l,pos)==1){
					printf("ɾ���ɹ�!\n");
					PrintAll_Sq(l);
				} 
				break;
			default:
				printf("�޴�ѡ�\n");
				break;
		}
	} 
	printf("���˳�˳��洢�ṹ\n");
}
