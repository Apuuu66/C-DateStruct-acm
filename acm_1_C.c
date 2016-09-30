#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct NodeType  
{
	int id;
	struct NodeType *next;  
}NodeType;

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

void JosephusOperate(NodeType *pHead ,int iPassword,int brray[]){
	NodeType *p,*t,*q;
	int i,j=0;
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
		brray[j] = q->id;
		j++;
		free(q);
	}
}


int main(){
	int n = 0;
	int k = 0;
	int i,j,t,m;
	int array[20],brray[20];
	NodeType *pHead = NULL;
	scanf("%d",&n);
	scanf("%d",&k);
	for(i=0;i<k;i++)
	{	
		scanf("%d",&array[i]);
	}
	for(i = 1;i <= n;i++)
	{

		t = n-k;
		m=0;
		pHead=CreaList(pHead,n);
		JosephusOperate(pHead,i,brray);
		for(j=0;j<k;j++,t++)
		{
			if(array[j] == brray[t])
				m++;
			if(m==k)
			{
				printf("%d",i);
				i=n+1;
			}
		}
	}
	if(m != k)
		printf("%d",0);
	return 1;
	
}
