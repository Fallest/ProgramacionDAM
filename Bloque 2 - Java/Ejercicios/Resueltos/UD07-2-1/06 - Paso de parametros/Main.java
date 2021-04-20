public class Main
{
  public Main()
  {
        Persona pers1, pers2;
	float aumentoSueldo;
	
	System.out.println("\nVamos a pedir los datos de la persona 1.");
	pers1 = new Persona();
	System.out.println("\nVamos a pedir los datos de la persona 2.");
	pers2 = new Persona();
	
	System.out.println("\nVamos a visualizar los datos que se han insertado.");
	this.visuInformDosEmpleado(pers1, pers2);
	
	this.paradaContinuar();
	
	System.out.println("\nIndique el aumento de sueldo: ");
	aumentoSueldo = Leer.datoFloat();
	
	System.out.println("\nEl aumento de sueldo indicado es " + aumentoSueldo);
	
	this.paradaContinuar();
	
	aumentarSueldoMasMayor(pers1, pers2, aumentoSueldo);
	
	System.out.println("\nLos datos de las personas, una vez aumentado el sueldo a la persona mas mayor, son: ");
	this.visuInformDosEmpleado(pers1, pers2);
	
	this.paradaContinuar();
	
	/* Los datos que se han modificado en el metodo le han llegado al main */
	
	sumarleUnoAumentoSueldo(aumentoSueldo);
	System.out.println("\nEl aumento de sueldo indicado (una vez sumado uno) es " + aumentoSueldo);
	
	this.paradaContinuar();
	
	/* Se ha cambiado el valor de la variable en el metodo pero ese cambio no le ha llegado al main */
	
	System.out.println("\nVamos a intercambiar los datos de la persona 1 con los de la persona 2, dentro del metodo.");
	intercambioPersonas(pers1, pers2);
	System.out.println("\nLos datos intercambiados (visualizados en el main) son: ");
	this.visuInformDosEmpleado(pers1, pers2);
	
	this.paradaContinuar();
	
	/* El intercambio no ha llegado al main. */
	/* Esto es debido a que dentro de un metodo podemos cambiar los datos que hay en la referencia que se envia pero, si
	   cambiamos dicha referencia, la referencia nueva no le llega al metodo que ha llamado a dicha funcion. */
  }
  
  void paradaContinuar()
  {
    System.out.println("\nPulse una tecla para continuar.");
    Leer.dato();
  }
  
  void visuInformDosEmpleado(Persona pers1, Persona pers2)
  {
    System.out.println("\nLos datos de la persona 1 son: ");
    pers1.visualizarDatos();
    System.out.println("\nLos datos de la persona 2 son: ");
    pers2.visualizarDatos();
  }
  
  void intercambioPersonas (Persona pers1, Persona pers2)
  {
        Persona aux;
	
	System.out.println("\nLos datos antes del intercambio, dentro de la funcion, son: ");
	this.visuInformDosEmpleado(pers1, pers2);
	
	this.paradaContinuar();
	
	aux = pers1;
	pers1 = pers2;
	pers2 = aux;
	
	System.out.println("\nLos datos despues del intercambio, dentro de la funcion, son: ");
	this.visuInformDosEmpleado(pers1, pers2);
	
	this.paradaContinuar();
  }

  public static void main(String args[])
  {
    new Main();
  }
  
  void sumarleUnoAumentoSueldo(float aumentoSueldo)
  {
    aumentoSueldo++;
  }
  
  void aumentarSueldoMasMayor (Persona pers1, Persona pers2, float aumentoSueldo)
  {
    if (pers1.getEdad() > pers2.getEdad())
	  pers1.aumentoSueldo(aumentoSueldo);
	else
	  if (pers1.getEdad() < pers2.getEdad())
	    pers2.aumentoSueldo(aumentoSueldo);
	  else
	  {
	    pers1.aumentoSueldo(aumentoSueldo);
		pers2.aumentoSueldo(aumentoSueldo);
	  }
  }
}