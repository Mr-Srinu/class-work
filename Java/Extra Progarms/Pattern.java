
//  *    sp=4 s=2 st=1
// * *   sp=3 s=1 st=2
//* * *  sp=2 s=0 st=3

class Pattern
{
	public static void main(String args[])
	{
		int n=4;
		for(int i=1;i<=n;i++)
    	{
       		for(int j=i;j<=n;j++)
       		{
      			System.out.print(" ");
       		}
			for(int k=1;k<=i;k++)
        	{
       			System.out.print("* ");
       		}
       		System.out.println();
    	}	
	}
}


