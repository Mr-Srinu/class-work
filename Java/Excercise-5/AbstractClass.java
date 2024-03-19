abstract class Area{
abstract void square(float a);
abstract void rectangle(float l,float b);
abstract void circle(float r);
}

class Finding extends Area
{
public void square(float a){
System.out.println("Area of square with side "+a+" is: "+(a*a));
}
public void rectangle(float l, float b){
System.out.println("Area of rectangle with length "+l+" breadth "+b+" is: "+(l*b));
}
public void circle(float r){
System.out.println("Area of circle with side "+r+" is: "+(3.14*(r*r)));
}
}

class AbstractClass
{
public static void main(String args[]){
Finding obj = new Finding();
obj.square(10);
obj.rectangle(4,5);
obj.circle(2);
}
}

