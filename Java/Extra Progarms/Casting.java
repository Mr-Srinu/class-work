class Hello{
	void m(){
		System.out.println("This Hello class m method");
	}
	void n(){
		System.out.println("This Hello class n method");
	}
}
class Welcome extends Hello{
	void m(){
		System.out.println("This Welcome class m method");
	}
	void p(){
		System.out.println("This Welcome class p method");
	}
}
class Casting 
{
	public static void main(String args[]){
		Welcome obj = new Welcome();
		obj.m();
		obj.n();
		
		Hello ob = new Hello();
		
		//UpCasting
		System.out.println();
		Hello obj2 = new Welcome();
		obj2.m();		// It is accepeted because it is overrided , so op will be as like Welcome class method
		obj2.n();
		//obj2.p();		Only Methods of Hello Class can be accesed
	
		//DownCasting	(IT can access any function)
		System.out.println();
		Welcome obj3 = (Welcome) obj2;
		obj3.m();
		obj3.n();
		obj3.p();
		
	}
}