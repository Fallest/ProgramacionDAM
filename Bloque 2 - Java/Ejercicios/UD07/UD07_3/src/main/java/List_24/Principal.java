class Principal
{

  public static void main(String[] args)
  {
    ArrayList colec = new ArrayList();
	
	colec.add(3);
	colec.add(3.5);
	colec.add(1,"hola");
	colec.add(45);
	
	System.out.println("\n\nVamos a visualizar la coleccion: ");
	visualCollection(colec);
	
	colec.set(2,'b');
	colec.remove(3);
	
	System.out.println("\n\nVamos a visualizar la coleccion: ");
	visualCollection(colec);
	
	colec.remove(new Integer(3));  // No es lo mismo que remove(3), que seria borrar el objeto que esta en la posicion 3.
	
	System.out.println("\n\nVamos a visualizar la coleccion: ");
	visualCollection(colec);
  }
  
  static void visualCollection(List co)
  {
    ListIterator iter;
	iter = co.listIterator();
	String m;
	
	while(iter.hasNext())
	{
	  System.out.println("\n\tEl siguiente valor de la coleccion: ");
	  System.out.println("\n\tEsta en la posicion " + iter.nextIndex());
	  m = String.valueOf(iter.next());
	  System.out.println("\n\tEl valor que contiene es: " + m);
	}
  }

}