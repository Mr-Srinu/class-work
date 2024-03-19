class Primes
{
	public static void main(String args[])
	{
		int sum=0,i,j=2,f=0,k;
		for(i=0;i<100;i++)
		{
			while(f!=1)
			{
				for(k=2;k<j;k++)
				{
					if(j%k==0)
					{
						f=1;
						
					}
				}
				if(f==0)
				{
					sum=sum+j;j++;
				}
				
			}
			f=0;
		}
		System.out.println("Sum of fist 100 primes is :"+sum);
	}
}