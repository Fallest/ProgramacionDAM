public class Mamifero extends Animal
{
  public int numhuesos;
  public int numextremidades;
  
  public Mamifero()
  {
    System.out.println(", mamifero");
  }
  
  public void insertardatosMami()
  {
    insertar_datos();
    System.out.println("\nNumero de huesos: ");
    numhuesos = Leer.datoInt();
    System.out.println("\nNumero de extremidades: ");
    numextremidades = Leer.datoInt();
  }
  
  public void visdatosMami()
  {
    visdatosAnim();
    System.out.println("\nHuesos: " + numhuesos);
    System.out.println("\nExtremidades: " + numextremidades);
  }
}