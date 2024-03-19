class CallBy
{
	int j=10;
	void incrementVal(int i)
	{
		i=i+1;
		System.out.println("The value of the number inside the method = "+i);
	}
	void incrementVal(CallBy c)
	{
		c.j=c.j+1;
		System.out.println("The value of the number inside the method = "+c.j);
	}
	public static void main(String args[])
	{
		int i=10;

		CallBy c = new CallBy();
		
		System.out.println("----Using callBy Reference----");
		System.out.println("Before method call : "+c.j);
		incrementVal(c.j);
		System.out.println("After method call : "+c.j);
		System.out.println();
		
		System.out.println("----Using callBy Value----");
		System.out.println("Before method call : "+i);
		incrementVal(i);
		System.out.println("After method call : "+i);
	}
}