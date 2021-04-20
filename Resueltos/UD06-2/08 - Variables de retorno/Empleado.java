import java.io.*;

public class Empleado
{
  public String nombre;
  public float sueldo;
  
  void pedirDatosEmp() throws IOException
  {
    String suelCad;
	InputStreamReader via = new InputStreamReader(System.in);
	BufferedReader teclado = new BufferedReader(via);
	
	System.out.println("\n\tInserte el nombre del empleado: ");
	nombre = teclado.readLine();
	
	System.out.println("\n\tInserte el sueldo del empleado: ");
	suelCad = teclado.readLine();
	sueldo = Float.parseFloat(suelCad);
  }
  
  public void asignarValores(String m, float s)
  {
    nombre = n;
	sueldo = s;
  }
  
  void visuDatosEmpleado()
  {
    System.out.println("\n\tNOMBRE: " + nombre);
	System.out.println("\n\tSUELDO: " + sueldo);
  }
  
  void asignarSueldo(float s)
  {
    sueldo = s;
  }
  
  void devolSueldo()
  {
    return sueldo;
  }
}
