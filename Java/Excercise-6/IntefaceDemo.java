interface A{
	public static int a=10;
	abstract void m();
}
class B implements A
{
	public void m()
	{
		System.out.println("Hello This method is abstracted");
	}
}
class InterfaceDemo 
{
	public static void main(String args[])
	{
		B obj = new B();
		System.out.println(obj.a);
		obj.m();
	}
}
	