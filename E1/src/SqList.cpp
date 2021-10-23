#include"../include/SqList.h" 

Status InitList_Sq(SqList &L){
	L.elem = (Book1 *)malloc(LISTINCREMENT*sizeof(Book1));
	if(!L.elem)
		exit(OVERFLOW);
	L.length=0;
	return OK;
}

//输出所有信息 
Status PrintAll_Sq(SqList &L){
	int i;
	if(L.length==0){
		printf("无图书信息！\n");	
		return OK;
	}
	printf("                ISBN                书名      定价\n");
	for(i=0;i<L.length;i++){
		printf("%20s",L.elem[i].no);
		printf("%20s",L.elem[i].name);
		printf("%10.2f\n",L.elem[i].price);
	}
	return OK; 
}

//添加图书 
Status AddBook(SqList &L){
	int pos,i,l;
	Book1* newbase;
	printf("添加图书个数为：");
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

//求最高价格 
Status TopBookPrice(SqList &L){
	if(L.length==0){
		printf("无图书信息！\n");	
		return OK;
	}
	float topPrice=L.elem[0].price;
	int i; 
	for(i=0;i<L.length;i++){
		if(L.elem[i].price>topPrice)
			topPrice=L.elem[i].price;
	}
	printf("                ISBN                书名      定价\n");
	for(i=0;i<L.length;i++){
		if(L.elem[i].price==topPrice){
			printf("%20s",L.elem[i].no);
			printf("%20s",L.elem[i].name);
			printf("%10.2f\n",L.elem[i].price);
		}
	}
} 

//指定位置插入
Status InsertBook(SqList &L,int pos){
	int i;
	Book1 tmp;
	Book1* newbase;
	if(pos<=0||pos>L.length){
		printf("输入位置非法!\n"); 
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

//删除指定位置图书信息
Status DeleteBookByPos(SqList &L,int pos){
	if(pos<=0||pos>L.length){
		printf("输入位置非法!\n"); 
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
	int pos;              //代表要插入的位置	
	while(1){
		printf("\n*****************图书信息管理系统*********************\n");
		printf("1.输出所有信息\n");
		printf("2.添加图书\n");
		printf("3.输出价格最高的图书信息\n");
		printf("4.指定位置插入图书信息\n");
		printf("5.删除指定位置图书信息\n");
		printf("0.退出菜单\n");
		printf("*******************************************************\n");
		printf("请输入菜单选项:> ");
		scanf("%d",&select);
		if(select==0){
			printf("谢谢使用图书管理系统！\n");
			break;
		}
		switch (select)
		{
			case 1: 
				printf("图书信息为：\n");
				PrintAll_Sq(l);
				break;
			case 2: 
				if(AddBook(l)==1){
					printf("添加成功！\n");
					PrintAll_Sq(l);
				} 
				break;
				
			case 3: 
				printf("价格最高的图书为：\n");
				TopBookPrice(l); 
				break;
			case 4: 
				printf("输入要插入图书信息的位置：");
				scanf("%d",&pos); 			
				if(InsertBook(l,pos)==1){
					printf("插入成功!\n");
					PrintAll_Sq(l);
				} 
				break;
			case 5:  
				printf("请输入要删除图书信息的位置：");
				scanf("%d",&pos); 	
				if(DeleteBookByPos(l,pos)==1){
					printf("删除成功!\n");
					PrintAll_Sq(l);
				} 
				break;
			default:
				printf("无此选项！\n");
				break;
		}
	} 
	printf("已退出顺序存储结构\n");
}
