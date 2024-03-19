class Basic
{
static int i=10;
void hello(){
System.out.println("Have a nice Day");
}
public static void main(String args[])
{
Basic obj = new Basic();
obj.hello();
obj.i=20;
System.out.println(i);
}
}