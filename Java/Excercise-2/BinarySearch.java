import java.io.*;
import java.util.*;
class BinarySearch 
{
static void Bsearch(int k, int[] a,int high,int low)
{
int m= ((low+high)/2);
if(m!=0)
{
if(a[m]==k)
{
System.out.println("Element found at position"+(m+1));
}
else if(a[m]<k)
{
low=m+1;
Bsearch(k,a,high,low);
}
else
{
high=m-1;
Bsearch(k,a,high,low);
}
}
else
{
System.out.println("Element not found!");
}
}
public static void main(String args[])
{
Scanner sc = new Scanner(System.in);
int n;
System.out.println("Enter n value: ");
n = sc.nextInt();
int[] ar = new int[n];
System.out.println("Enter array elements:");
for(int i=0;i<n;i++){
ar[i]=sc.nextInt();
}
System.out.println("Array elements are:");
for(int i=0;i<n;i++){
System.out.printf("%d\t",ar[i]);
}
System.out.println();
System.out.print("After sorting:");
Arrays.sort(ar);
for(int i=0;i<n;i++){
System.out.printf("%d\t",ar[i]);
}
System.out.print("Enter a key value to search:");
int k = sc.nextInt();
Bsearch(k,ar,n,0);
}
}