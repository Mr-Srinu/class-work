class Sup{
	void m(){
		System.out.println("Hay this is somthing");
	}
	void n(){
		System.out.println("This is n");
	}
}
class Hey extends Sup{
	void m(int i){
		System.out.println("Override can't possible");
		super.n();
		this.h();
	}
	void h(){
		System.out.print("Anyway");
	}
}
class SuperKeyWord{
	public static void main(String args[]){
	Hey obj = new Hey();
	obj.m();
	obj.m(10);
	}
}