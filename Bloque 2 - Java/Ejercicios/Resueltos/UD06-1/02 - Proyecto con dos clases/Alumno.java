import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Alumno
{
  String nombre;
  int edad;

  void pedirDatosAlumno()
  {
    String edadCadena;
    InputStreamReader flujo = new InputStreamReader(System.in);
    BufferedReader teclado = new BufferedReader(flujo);

    try
    {
      System.out.println("\n\n\tInserte el nombre del alumno: ");
      nombre = teclado.readLine();
      System.out.print("\n\n\tInserte la edad del alumno: ");
      edadCadena = teclado.readLine();
      edad = Integer.parseInt(edadCadena);
    }catch(IOException e)
    {
      System.out.println("Ha habido un problema en la entrada de datos.");
    }
  }

  void visualDatosAlumno()
  {
    System.out.println("\n\n\tLos datos del alumno son: ");
    System.out.println("\n\n\tNOMBRE: " + nombre);
    System.out.println("\n\n\tEDAD: " + edad);
  }
} 
