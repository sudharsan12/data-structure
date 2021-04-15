#include<stdio.h>
int size=0;
void swap(int *a,int *b)
{
	int temp=*b;
	*b=*a;
	*a=temp;
}
void heapify(int *array,int i)
{
	if(size==1)
		printf("single element in the heap");
	else
	{
		int largest=i;
		int l=2*i+1;
		int r=2*i+2;
		if(l<size && array[l]>array[largest])
			largest=l;
		if(r<size && array[r]>array[largest])
			largest=r;

		if(largest!=i)
		{
			swap(&array[i],&array[largest]);
			heapify(array,largest);
		}

	}
}
void insert(int *array,int newnum)
{
	int i;
	if(size==0)
	{
		array[0]=newnum;
		size+=1;
	}else
	{
		array[size]=newnum;
		size+=1;
		for(i=size/2-1;i>=0;i--)
			heapify(array,i);
	}
}
void delete_root(int *array,int num)
{
	int i;
	for(i=0;i<size;i++)
		if(num==array[i])
			break;
	swap(&array[i],&array[size-1]);
	size-=1;
	for(i=size/2-1;i>=0;i--)
			heapify(array,i);

}
void print_array(int *array)
{
	int i;
	for(i=0;i<size;i++)
		printf("%d \n",array[i]);
}
int main()
{
	int array[10];

	insert(array,3);
	insert(array,4);
	insert(array,9);
	insert(array,5);
	insert(array,2);

	printf("max heap array:\n");
	print_array(array);

	delete_root(array,4);

	printf("after deleting an element\n");
	print_array(array);

}
