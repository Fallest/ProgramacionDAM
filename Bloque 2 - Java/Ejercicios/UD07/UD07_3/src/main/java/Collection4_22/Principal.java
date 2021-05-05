package Collection4_22;

import java.util.*;

class Principal
{

  public static void main(String[] args)
  {
    Collection colec = new ArrayList();
	String dato;
	colec.add("hola");
	colec.add("buenos dias");
	colec.add("buenas tardes");
	
	Iterator iter = colec.iterator();
	
	while(iter.hasNext())
	{
	  dato=(String)iter.next();
	  if(dato.charAt(0)=='b')
	    iter.remove();
	}
	
	System.out.println("\n\tLa lista ha quedado asi: ");
	iter = colec.iterator(); // Empieza de nuevo desde el principio.
	while(iter.hasNext())
	{
	  dato=(String)iter.next();
	  System.out.println("\n\tEl dato que hay es " + dato);
	}

  }

}