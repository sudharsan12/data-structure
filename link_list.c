#include<stdio.h>
#include<stdlib.h>
typedef struct student
{
	int no;
	char name[10];
	struct student *next;
}st;
void  list(st **);
void delete(st **);
void show (st *);
int main()
{
	st *hptr=NULL;
	int i;
	while(1)
	{
		printf("enter list---> 1 \n delete list ----> 2 \n show list----> 3\n exit ----> 4");
		scanf("%d",&i);
		switch(i)
		{
			case 1: list(&hptr);
			       break;
			case 2: delete(&hptr);
			        break;
			case 3: show(hptr);
				break;
			default:return 0;
		}
	}
}
void list(st **ptr)
{

	st *temp;
	temp=(st*)malloc(sizeof(st));
	printf("enter the student no and name\n");
	scanf("%d %s",&temp->no,temp->name);
	temp->next=*ptr;
	*ptr=temp;

}
void delete(st **ptr)
{
	int no;
	st *prv=*ptr;
	printf("enter the delete id no\n");
	scanf("%d",&no);
	if((*ptr)->no==no)
	{
		printf("%d %s\n",(*ptr)->no,(*ptr)->name);
		*ptr=(*ptr)->next;
		free(prv);
		prv=NULL;
		return ;
	}
	else
	{
		while(*ptr!=0)
		{
			if((*ptr)->no==no)
			{
		printf("%d %s\n",(*ptr)->no,(*ptr)->name);
				prv->next=(*ptr)->next;
		//		*ptr=NULL;
				return;
			}
			prv=*ptr;
			*ptr=(*ptr)->next;

		}
		printf("the data doesnt found...\n");
	}
}
void show(st *ptr)
{
if( ptr==NULL)
{
	printf(" the list is empty\n");
	return ;
}
while(ptr!=0)
{
	printf("%d <------> %s \n",ptr->no,ptr->name);
       ptr=ptr->next;	
}
}
