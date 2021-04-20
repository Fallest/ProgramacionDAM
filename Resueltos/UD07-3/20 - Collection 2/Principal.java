class Principal
{

  public static void main(String[] args)
  {
    Collection colec = new LinkedList();
	boolean preg;
	
	Hijo obj = new Hijo("Gustavo", 35);
	
	colec.add(new Hijo("Lara", 32));
	colec.add(new Hijo("Ivan", 32));
	colec.add(new Hijo("Vanesa", 27));
	colec.add(new Hijo("Noelia", 26));
	colec.add(obj);
	
	preg = colec.contains(obj);  // Devolveria true
	                             // Si obj tuviese ("Lara", 32) y no se hiciese add con el, devolveria false porque cada objeto tiene un codigo distinto.
	System.out.println("El resultado de la comparacion es: " + preg);
  }

}