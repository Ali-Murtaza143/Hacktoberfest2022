#include<stdio.h>
int main()
{
	int n,i,m,j=0;
	printf("Enter the size of array\n");
	scanf("%d",&n);
	int arr[n],arr1[n];
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	
	printf("enter value ");
	scanf("%d",&m);
	
	for(i=0;i<n;i++)
	{
		if(m<=arr[i])
		{
			arr1[j]=arr[i];
			j++;	
		}
	}
	for(i=0;i<j;i++)
	{	
		printf("%d ",arr1[i]);
	}
}
