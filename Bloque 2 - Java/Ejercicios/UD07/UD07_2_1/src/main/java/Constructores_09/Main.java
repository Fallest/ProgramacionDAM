public class Main
{
  public static void main(String args[])
  {
    System.out.println("\nDeclaracion de un objeto del tipo base1");
	Base1 ob1;
	System.out.println("\nInstanciacion de un objeto del tipo base1");
	ob1 = new Base1();
	
	System.out.println("\nDeclaracion de un objeto del tipo deriva1");
	Deriva1 ob2;
	System.out.println("\nInstanciacion de un objeto del tipo deriva1");
	ob2 = new Deriva1();
	
	System.out.println("\nDeclaracion de un objeto del tipo deriva2");
	Deriva2 ob3;
	System.out.println("\nInstanciacion de un objeto del tipo deriva2");
	ob3 = new Deriva2();
	
	System.out.println("\nFIN DEL PROCESO.");
  }
}