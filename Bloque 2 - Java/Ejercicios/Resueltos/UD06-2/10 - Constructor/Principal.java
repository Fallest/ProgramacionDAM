import java.io.*;

public class Principal
{
  public static void main(String args[]) throws IOException
  {
    System.out.println("Entramos en el programa principal");
	System.out.println("\nDeclaramos un objeto de tipo linea. Le asignamos el valor 15");
	Linea obj1 = new Linea(15);
	
	System.out.println("\nDeclaramos otro objeto de tipo linea. Le asignamos el valor 8");
	Linea obj2 = new Linea(8);
	
	System.out.println("\nFIN DEL PROGRAMA");
  }
}