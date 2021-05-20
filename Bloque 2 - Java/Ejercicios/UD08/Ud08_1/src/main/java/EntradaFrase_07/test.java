package EntradaFrase_07;

import java.io.*;

public class test
{
  public static void main(String[] args) throws IOException
  {
    char c;
    String frase="";

    System.out.println("Inserte una frase: ");
    c = (char)System.in.read();

    while (c != '\n')
    {
      frase = frase + c;
      c = (char)System.in.read();
    }

    System.out.println("\nLa frase insertada es: " + frase);
    System.out.println("\nFIN DEL PROGRAMA\n");
  }
}