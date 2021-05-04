package Polimorfismo_17;

public class Becario extends Empleado
{
  String univEstud;
  
  public Becario()
  {
	pedirDatosBecario();
  }
  
  void pedirDatosBecario()
  {
    System.out.println("\n\tNOMBRE DE LA UNIVERSIDAD DONDE ESTUDIO: ");
	univEstud = Leer.dato();
  }
  
  public void visualTodosDatos()
  {
    /* Se sobrescribe el metodo de la clase Empleado */
	super.visualTodosDatos();
	System.out.println("\n\tNOMBRE DE LA UNIVERSIDAD DONDE ESTUDIO: " + univEstud);
  }
}