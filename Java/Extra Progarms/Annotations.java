class He{
	void m(){
		System.out.println("Hay this is somthing");
	}
	void n(){
		System.out.println("This is n");
	}
}
class Hey extends He{
	@Override
	void m(int m){
		System.out.println("Override possible");
		//super.n();
	}
	void h(){
		System.out.print("Anyway");
	}
}
class Annotations{
	public static void main(String args[]){
	Hey obj = new Hey();
	obj.m();
	}
}