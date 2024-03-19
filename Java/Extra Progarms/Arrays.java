import java.util.Scanner;

class St
{
private String name;
public St(String name)
{
this.name = name;
}
}

class Arrays
{
public static void main(String args[])
{
Scanner sc = new Scanner(System.in);
int s;


// --**Array Demonstration and Accesing**-- 

System.out.println("Enter the size of the array: ");
s = sc.nextInt();
int a[]=new int[s];
for(int i=0;i<s;i++)
{
System.out.println("Enter the element : ");
a[i] = sc.nextInt();
}
System.out.println("The array elements are: ");
for(int i=0;i<s;i++)
{
System.out.print("\t"+a[i]);
}


// --**Accessing Array elements using index**--

System.out.println();
System.out.println("The array 2nd element before modification : "+a[1]);
a[1]=100;
System.out.println("The array 2nd element after modification : "+a[1]);


// --** Storing objects into Array**--

St arr[]  = new St[3];
arr[0] = new St("Joe");
arr[1] = new St("Jay");
arr[2] = new St("Kalki");
System.out.println(" "+arr[0]);
}
}