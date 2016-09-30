
#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct NodeType  
{
	int id;
	int password;
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
		scanf("%d"  ,&iPassword);
		p=(NodeType *)malloc(sizeof(NodeType));
		p->password=iPassword;
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
	pNew -> id = iId;
	pNew -> password = iPassword;
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
		iPassword= q->password;
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