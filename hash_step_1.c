#include<stdio.h>
int main()
{
	int a[7],i,n,count=0;
	while(count<7)
	{
		printf("enter the data into the list...\n");
		scanf("%d",&n);
		i=n%7;
		a[i]=n;
		count++;
	}
	printf("enter the searching number...\n");
	scanf("%d",&n);

	i=n%7;

	if(a[i]==n)
		printf("your are searching data=%d\n",a[i]);
	else
		printf("i am sorry you are searched data not here..\n");
}
