public class Linea
{  
  private int ancho;
  
  Linea()
  {
    System.out.print("\nIndique cual es su anchura: ");
    ancho = Leer.datoInt();
  }
  
  void visLinea()
  {
    System.out.println("\nLa linea tiene una anchura de " + ancho);
  }
  
  Linea (int anEnv)
  {
    ancho = anEnv;
  }
  
  int getAncho()
  {
    return ancho;
  }
}