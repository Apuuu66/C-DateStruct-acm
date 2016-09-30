

#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct NodeType  
{
	int id;
	struct NodeType *next;  
}NodeType;

NodeType *CreaList(NodeType *,int);   
NodeType *GetNode(int ,int);   
void PritList(NodeType *);
int IsEmptyList(NodeType *);  
void JosephusOperate(NodeType *, int); 

NodeType *CreaList(NodeType *pHead ,int n){
	NodeType *p,*t;
	int i=0;
	int id,iPassword = 0 ;

	for (i=1 ; i<=n ; i++){
		p=(NodeType *)malloc(sizeof(NodeType));
		p->id=i;
		if(i==1){
			pHead=t=p;
			t->next = pHead;
		}
		else{
			p->next = t->next;
			t->next=p;
			t=p;
		}
	}
	return pHead;
}

NodeType *GetNode(int iId , int iPassword){
	NodeType *pNew = NULL;
	pNew = (NodeType *)malloc(sizeof(NodeType));
	if( !pNew){
		printf("Error,the memory is not enough!\n");
		exit(-1);
	}
	pNew -> id = iId;
	pNew -> next = NULL;

	return pNew;
}

void JosephusOperate(NodeType *pHead ,int iPassword){
	NodeType *p,*t,*q;
	int i;
	int flag =1 ;
	t=p=pHead;
	while(t->next != pHead){
		t= t->next;
	}
	while(flag){
		for(i=1 ; i<iPassword ; i++){
			t=p;
			p=p->next;
		}
		if(p==t){
			flag = 0;
		}
		q=p;
		t->next = p->next;
		p=p->next;
		printf("%d ",q->id);
		free(q);
	}
}


int main(){
	int n =0 ;
	int m = 0;
	NodeType *pHead = NULL;

	scanf("%d",&n);
	scanf("%d",&m);
	pHead=CreaList(pHead,n);
	JosephusOperate(pHead,m);
}