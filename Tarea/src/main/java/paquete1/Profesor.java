package paquete1;

class Profesor
{
  private String nombre;
  private String especialidad;

  void pedirTodosDatos()
  {
        pedirNombre();
        pedirEspecialidad();
  }

  private void pedirNombre()
  {
    // Aqui se introducira todo el codigo necesario para pedir el nombre por el teclado.
  }

  private void pedirEspecialidad()
  {
    // Aqui se introducira todo el codigo necesario para pedir la especialidad por el teclado.
  }

  public void visualDatosProfesor()
  {
    System.out.println("\n\tNOMBRE: " + nombre);
    System.out.println("\tESPECIALIDAD: " + especialidad);
  }
} 
