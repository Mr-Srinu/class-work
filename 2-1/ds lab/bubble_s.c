#include<stdio.h>
void main()
{
	int a[10],n,temp,i,j;
	printf("Enter the length of arrray:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("array before sorting:");
	for(i=0;i<n;i++)
	{
	printf("\t%d",a[i]);
	}
	for(i=0;i<n;i++)
	{
	
		for(j=0;j<n-1;j++)
		{
			if(a[j+1]<a[j])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	 
	}
	printf("\n array after sorting:");
	for(i=0;i<n;i++)
	{
	printf("\t%d",a[i]);
	}
	
}
