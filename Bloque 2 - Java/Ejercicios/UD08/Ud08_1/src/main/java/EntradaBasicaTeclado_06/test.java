package EntradaBasicaTeclado_06;

import java.io.*;

public class test
{
  public static void main(String[] args) throws IOException
  {
    int numCarac;
	char carac;
	System.out.println("Inserte un caracter: ");
	numCarac = System.in.read();
	carac = (char)numCarac;
	
	System.out.println("\nEl primer caracter insertado es " + carac + ". El codigo ASCII es " + numCarac);
  }
}