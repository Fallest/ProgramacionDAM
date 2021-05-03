class Principal
{

  public static void main(String[] args)
  {
    Collection colec = new ArrayList(); // Collection es una interfaz, no se puede instanciar. Usamos una de las clases que heredan.
  
    colec.add(new Integer(25));  // O bien colec.add(25);
    colec.add(new Integer(63));
    colec.add(new Integer(25));
    colec.add(new Integer(23));
    Integer ent;
    Iterator iterador = colec.iterator();
    while(iterador.hasNext())
    {
      ent=(Integer)iterador.next();
	  System.out.println("El dato obtenido de la coleccion es " + ent);
    }
  }

}