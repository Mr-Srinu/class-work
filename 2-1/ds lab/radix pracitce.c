#include<stdio.h>
int largest(int[],int);
int noofdigits(int);
void radix(int[],int);
int main()
{
    int a[10],n,i;
    printf("Enter n value");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("\nElement before sorting\n");
    for(i=1;i<n+1;i++)
    {
        printf("\t%d",a[i]);
    }
    radix(a,n);
    printf("\nElement after sorting\n");
    for(i=0;i<n;i++)
    {
        printf("\t%d",a[i]);
    }
    return 0;
}
int largest(int a[10], int n)
{
	int large,i;
	large=a[0];
	for(i=0;i<n;i++)
	{
		if(a[i]>large)
		{
			large=a[i];
		}
	}
	return large;
}
int noofdigits(int large){
	int dig=0;
	while(large>0)
	{
		dig++;
		large=large/10;
	}
	return dig;
}
void radix(int a[10],int n)
{
	int bucket[9][12],bc[10],i,j,k,pass,rem=0,d=0,large,np;
	large=largest(a,n);
	np=noofdigits(large);
	for(pass=0;i<np;pass++)
	{
		for(i=0;j<n;j++)
		{
			bc[i]=0;
		}
		for(i=0;i<n;i++)
		{
			rem=(a[i]/d)%10;
			bucket[rem][bc[rem]]=a[i];
			bc[rem]=bc[rem]+1;
		}
		i=0;
		for(k=0;k<10;k++)
		{
			for(j=0;j<bc[k];j++)
			{
				a[i]=bucket[k][j];
				i++;
			}
		}
		d=d*10;
	}
}

