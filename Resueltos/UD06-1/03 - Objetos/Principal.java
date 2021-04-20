package paquete;

public class Principal
{
  public static void main(String[] args)
  {
    Alumno alum1, alum2;
    alum1 = new Alumno();
    alum2 = new Alumno();
    alum1.inicialDatos("Maria Jesus", 58);
    alum2.inicialDatos("Angel", 62);
    alum1.visualDatos();
    alum2.visualDatos();
    alum1.modificarDatos();
  }
} 
