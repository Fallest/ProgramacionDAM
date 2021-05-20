package FileOutputStream1_10;

import java.io.*;

public class test
{
  public static void main(String[] args) throws IOException
  {
    String cadena;
    int car;
    char cara;
    FileOutputStream fich = new FileOutputStream("hola.txt");

    System.out.println("\nInserte una frase: ");
    cadena = Leer.dato();
    for (int pos = 0; pos < cadena.length(); pos++)
    {
      fich.write(cadena.charAt(pos));
    }
    fich.write('\n');
    fich.close();

    System.out.println("\nEl contenido del fichero es: \n");
    FileInputStream fichLec = new FileInputStream("hola.txt");
    car = fichLec.read();
    while (car != -1)
    {
      cara = (char)car;
      System.out.println(cara);
      car = fichLec.read();
    }

    fichLec.close();
  }
}