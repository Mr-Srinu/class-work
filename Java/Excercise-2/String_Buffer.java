import java.lang.*;
class String_Buffer{
	public static void main(String args[]){
		StringBuffer s = new StringBuffer("This is some text");
		System.out.println(s.delete(8,12));
		s.append(" modified");
		System.out.println(s);
	}
}