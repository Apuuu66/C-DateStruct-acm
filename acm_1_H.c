#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct Polynomial                 
{
	float    coef;   
	int      expn;   
	struct   Polynomial *next;
}Polynomial,*Polyn;

Polyn CreatePoly()                        
{
	Polynomial *head,*rear,*s;
	int c,e,n,i;

	head=(Polynomial *)malloc(sizeof(Polynomial));
	rear = head;

	scanf("%d\n",&n);

	for(i=1;i<=n;i++)
	{
		scanf("(%d,%d)",&c,&e);

		s = (Polynomial *)malloc(sizeof(Polynomial));
		s -> coef = c;
		s -> expn = e;
		rear -> next = s ;
		rear = s;
	}
	rear -> next = NULL;
	return(head);

}


void ValuePolyn(Polyn head)
{
	Polyn p;
	int value=0,x;
	scanf("%d",&x);
	p=head->next;
	while(p)
	{
		value += p->coef*pow(x,p->expn);
		p = p->next;
	}
	printf("%d",value);
}
int main()
{
	Polynomial *head;                  
	head = CreatePoly();
    ValuePolyn(head);                                           	                                
}
