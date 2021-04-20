public class Animal
{
  public int numcrias;
  
  public Animal()
  {
    System.out.println("\nHa nacido un animal.");
  }
  
  public void alimentarse()
  {
    System.out.println("\nHora de comer.");
  }
  
  public void insertar_datos()
  {
    System.out.println("\nNumero de crias: ");
    numcrias = Leer.datoInt();
  }
  
  public void visdatosAnim()
  {
    System.out.println("\nCrias: " + numcrias);
  }
}