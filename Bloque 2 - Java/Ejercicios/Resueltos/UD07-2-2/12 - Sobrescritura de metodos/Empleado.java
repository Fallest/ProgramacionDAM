public class Empleado
{
  private String nom;
  private int edad;
  
  public Empleado()
  {
    indicaTipoPersonal();
	pedirDatos();
  }
  
  void pedirDatos()
  {
    System.out.println("\nVamos a insertar los datos del empleado: ");
	System.out.println("\n\tNOMBRE: ");
	nom = Leer.dato();
	System.out.println("\n\tEDAD: ");
	edad = Leer.datoInt();
  }
  
  static void indicaTipoPersonal()
  {
    System.out.println("\nESTA PERSONA ES UN EMPLEADO DE LA EMPRESA.");
  }
  
  void visualTodosDatos()
  {
    System.out.println("\nSe van a visualizar los datos de un empleado: ");
	System.out.println("\n\tNOMBRE: " + nom);
	System.out.println("\n\tEDAD: " + edad);
  }
}