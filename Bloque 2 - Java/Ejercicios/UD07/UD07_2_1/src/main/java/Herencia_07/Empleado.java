package Herencia_07;

public class Empleado
{
  String nombre;
  float sueldo;
  
  void insnom()
  {
    System.out.println("\nNOMBRE: ");
    nombre = Leer.dato();
  }
  
  void inssueldo()
  {
    System.out.println("\nSUELDO:");
    sueldo = Leer.datoFloat();
  }
  
  void insdatemp()
  {
    insnom();
    inssueldo();
  }
  
  void visnom()
  {
    System.out.println("\nNOMBRE: " + nombre);
  }
  
  void vissueldo()
  {
    System.out.println("\nSUELDO: " + sueldo);
  }
  
  void visdatemp()
  {
    visnom();
    vissueldo();
  }
}