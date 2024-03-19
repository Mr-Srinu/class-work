class A
{
	int age;
	String name;
	
	//with using this keyword
	int x=5;
	void display(int x)
	{
		this.x=x;
		System.out.println("The changed value : "+x); 
	}
	
	//calling default constructor using parameterized constructor
	A()
	{
		System.out.println("Invoked the constructor using This keyword");
	}
	A(int x)
	{
		this();
		System.out.println(this.x);
	}
	
	//invoking class method using this keyword
	void m()
	{
		System.out.println("This is m method invoked using main method");
	}
	void n()
	{
		System.out.println("This is N method invoked using main method");
		this.m();
		
	}
	
	//returning the current class object using this keyword
	A getA()
	{
		return this;
	}
	void msg()
	{
		System.out.println("Hello Java");
	}
	
	//Passing this as an argument into a method
	void thisArg(A obj)
	{
		System.out.println("This keyword argument method is invoked");
	}
	void p()
	{
		thisArg(this);
	}
	
	//Passing this as an argument in the constructor calling
	ThisKeyword t;
	A(ThisKeyword t)
	{
		this.t = t;
	}
	void disp()
	{
		System.out.println("This keyword succesfull in constructor calling by returning "+t.d);
	}
	
	//Passing class objects as parameters in Methods
	A(int a,String n)
	{
		age=a;
		name=n;
	}
	void displays(A ob)
	{
		System.out.println("Age is : "+ob.age);
		System.out.println("Name is : "+ob.name);
	}
}


class ThisKeyword
{
	int d =10;
	ThisKeyword()
	{
		A b = new A(this);
		b.disp();
	}
	public static void main(String args[])
	{
		A obj = new A(10);
		obj.display(10);
		
		obj.n();
		
		obj.getA().msg();
		
		ThisKeyword ob = new ThisKeyword();
		
		A obj2 = new A(20,"Srinu");
		obj2.displays(obj2);
	
	}
	
}

