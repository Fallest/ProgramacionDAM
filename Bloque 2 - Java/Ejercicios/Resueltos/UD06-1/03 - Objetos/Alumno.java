package paquete;

public class Alumno
{
  private String nombre;
  private int edad;

  public void inicialDatos(String n, int e)
  {
    nombre = n;
    edad = e;
  }

  void visualDatos()
  {
    System.out.println("\n\tNOMBRE: " + nombre);
    System.out.println("\tEDAD: " + edad);
  }

  protected void modificarDatos()
  {
    pedirNombre();
    pedirEdad();
  }

  private void pedirNombre()
  {
    // Aqui estaria el codigo para pedir el nombre por el teclado.
  }

  private void pedirEdad()
  {
    // Aqui estaria el codigo para pedir la edad por el teclado.
  }
} 
