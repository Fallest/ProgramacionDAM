public class Persona extends Mamifero
{
  public String profesion;
  
  public Persona()
  {
    System.out.println(" y persona");
  }
  
  public void insertardatosPers()
  {
    insertardatosMami();
    System.out.println("\nProfesion: ");
    profesion = Leer.dato();
  }
  
  public void visdatosPers()
  {
    visdatosMami();
    System.out.println("\nProfesion: " + profesion);
  }
}