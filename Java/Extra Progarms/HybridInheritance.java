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

class Cullinan extends RollsRoyce
{
void c()
{
System.out.println("This is RollsRoyce Cullinan");
}
}

class BoatTail extends Cullinan
{
void d()
{
System.out.println("This is RollsRoyce BoatTail");
}
}

class Toyota extends Cars
{
void n(){
System.out.print("Toyota Supraaaaaa");
}
}

class HybridInheritance
{
public static void main(String args[]){
RollsRoyce rr = new RollsRoyce();
Toyota t = new Toyota();
BoatTail bt = new BoatTail();
rr.m();
rr.n();
t.m();
t.n();
bt.n();
bt.c();
bt.d();
}
}