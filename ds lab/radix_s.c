#include<stdio.h>
int largest(int[],int);
int nofDigits(int);
void radix(int[],int);
int main()
{
    int i,n, a[10];
    printf("Enter size of array:");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }

    printf("\nElements before sorting\n");
    for(i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
    radix(a,n);
    printf("\nElements After sorting\n");
    for(i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
    return 0;
}
int largest(int a[10],int n)
{   
    int large,i;
    large=a[0];
    for(i=1;i<n;i++)
    {
        if(a[i]>large)
        {
            large = a[i];
        }
    }
    return large;
}
int nofDigits(int n)
{
    int nodigits=0;
    while(n>0)
    {
        nodigits=nodigits+1;
        n=n/10;
    }
    return nodigits;
}
void radix(int a[10],int n)
{
    int bucket[10][12],bc[10],i,j,k,diviser=1;
    int r,nop,pass,large;
    large=largest(a,n);
    nop=nofDigits(large);
    printf("\nLargest is %d\n",large);
    printf("\nNo of digits is :%d\n",nop);
    for(pass=0;pass<nop;pass++)
    {
        for(i=0;i<10;i++)
        {
            bc[i]=0;
        }
        for(i=0;i<n;i++)
        {
            r=(a[i]/diviser)%10;
            bucket[r][bc[r]]=a[i];
            bc[r] = bc[r]+1;
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
        diviser = diviser*10;
    }
    
}

