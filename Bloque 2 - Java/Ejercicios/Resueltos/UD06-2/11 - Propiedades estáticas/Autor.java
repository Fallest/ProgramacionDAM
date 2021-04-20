import java.io.*;

public class Autor
{
  String nombre;
  double gananciasAutor;
  static float IRPF;
  
  void pedirDatos()
  {
    pedirNombre();
	pedirGananciasAutor();
  }
  
  String pedirCadena()
  {
    String cadena="";
	InputStreamReader flujo = new InputStreamReader(System.in);
	BufferedReader teclado = new BufferedReader(flujo);
	
	try
	{
	  cadena = teclado.readLine();
	}
	catch(IOException e)
	{
	  System.out.println("Ha habido un error en la entrada de datos.");
	}
	
	return cadena;
  }
  
  void pedirNombre()
  {
    System.out.println("\n\tInserte el nombre del autor: ");
	nombre = pedirCadena();
  }
  
  void pedirGananciasAutor()
  {
    String cadena;
	System.out.println("\n\tIndique cual ha sido la ganancia del autor: ");
	cadena = pedirCadena();
	gananciasAutor = Double.parseDouble(cadena);
  }
  
  void pedirIRPF()
  {
    String cadena;
	System.out.println("\n\tIndique cual es el IRPF que tiene que pagar el autor: ");
	cadena = pedirCadena();
	IRPF = Float.parseFloat(cadena);
  }
  
  void visualDatosAutor()
  {
    System.out.println("\n\tNOMBRE: " + nombre);
	System.out.println("\nGANANCIAS: " + gananciasAutor);
	System.out.println("\nIRPF: " + IRPF);
  }
}
