#include"../include/LinkList.h" 


//��ʼ�� 
Status InitLinkList(LinkList &L){
	L=(LinkList)malloc(sizeof(LNode));
    L->next=NULL;
}
	
//���������Ϣ 
Status PrintAll_LinkList(LinkList &L){
	LinkList p;
	p=L->next;
	if(L->next==NULL){
		printf("��ͼ����Ϣ��\n");
		return OK;
	}		
	printf("                ISBN                ����      ����\n");
	while(p){
		printf("%20s",p->data.no);
		printf("%20s",p->data.name);
		printf("%10.2f\n",p->data.price);
		p=p->next;
	}
	return OK;
}

//���ͼ��--->β�巨 
Status AddBook_LinkList(LinkList &L){
	int i,pos;
	LinkList p,q;
	p=L;
	printf("���ͼ�����Ϊ��");
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

//��������
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
            // �ڵ����
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
		printf("����λ�÷Ƿ���\n");
		return ERROR;
	}
	else{
		while(i<pos&&p!=NULL){
			p=p->next;
			i++;
		}
		if(p==NULL){
			printf("����λ�÷Ƿ���\n");
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
	
//ɾ��ָ��λ��ͼ����Ϣ
Status DeleteBookByPos_LinkList(LinkList &L,int pos){
	int j=1;
	LinkList p=L,q; 
	if(p==NULL||pos<=0){
		printf("����λ�÷Ƿ���\n");
		return ERROR;
	}
	while (j<pos && p!=NULL) 
	{ 
		j++;
		p=p->next;
	}
	if(p==NULL||p->next==NULL){
		printf("����λ�÷Ƿ���\n");
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
	int pos;              //����Ҫ�����λ��	
	while(1){
		printf("\n*****************ͼ����Ϣ����ϵͳ*********************\n");
		printf("1.���������Ϣ\n");
		printf("2.���ͼ��\n");
		printf("3.ͼ�鰴�۸�����\n");
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
				PrintAll_LinkList(l);
				break;
			case 2: 
				if(AddBook_LinkList(l)==1){
					printf("��ӳɹ���\n");
					PrintAll_LinkList(l);
				} 
				break;
				
			case 3: 
				if(LinkSort(l)==1) {
					printf("����ɹ�!\n");
					PrintAll_LinkList(l);
				}					
				else
					printf("����ʧ�ܣ�\n");
				break;
			case 4: 
				printf("������Ҫ����ͼ����Ϣ��λ�ã�");
				scanf("%d",&pos); 
				if(InsertBook_LinkList(l,pos)==1){
					printf("����ɹ�!\n");
					PrintAll_LinkList(l);
				}
				break;
			case 5: 
				printf("������Ҫɾ��ͼ����Ϣ��λ�ã�");
				scanf("%d",&pos); 
				if(DeleteBookByPos_LinkList(l,pos)==1){
					printf("ɾ���ɹ�!\n");
					PrintAll_LinkList(l);
				} 
				break;
			default:
				printf("�޴�ѡ�\n");
				break;
		}
	} 
	printf("���˳���ʽ�洢�ṹ\n");
}
