// in this graph representation popularly not used for programmers

#include<stdio.h>
#define V 5
#define E 8
void add_edge(int (*arr)[E],int i,int j)
{
	arr[i][j]=1;
}

int main()
{
	int matrix[V][E]={0};
	int i,j;

	add_edge(matrix,0,0);
	add_edge(matrix,0,1);
	add_edge(matrix,1,0);
	add_edge(matrix,1,2);
	add_edge(matrix,1,3);
	add_edge(matrix,1,5);
	add_edge(matrix,1,6);
	add_edge(matrix,2,6);
	add_edge(matrix,2,7);
	add_edge(matrix,3,3);
	add_edge(matrix,3,4);
	add_edge(matrix,3,7);
	add_edge(matrix,4,1);
	add_edge(matrix,4,2);
	add_edge(matrix,4,4);

	printf("   ");
		for(j=0;j<E;j++)
			printf("E%d ",j+1);
		printf("\n");
	for(i=0;i<V;i++)
	{
		printf("%c  ",'A'+i);
		for(j=0;j<E;j++)
			printf("%d  ",matrix[i][j]);
		printf("\n");
	}

}
