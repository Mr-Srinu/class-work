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

class C extends B
{
void f()
{
System.out.println("This is method f in class C");
}
}

class MultiLevelInheritance
{
public static void main(String args[])
{
C obj = new C();
obj.m();
obj.n();
obj.f();
}
}