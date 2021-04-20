package ClasesExcepciones18;

import java.io.*;
import java.util.*;

public class Alumno
{
  String nombre;
  int edad;
  static int contador = 0;

  Alumno() throws DemasiadosObjetos
  {
    InputStreamReader via = new InputStreamReader(System.in);
    BufferedReader tecla = new BufferedReader(via);

    String cad;
    DemasiadosObjetos objdemasObj = new DemasiadosObjetos();

    if (contador == 3)
      throw objdemasObj;
    else
    {
      try
      {
        System.out.println("\tIndica el nombre del alumno: ");
        nombre = tecla.readLine();
        System.out.println("\tIndica la edad del alumno: ");
        cad = tecla.readLine();
        edad = Integer.parseInt(cad);
      }
      catch(IOException e)
      {
        System.out.println("\n\nSe ha producido un error.");
      }

      contador++;
    }
  }


  int devEdad()
  {
    return edad;
  }


  protected void finalize()
  {
    System.out.println("\nSe liberan los datos de un objeto.");
    System.out.println("\nLos datos del alumno son: ");
    this.visualDatosAlumno();
    contador--;
  }


  void visualDatosAlumno()
  {
    System.out.println("\n\tNOMBRE: " + nombre);
    System.out.println("\n\tEDAD: " + edad);
  }
} 