import java.io.*;
import java.util.*;
class Roots
{
	public static void main(String args[])
	{
		int a,b,c,d;
		a=Integer.parseInt(args[0]);
		b=Integer.parseInt(args[1]);
		c=Integer.parseInt(args[2]);
		d=((b*b)-(4*a*c));
		double e=Math.sqrt(d);
		double r1=((-b)+e)/(2*a);
		double r2=((-b)-e)/(2*a);
		System.out.println("The root are :"+r1+" , "+r2);		
		if(d>0)
		{
			System.out.println("The roots are real and different");
		}
		if(d==0)
		{
			System.out.println("The roots are real and equal");
		}
		if(d<0)
		{
			System.out.println("The roots are imaginary");
		}
	}
}