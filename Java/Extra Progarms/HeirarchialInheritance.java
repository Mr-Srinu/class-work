class Cars
{
void m()
{
System.out.println("The car name is :");
}
}

class RollsRoyce extends Cars
{
void n(){
System.out.print("Rolls Royce");
}
}

class Toyota extends Cars
{
void n(){
System.out.print("Toyota Supraaaaaa");
}
}

class HeirarchialInheritance
{
public static void main(String args[]){
RollsRoyce rr = new RollsRoyce();
Toyota t = new Toyota();
rr.m();
rr.n();
t.m();
t.n();
}
}