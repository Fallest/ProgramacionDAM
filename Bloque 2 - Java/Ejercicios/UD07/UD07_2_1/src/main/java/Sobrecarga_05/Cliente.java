package Sobrecarga_05;

import java.io.*;

public class Cliente
{
  String nombre;
  int edad;
  float altura;
  float deuda;
  int antig;
  
  void pedirNombre()
  {
    System.out.println("\n\tInserte el nombre del cliente: ");
    nombre = Leer.dato();
  }
  
  void pedirEdad()
  {
    System.out.println("\nInserte la edad del cliente: ");
    edad = Leer.datoInt();
  }
 
  void pedirAltura()
  {
    System.out.println("\nInserte la altura del cliente: ");
    altura = Leer.datoFloat();
  }
  
  Cliente()
  {
    pedirNombre();
    pedirEdad();
    pedirAltura();
  }
  
  Cliente(float d, int ant)
  {
    pedirNombre();
    pedirEdad();
    pedirAltura();
    deuda = d;
    antig = ant;
  }
  
  Cliente(String nom)
  {
    nombre = nom;
    pedirEdad();
    pedirAltura();
  }
  
  void visualTodosDatos()
  {
    visualNombre();
    visualEdad();
    visualAltura();
    visualAntiguedad();
    visualDeuda();
  }
  
  void visualNombre()
  {
    System.out.println("\n\tNOMBRE: " + nombre);
  }

  void visualEdad()
  {
    System.out.println("\n\tEDAD: " + edad);
  }

  void visualAltura()
  {
    System.out.println("\n\tALTURA: " + altura);
  }
  
  void visualAntiguedad()
  {
    System.out.println("\n\tANTIGUEDAD: " + antig);
  }
  
  void visualDeuda()
  {
    System.out.println("\n\tDEUDA: " + deuda);
  }
}