#include<stdio.h>
#include<malloc.h>
typedef struct  test
{
	char var;
	int data;
	struct test *next;
}T;

void insert(T **head)
{
	T *temp;
	temp=malloc(sizeof(T));
	printf("enter the character and no \n");
	scanf(" %c%d",&temp->var,&temp->data);
	temp->next=*head;
	*head=temp;
}
void view(T *head)
{
	while(head!=NULL)
	{
		printf("%c ->%d\n",head->var,head->data);
		head=head->next;
	}
}
void delete(T **head)
{
	T *sam=*head,*prv;
	char c;
	printf("enter the delete the character\n");
	scanf(" %c",&c);
	while(sam->next!=NULL && sam->var!=c)
	{
		prv=sam;
		sam=sam->next;
	}
	prv->next=sam->next;

}
int main()
{
	T *head=NULL;
	while(1)
	{
		int i;
		printf("1-> insert data\n 2->view data \n 3 ->delete data \n 4 ->exit\n");
		scanf("%d",&i);
		switch(i)
		{
			case 1:printf("please enter  your data \n");
			       insert(&head);
			       break;
			case 2:printf(" ........... your data............. \n");
			       view(head);
			       break;
			case 3:printf("please enter  your data  delete data \n");
			       delete(&head);
			       break;
			case 4:printf("...............thank you............ \n");
			       break;
		}

	}
}
