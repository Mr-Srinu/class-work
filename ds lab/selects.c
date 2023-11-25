#include<stdio.h>
void main()
{
	int a[10],n,temp,i,j,min;
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
		min=i;
		for (j=i;j<n;j++)
		{
			if(a[min]>a[j])
			{
				temp=a[min];
				a[min]=a[j];
				a[j]=temp;
			}
		}
	}
	printf("\n array after sorting:");
	for(i=0;i<n;i++)
	{
	printf("\t%d",a[i]);
	}
}
