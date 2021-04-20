package VariablesEntorno08;

import java.io.IOException;

public class ProyReturn
{
  public static void main(String args[]) throws IOException
  {
    float sueldo1, sueldo2;
	Empleado emp1, emp2;
	
	emp1 = new Empleado();
	emp2 = new Empleado();
	emp1.pedirDatosEmp();
	emp2.pedirDatosEmp();
	
	sueldo1 = emp1.devolSueldo();
	sueldo2 = emp2.devolSueldo();
	
	System.out.println("\nEstos son los datos del empleado que más gana:");
	
	if (sueldo1 > sueldo2)
	  emp1.visuDatosEmpleado();
	else
	  emp2.visuDatosEmpleado();
  }
}