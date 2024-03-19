import java.util.*;
class PalindromeSeq
{
public static void main(String args[])
{
int n,a,d,s=0,div=1;
Scanner sc = new Scanner(System.in);
System.out.print("Enter a number to check:");
n=sc.nextInt();
while(n>0)
{
a=n;
div=1;
s=0;
while(a!=0)
{
d=a%10;
a=a/10;
s=s+d*div;
div=div*10;
}
if(n==s)
{
System.out.println(n);
}
n--;
}
}
}