
class ObjectAssign
{
	public static void main(String args[])
	{
		Hello obj = new Hello();
		Hello obj2;
		System.out.println(obj.i);
		obj2 = obj;
		obj2.i=20;
		System.out.println(obj2.i);
		System.out.println(obj.i);
	}
}
class Hello
{
	int i=10;
}