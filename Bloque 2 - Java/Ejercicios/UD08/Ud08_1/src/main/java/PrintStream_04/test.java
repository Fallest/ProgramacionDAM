package PrintStream_04;

import java.io.*;

public class test
{
  public static void main(String[] args) throws IOException
  {
    String[] lista = {"Juan Clemente", "Maria Jesus", "Noelia", "Ruben"};
	float[] notas={7.5f, 9.1f, 6.2f, 6.8f};
	
	PrintStream obPrintStr = new PrintStream(System.out);
	
	for(int pos = 0; pos < lista.length; pos++)
	{
	  obPrintStr.printf("%-15s", lista[pos]);
	  obPrintStr.printf("%.2f\n", notas[pos]);
	}
  }
}