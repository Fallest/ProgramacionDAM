public class AreaPoli extends Area
{  
  private int grosor;
  
  AreaPoli()
  {
    System.out.print("\nIndique cual es su grosor: ");
    grosor = Leer.datoInt();
  }
  
  void visAreaPoli()
  {
    System.out.println("\nUna caja con estos datos: ");
    System.out.println("\nAnchura: " + getAncho());
    System.out.println("\nAltura: " + getAlto());
    System.out.println("\nGrosor: " + grosor);
    System.out.println("\nOcupa un volumen de: " + getAncho()*getAlto()*grosor);
  }
  
  AreaPoli (int altoEnv, int anchoEnv, int grosorEnv)
  {
    super(altoEnv, anchoEnv);
    grosor = grosorEnv;
  }
  
  int getGrosor()
  {
    return grosor;
  }
}