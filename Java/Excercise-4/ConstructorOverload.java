class ConstructorOverload
{
ConstructorOverload()
{
System.out.println("Constructor invoked with no value");
}
ConstructorOverload(int i)
{
System.out.println("Constructor invoked with value :"+i);
}
ConstructorOverload(int i,int j)
{
System.out.println("Constructor invoked with two values : "+i+" , "+j);
}
public static void main(String args[])
{
ConstructorOverload obj = new ConstructorOverload();
ConstructorOverload obj2 = new ConstructorOverload(20);
ConstructorOverload obj3 = new ConstructorOverload(10,20);
}
}