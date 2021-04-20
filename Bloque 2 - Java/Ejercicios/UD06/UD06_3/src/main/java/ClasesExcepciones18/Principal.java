package ClasesExcepciones18;

import java.io.*;
import java.util.*;

class Principal
{
  public static void main(String args[])
  {
    Alumno alum1 = null, alum2 = null, alumMayor, alum4, alum5;

    try
    {
      System.out.println("\nVamos a insertar los datos del alumno 1: ");
      alum1 = new Alumno();

      System.out.println("\nVamos a insertar los datos del alumno 2: ");
      alum2 = new Alumno();
    }
    catch(DemasiadosObjetos e)
    {
      e.informError("Alumno");
      System.out.println("\n\nCerramos el programa.");
      System.exit(0);
    }

    alumMayor = mayor(alum1, alum2);
    System.gc();
    //Thread.sleep(100); // Detenemos el programa para que el recolector de basura actue.

    System.out.println("\n\nLos datos del alumno mayor de los tres que teniamos hasta ahora son: ");
    alumMayor.visualDatosAlumno();

    try
    {
      System.out.println("\nVamos a insertar los datos del alumno 4: ");
      alum4 = new Alumno();

      System.out.println("\nVamos a insertar los datos del alumno 5: ");
      alum5 = new Alumno();
    }
    catch(DemasiadosObjetos e)
    {
      e.informError("Alumno");
      System.out.println("\n\nCerramos el programa.");
      System.exit(0);
    }
  }


  static Alumno mayor(Alumno al1, Alumno al2)
  {
    //Pedimos los datos de un tercer alumno y devolvemos los datos del alumno mayor.
    Alumno alum3 = null, alumMayor;

    try
    {
      System.out.println("\nVamos a insertar los datos del alumno 3: ");
      alum3 = new Alumno();
    }
    catch(DemasiadosObjetos e)
    {
      e.informError("Alumno");
      System.out.println("\n\nCerramos el programa.");
      System.exit(0);
    }

    if(   (al1.devEdad()>=al2.devEdad()) && (al1.devEdad()>=alum3.devEdad()))
      alumMayor = al1;
    else
      if(al2.devEdad()>=al1.devEdad() && al2.devEdad()>=alum3.devEdad())
        alumMayor = al2;
      else
        alumMayor = alum3;

    return alumMayor;
  }
} 