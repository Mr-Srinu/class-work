interface Key{
	default void m(){
		System.out.println("Hello This Definition is from Interface");
	}
}
class def implements Key{
	int a =20;
}
class DefaultKeyWord {
	public static void main(String args[]){
		def obj = new def();
		obj.m();
	}
}