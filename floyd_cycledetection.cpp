#include<iostream>
using namespace std;

typedef struct list
{
	int data;
	struct list *next;
}node;


void insert(node **head,int data)
{
	node *pack=new node;
	pack->data=data;
	if(*head==NULL)
	{
		pack->next=*head;
		*head=pack;
	}else
	{
		node *temp=*head;
		while(temp->next!=NULL)
			temp=temp->next;
		pack->next=temp->next;
		temp->next=pack;
	}
}

void print(node *head)
{
	if(head==NULL)
		cout<<"list is empty\n";
	else
	{
		while(head!=NULL)
		{
			cout<<head->data<<"----> ";;
			head=head->next;
		}
	}
}

void make_loop(node **head)
{
	if(*head==NULL)
		return;
	node *temp=(*head)->next->next->next;
	node *iter=*head;
	while(iter->next!=NULL)
		iter=iter->next;
	iter->next=temp;

}
void find_loop(node *head)
{
	if(head==NULL)
		return;
	node *rappit=head;
	node *turtle=head;
	while(rappit&& turtle)
	{
		turtle=head->next;
		rappit=head->next->next;
		if(turtle==rappit)
		{
			printf("this is cyclic list\n");
			return;
		}
	}
	printf("this is not a cyclic list\n");
}

int main()
{

node *head=NULL;
insert(&head,1);
insert(&head,2);
insert(&head,3);
insert(&head,4);
insert(&head,5);

print(head);
//make loopfor testing purpose
//make_loop(&head);
insert(&head,6);
insert(&head,7);
insert(&head,8);
//find_loop(head);

}


