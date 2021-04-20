public class Jefe extends Empleado
{
  String nomDeparJefe;
  
  public Jefe()
  {
	pedirDatosJefe();
  }
  
  void pedirDatosJefe()
  {
    System.out.println("\n\tNOMBRE DEL DEPARTAMENTO: ");
	nomDeparJefe = Leer.dato();
  }
  
  void visualTodosDatos()
  {
    /* Se sobrescribe el metodo de la clase Empleado */
	super.visualTodosDatos();
	System.out.println("\n\tNOMBRE DEL DEPARTAMENTO: " + nomDeparJefe);
  }
}