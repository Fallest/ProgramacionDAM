import java.io.*;

public class test
{
  public static void main(String[] args) throws IOException
  {
        File fichero;
	char resp;
	BufferedReader teclado = new BufferedReader(new InputStreamReader(System.in));
	String nombre;
	
	System.out.println("\nQuiere indicar el nombre del fichero para ver si existe?: ");
	resp = (char)System.in.read();
	while (resp == 's')
	{
          resp = (char)System.in.read(); // Salta el Intro //
	  System.out.println("\nIndique el nombre de un fichero: ");
	  nombre = teclado.readLine();
          System.out.println("Nombre del fichero: " + nombre);
	  fichero = new File(nombre);
	  
	  if (fichero.isFile())
	    System.out.println("\nOK. Este fichero existe.");
	  else
	    System.out.println("\nError. Este fichero no existe.");
	
	  System.out.println("\nQuiere indicar el nombre del fichero para ver si existe?: ");
	  resp = (char)System.in.read();
	}
  }
}