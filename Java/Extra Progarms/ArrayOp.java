import java.util.*;
class ArrayOp extends Arrays
{
public static void main(String args[])
{
int a[] = {10,20,56,3,6,34};


// --** Accessing first & last elements **--

System.out.println("First element: "+a[0]);
System.out.println("Last element: "+a[a.length-1]);

// --** Accessing Random element using random() **--

System.out.println("Randomly accesed element: "+a[new Random().nextInt(a.length)]);

// --** Adding an element at the end**--
/*
int newArray[] = Arrays.copyOf(a,a.length+1);
newArray[newArray.length] = 25;
System.out.print(newArray);

int a2[] = a.clone();
boolean ans = Arrays.equals(a,a2);
System.out.println(ans);
*/

for(int i=1;i<5;i++)
{
for(int j=1;j<=i;j++)
{
System.out.print(i+"\t");
}
System.out.println();
}
}
}