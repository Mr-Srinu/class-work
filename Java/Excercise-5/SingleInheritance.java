import java.io.*;
import java.util.*;

class A
{
void m()
{
System.out.println("This is the method m in class A");
}
}
class B extends A
{
void n()
{
System.out.println("This is the method n in class B");
}
}

class SingleInheritance
{
public static void main(String args[])
{
B obj = new B();
obj.m();
obj.n();
}
}