import java.io.*;
import java.util.*;
class BubbleSort
{
public static void main(String args[])
{
Scanner sc = new Scanner(System.in);
int n,i,j,temp;
System.out.println("Enter n value: ");
n = sc.nextInt();
int[] ar = new int[n];
System.out.println("Enter array elements:");
for(i=0;i<n;i++){
ar[i]=sc.nextInt();
}
System.out.println("Array elements before sorting:");
for(i=0;i<n;i++){
System.out.printf("%d\t",ar[i]);
}
System.out.println();
for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{
if(ar[i]<ar[j])
{
temp=ar[i];
ar[i]=ar[j];
ar[j]=temp;
}
}
}
System.out.println("Array elements After sorting:");
for(i=0;i<n;i++){
System.out.printf("%d\t",ar[i]);
}
}
}