public class Test
{
  public static void main(String[] args)
  {
    meses mes = meses.marzo;
	// ...
	int ind = mes.ordinal();  // indice: 0, 1, 2, ...
	System.out.println("El mes " + (ind + 1) + " es " + mes.values()[ind]);
	System.out.println(mes + " tiene " + mes.DiasMes() + " dias");
	// ...
  }
}