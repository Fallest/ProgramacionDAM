public class SuperClase
{
  int datoClase;
  
  public SuperClase(int datoEnv)
  {
    datoClase = datoEnv;
    System.out.println("\nHemos entrado en la funcion constructora de la superclase");
  }
  
  public void visualDatoSuperClase()
  {
    System.out.println("\nEl dato de la superclase es " + datoClase);
  }
}