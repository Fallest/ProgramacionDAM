package Sobrecarga_05;

import java.io.*;

class Principal
{
  public static void main(String args[]) throws IOException
  {
    System.out.println("\nDeclaramos un objeto donde se piden todos los datos menos la deuda y la antiguedad, que toman valor 0.");
    Cliente cl1 = new Cliente();
    System.out.println("\nDeclaramos un objeto donde se piden todos los datos menos la deuda y la antiguedad; esta vez tomaran los valores indicados en la instanciacion del objeto.");
    Cliente cl2 = new Cliente(1000, 3);
    System.out.println("\nDeclaramos un objeto donde se piden todos los datos menos el nombre, la deuda y la antiguedad; dicho nombre se indicara en el momento de la instanciacion del objeto y la deuda y la antiguedad tomaran el valor 0.");
    Cliente cl3 = new Cliente("Juan Gonzalez");
    System.out.println("\nVisualizamos el primer objeto: ");
    cl1.visualTodosDatos();
    System.out.println("\nVisualizamos el segundo objeto: ");
    cl2.visualTodosDatos();
    System.out.println("\nVisualizamos el tercer objeto: ");
    cl3.visualTodosDatos();
    System.out.println("\n\nFIN DEL PROGRAMA.");
  }
}