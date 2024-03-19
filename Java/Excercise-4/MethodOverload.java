class Hello
{
	void m()
	{
		System.out.println("This is the method with 0 parameter ");
	}
	void m(int x)
	{
		System.out.println("This is the method with 1 parameter by changing no of parameters"+x);
	}
	void m(char x)
	{
		System.out.println("This is the method with 1 parameter by changing dataType "+x);
	}
}
class MethodOverload
{
	public static void main(String args[])
	{
		Hello obj = new Hello();
		obj.m();
		obj.m(10);
		obj.m('H');
	}
}