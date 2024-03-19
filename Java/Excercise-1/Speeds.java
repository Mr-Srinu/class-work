class Speeds
{
	public static void main(String args[])
	{
		int a,b,c,d,e,avg;
		a=Integer.parseInt(args[0]);
		b=Integer.parseInt(args[1]);
		c=Integer.parseInt(args[2]);
		d=Integer.parseInt(args[3]);
		e=Integer.parseInt(args[4]);
		avg=((a+b+c+d+e)/5);
		if(a>avg)
		{
			System.out.println("Racer 1 with speed of "+a);
		}
		if(b>avg)
		{
			System.out.println("Racer 2 with speed of "+b);
		}
		if(c>avg)
		{
			System.out.println("Racer 3 with speed of "+c);
		}
		if(d>avg)
		{
			System.out.println("Racer 4 with speed of "+d);
		}
		if(e>avg)
		{
			System.out.println("Racer 5 with speed of "+e);
		}
	
	}
}