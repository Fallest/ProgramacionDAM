public class Principal
{
  public static void main(String args[])
  {
        int anchoPrin, altoPrin, grosorPrin;
	
	System.out.println("\nVamos a visualizar el espacio que ocupa una linea: ");
	Linea lin1 = new Linea();
	lin1.visLinea();
	
	System.out.println("\nVamos a visualizar el espacio que ocupa un rectangulo: ");
	Area rect1 = new Area();
	rect1.visArea();
	
	System.out.println("\nVamos a visualizar el espacio que ocupa una caja: ");
	AreaPoli caja1 = new AreaPoli();
	caja1.visAreaPoli();
	
	System.out.println("\nVamos a pedir la anchura, la altura y el grosor de una caja.");
	System.out.println("\nVamos a ver lo que ocupa una linea (de esa caja), el area de una de sus caras y el espacio que ocupa la caja.");
	
	System.out.println("\nIndique la anchura de una cara de la caja: ");
	anchoPrin = Leer.datoInt();
	System.out.println("\nIndique la altura de esa cara de la caja: ");
	altoPrin = Leer.datoInt();
	System.out.println("\nIndique el grosor de la caja: ");
	grosorPrin = Leer.datoInt();
	
	AreaPoli caja2 = new AreaPoli(anchoPrin, altoPrin, grosorPrin);
	
	caja2.visLinea();
	caja2.visArea();
	caja2.visAreaPoli();
  }
}