#include"../include/LinkList.h" 


//初始化 
Status InitLinkList(LinkList &L){
	L=(LinkList)malloc(sizeof(LNode));
    L->next=NULL;
}
	
//输出所有信息 
Status PrintAll_LinkList(LinkList &L){
	LinkList p;
	p=L->next;
	if(L->next==NULL){
		printf("无图书信息！\n");
		return OK;
	}		
	printf("                ISBN                书名      定价\n");
	while(p){
		printf("%20s",p->data.no);
		printf("%20s",p->data.name);
		printf("%10.2f\n",p->data.price);
		p=p->next;
	}
	return OK;
}

//添加图书--->尾插法 
Status AddBook_LinkList(LinkList &L){
	int i,pos;
	LinkList p,q;
	p=L;
	printf("添加图书个数为：");
	scanf("%d",&pos);
	while(p->next!=NULL){
		p=p->next;
	}
	for(i=0;i<pos;i++){
		q=(LinkList)malloc(sizeof(LNode));
		q->next=NULL;
		scanf("%s",q->data.no);
		scanf("%s",q->data.name);
		scanf("%f",&q->data.price);
		p->next=q;
		p=q;
	}
	
	return OK;
}

//链表排序
Status LinkSort(LinkList &L){
    LinkList p, prep, temp, tail;		
	tail = NULL;
	while( L->next != tail ){
	     prep = L;
	     p = L->next;
	    while( p->next != tail ){
	        if( p->data.price < p->next->data.price ){
             	temp = p->next;
             	prep->next = p->next;
                p->next = p->next->next;
                prep->next->next = p;
                p = temp;
            }
            // 节点后移
            p = p->next;
            prep = prep->next;
       		}
        	tail = p;
	    }
    
	return OK;
}
 
Status InsertBook_LinkList(LinkList &L,int pos){
	int i=1;
	LinkList p,q;
	p=L;
	if(p==NULL||pos<=0){
		printf("输入位置非法！\n");
		return ERROR;
	}
	else{
		while(i<pos&&p!=NULL){
			p=p->next;
			i++;
		}
		if(p==NULL){
			printf("输入位置非法！\n");
			return ERROR;
		}	
		q=(LinkList)malloc(sizeof(LNode));
		q->next=NULL;
		scanf("%s",q->data.no);
		scanf("%s",q->data.name);
		scanf("%f",&q->data.price);
		q->next=p->next;
		p->next=q;
	}
	return OK;
}
	
//删除指定位置图书信息
Status DeleteBookByPos_LinkList(LinkList &L,int pos){
	int j=1;
	LinkList p=L,q; 
	if(p==NULL||pos<=0){
		printf("输入位置非法！\n");
		return ERROR;
	}
	while (j<pos && p!=NULL) 
	{ 
		j++;
		p=p->next;
	}
	if(p==NULL||p->next==NULL){
		printf("输入位置非法！\n");
		return ERROR;
	}
	else{ 
		q=p->next; 
		if (q==NULL) 
			return ERROR;
		p->next=q->next; 
		free(q); 
		return OK; 
	}
	return ERROR;
}

void LinkListMain(){
	LinkList l;
	InitLinkList(l);
	int select = 0;
	int pos;              //代表要插入的位置	
	while(1){
		printf("\n*****************图书信息管理系统*********************\n");
		printf("1.输出所有信息\n");
		printf("2.添加图书\n");
		printf("3.图书按价格排序\n");
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
				PrintAll_LinkList(l);
				break;
			case 2: 
				if(AddBook_LinkList(l)==1){
					printf("添加成功！\n");
					PrintAll_LinkList(l);
				} 
				break;
				
			case 3: 
				if(LinkSort(l)==1) {
					printf("排序成功!\n");
					PrintAll_LinkList(l);
				}					
				else
					printf("排序失败！\n");
				break;
			case 4: 
				printf("请输入要插入图书信息的位置：");
				scanf("%d",&pos); 
				if(InsertBook_LinkList(l,pos)==1){
					printf("插入成功!\n");
					PrintAll_LinkList(l);
				}
				break;
			case 5: 
				printf("请输入要删除图书信息的位置：");
				scanf("%d",&pos); 
				if(DeleteBookByPos_LinkList(l,pos)==1){
					printf("删除成功!\n");
					PrintAll_LinkList(l);
				} 
				break;
			default:
				printf("无此选项！\n");
				break;
		}
	} 
	printf("已退出链式存储结构\n");
}
