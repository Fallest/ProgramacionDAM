import java.io.*;

public class Linea
{
  public Linea(int tam)
  {
    int cont;
	System.out.print("\t\t");
	for(cont=1; cont<=tam; cont++)
	  System.out.print("*");
  }
}