#include<stdio.h>
void mergesort(int[],int,int);
void merge(int[],int,int,int);
int main()
{
    int n,i;
    int a[10];
    printf("Enter array length");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    mergesort(a,0,n);
    printf("Elements after Sorting"); 
    for(i=1;i<=n;i++)
    {
        printf("%d \t",a[i]);
    } 
    return 0;
}
void mergesort(int a[10],int low,int high)
{
    int mid;
    if(low<high)
    {
        mid=(low+high)/2;
        mergesort(a,low,mid);
        mergesort(a,mid+1,high);
        merge(a,low,mid,high);
    }
}
void merge(int a[10],int low,int mid, int high)
{
    int b[10],i,j,k=low;
    i=low;
    j=mid+1;
    while(i<=mid && j<=high)
    {
        if(a[i]<=a[j])
        {
            b[k]=a[i];
            k++;
            i++;
        }
        else
        {
            b[k]=a[j];
            k++;
            j++;
        }
    }
  
        while(j<=high)
        {
            b[k]=a[j];
            k++;
            j++;
        }

  

        while(i<=mid)
        {
            b[k]=a[i];
            k++;
            i++;
        }
 
    for(i=low;i<=high;i++)
    {
        a[i]=b[i];
    }
}
