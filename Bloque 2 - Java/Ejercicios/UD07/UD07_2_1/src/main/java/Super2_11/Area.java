public class Area extends Linea
{  
  private int alto;
  
  Area()
  {
    System.out.print("\nIndique cual es su altura: ");
    alto = Leer.datoInt();
  }
  
  void visArea()
  {
    System.out.println("\nUn rectangulo con estos datos: ");
	System.out.println("\nAnchura: " + getAncho());
	System.out.println("\nAltura: " + alto);
	System.out.println("\nOcupa un area de: " + getAncho()*alto);
  }
  
  Area (int altoEnv, int anchoEnv)
  {
    super(anchoEnv);
    alto = altoEnv;
  }
  
  int getAlto()
  {
    return alto;
  }
}