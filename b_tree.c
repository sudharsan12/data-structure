// here level order m= 4
//  so that max key m-1 -> 4-1=3
//  min key (m/2)-1  -> 4/2-1=1
//  max links   m =4
//  min links   (m/2)=2


#include<stdio.h>
#include<malloc.h>
#define MIN_KEY 1
#define MAX_KEY 3
#define MIN_LINK 2
#define MAX_LINK 4

typedef struct Node
{
	int data[MAX_KEY],d_count,l_count;

	struct Node *link[MAX_LINK];
}btree;
btree *parent;
btree * makenode(int data)
{
	int i;
	btree *child=(btree *)malloc(sizeof(btree));
	child->data[child->d_count++]=data;
	for(i=0;i<MAX_LINK;i++)
		child->link[i]=NULL;
	
	return child;
}
int sort(int *data,btree *node)
{

		int i,temp;
		for(i=0;i<node->d_count;i++)
		{
			if(*data<node->data[i])
			{
				temp=*data;
				*data=node->data[i];
				node->data[i]=temp;
			}
		}
		return i;
}
void splitcells(btree **root,btree *parent,int data)
{
 if(*root==parent)
 {
	 *root=makenode((*root)->data[MAX_KEY-1]);
	 (*root)->link[(*root)->l_count++]=parent;
	 parent->data[--parent->d_count]=0;
	 (*root)->link[(*root)->l_count++]=makenode(data);

	 parent=*root;
 }

}

void insert(btree **root,int data)
{
	if(*root==NULL)
	{
		*root=makenode(data);
		parent=*root;
	}
	else if((*root)->l_count==0)
	{
		int count=sort(&data,*root);
		if(count==MAX_KEY)
			splitcells(root,parent,data);
		else
			(*root)->data[(*root)->d_count++]=data;

	}
        else{
		int i=0;
		for(;i<(*root)->d_count&&(*root)->data[i]<data;i++);
		insert(&(*root)->link[i],data);

	}
}
void traversal(btree *root)
{
	if(root==NULL)
	{
		printf("hai\n");
		return;
	}
	int i=0;
	for(i=0;i<root->l_count;i++)
		traversal(root->link[i]);
		for(i=0;i<root->d_count;i++)
		printf("%d \n",root->data[i]);
	
	

}


int main()
{

btree *root=NULL;
	insert(&root,9);
	insert(&root,7);
	insert(&root,3);
	insert(&root,2);
	insert(&root,21);
	insert(&root,1);
	insert(&root,2);
	insert(&root,4);
	insert(&root,5);
	insert(&root,10);
	insert(&root,12);  
	traversal(root);
}
