
import Polimorfismo_17.Empleado;
import Polimorfismo_17.Jefe;

public class Main
{
  public static void main(String[] args)
  {
    Empleado empleados[];
    Jefe jefes[];
    int numemp, numjefes;
    int op;
  
    System.out.println("\nIndique los empleados que hay en la empresa: ");
    numemp = Leer.datoInt();
    empleados = new Empleado[numemp];
    for (int pos = 0; pos < numemp; pos++)
      empleados[pos] = new Empleado();

    System.out.println("\nIndique los jefes que hay en la empresa: ");
    numjefes = Leer.datoInt();
    jefes = new Jefe[numemp];
    for (int pos = 0; pos < numjefes; pos++)
      jefes[pos] = new Jefe();
	
    visualTodosJefes(jefes);
    visualTodosEmpleados(empleados);
  }
  
  static void visualTodosEmpleados(Empleado empleados[])
  {
    int pos;
	System.out.println("\nLos datos de los empleados (que no son jefes) en la empresa son: ");
	for (pos = 0; pos < empleados.length; pos++)
	  empleados[pos].visualTodosDatos();
  }
  
  static void visualTodosJefes(Jefe jefes[])
  {
    int pos;
	System.out.println("\nLos datos de los jefes en la empresa son: ");
	for (pos = 0; pos < jefes.length; pos++)
	  jefes[pos].visualTodosDatos();
  }
}