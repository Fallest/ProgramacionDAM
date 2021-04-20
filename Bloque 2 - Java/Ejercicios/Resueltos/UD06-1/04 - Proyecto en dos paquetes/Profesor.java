package paquete1;

public class Profesor
{
  private String nombre;
  private String especialidad;

  private void pedirTodosDatos()
  {
    pedirNombre();
    pedirEspecialidad();
  }

  void pedirNombre()
  {
    // Aqui se introducira todo el codigo necesario para pedir el nombre por el teclado.
  }

  protected void pedirEspecialidad()
  {
    // Aqui se introducira todo el codigo necesario para pedir la especialidad por el teclado.
  }

  public void visualDatosProfesor()
  {
    System.out.println("\n\tNOMBRE: " + nombre);
    System.out.println("\tESPECIALIDAD: " + especialidad);
  }
} 
