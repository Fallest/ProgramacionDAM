import java.io.*;

public class Cuenta
{
  private static float benef;  // Dinero que da el banco a los titulares de las cuentas.
  private String titular;
  private float saldo;
  
  Cuenta()
  {
    System.out.println("\nIndique el nombre del titular: ");
	titular = pedirCadena(); // El saldo parte de 0 y al ser el valor por defecto no se pide. Idem con benef.
  }
  
  static String pedirCadena()
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
  
  public void ingresar()
  {
    String cingreso;
	float ingre;
	System.out.println("\nIndique el ingreso que realiza el cliente: " + titular + ": ");
	cingreso = pedirCadena();
	ingre = Float.parseFloat(cingreso);
	saldo = saldo + ingre;
  }
  
  static void pedirBenef()
  {
    String cadbene;
	System.out.println("\n¿Cual es el aporte economico que da la empresa a todos sus clientes?: ");
	cadbene = pedirCadena();
	benef = Float.parseFloat(cadbene);
  }
  
  void visualDatosCuenta()
  {
    System.out.println("\n\tTITULAR: " + titular);
	System.out.println("\tSALDO: " + saldo);
	System.out.println("\tBENEFICIO: " + benef);
  }
}