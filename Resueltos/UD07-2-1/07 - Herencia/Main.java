public class Main
{
  public static void main(String args[])
  {
    Empleado emp = new Empleado();
	Jefe jef = new Jefe();
	
	System.out.println("\nVamos a insertar los datos del empleado: ");
	emp.insdatemp();
	
	System.out.println("\nVamos a insertar los datos del jefe: ");
	jef.insdatjef();
	
	System.out.println("\nVamos a visualizar los datos del empleado: ");
	emp.visdatemp();
	
	System.out.println("\nVamos a visualizar los datos del jefe: ");
	jef.visdatjef();
  }
}