package ejercicio1;

import java.io.*;
import java.util.Scanner;

public class Principal3
{
  public static void main(String args[]) throws IOException
  {
    String nombre;
    float numero;
    Scanner entrada = new Scanner(System.in);

    System.out.print("\n\tInserte un nombre: ");
    nombre = entrada.nextLine();
    System.out.print("\n\tInserte un numero: ");
    numero = entrada.nextFloat();

    System.out.println("\n\nLos datos insertados son: ");
    System.out.println("\n\n\tNOMBRE: " + nombre);
    System.out.println("\n\n\tNUMERO INSERTADO: " + numero);

    System.out.println("\n\nFinal del programa.");
  }
} 
