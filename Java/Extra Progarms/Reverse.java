class Reverse
{
	public static void main(String args[])
	{
		int div=0,sum=0;
		int n=253;
		while(n>0)
		{
			div=n%10;
			n=n/10;
			sum=sum*10+div;
		}
		System.out.println("Reverse of "+n+" is :"+sum);
	}
}