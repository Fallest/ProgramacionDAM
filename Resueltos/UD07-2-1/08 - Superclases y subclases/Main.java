public class Main
{
  public static void main(String args[])
  {
    int pos;
	
	Persona t[] = new Persona[3];	
	for (pos = 0; pos < 3; pos++)
	{
	  t[pos] = new Persona();
	}
	
	Mamifero ma[] = new Mamifero[2];
	for (pos = 0; pos < 2; pos++)
	{
	  ma[pos] = new Mamifero();
	}
	
	Animal a = new Animal();
	
	System.out.println("\nInsercion de los datos de las diferentes personas: \n");
	for (pos = 0; pos < 3; pos++)
	{
	  System.out.println("\nInserte los datos de la persona " + (pos+1) + ": \n");
	  t[pos].insertardatosPers();
	}
	
	System.out.println("\nInsercion de los datos de los diferentes mamiferos: \n");
	for (pos = 0; pos < 2; pos++)
	{
	  System.out.println("\nInserte los datos del mamifero " + (pos+1) + ": \n");
	  ma[pos].insertardatosMami();
	}
	
	System.out.println("\nInsercion de los datos del animal: \n");
	a.insertar_datos();
	
	System.out.println("\nVisualizacion de los datos de las diferentes personas: \n");
	for (pos = 0; pos < 3; pos++)
	{
	  System.out.println("\nPersona: " + (pos+1) + ": \n");
	  t[pos].visdatosPers();
	}
	
	System.out.println("\nVisualizacion de los datos de los diferentes mamiferos: \n");
	for (pos = 0; pos < 2; pos++)
	{
	  System.out.println("\nMamifero " + (pos+1) + ": \n");
	  ma[pos].visdatosMami();
	}
	
	System.out.println("\nVisualizacion de los datos del animal: \n");
	a.visdatosAnim();
	
	System.out.println("\nSe va a proceder a dar de comer a todas las personas: \n");
		for (pos = 0; pos < 3; pos++)
	{
	  System.out.println("\nPersona " + (pos+1) + ": \n");
	  t[pos].alimentarse();
	}
	
	System.out.println("\nSe va a proceder a dar de comer a todos los mamiferos: \n");
	for (pos = 0; pos < 2; pos++)
	{
	  System.out.println("\nMamifero " + (pos+1) + ": \n");
	  ma[pos].alimentarse();
	}
	
	System.out.println("\nSe va a proceder a dar de comer al restante animal: \n");
	a.alimentarse();
	
	System.out.println("\n\nFIN DEL PROCESO.");
  }
}