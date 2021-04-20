import java.io.*;

public class Principal
{
  public static void main(String args[]) throws IOException
  {
    Empleado emp1, emp2;
	
	emp1 = new Empleado();
	emp2 = new Empleado();
	
	System.out.println("\n\nVamos a asignarle valores al empleado 1: ");
	emp1.asignarValores("Fidela", 1450);
	
	System.out.println("\n\nVamos a asignarle valores al empleado 2: ");
	emp2.nombre = "Ponci";
	emp2.sueldo = 2300;
	
	System.out.println("\n\nLos datos del empleado 1 son: ");
	emp1.visuDatosEmpleado();
	
	System.out.println("\n\nLos datos del empleado 2 (visualizandolos fuera de la clase) son: ");
	System.out.println("\tNombre:\t\t" + emp2.nombre);
	System.out.println("\tSueldo:\t\t" + emp2.sueldo);
	
	emp1.sueldo = 1560;
	emp2.asignarSueldo(2780);
	
	System.out.println("\n\n¡Hemos cambiado el sueldo de cada uno de los empleados!");
	
	System.out.println("\n\nLos datos del empleado 1 son: ");
	System.out.println("\tNombre:\t\t" + emp1.nombre);
	System.out.println("\tSueldo:\t\t" + emp1.sueldo);
		
	System.out.println("\n\nLos datos del empleado 2 (visualizandolos fuera de la clase) son: ");
	emp2.visuDatosEmpleado();
	
	System.out.println("\n\nFIN DEL PROGRAMA");
  }
}