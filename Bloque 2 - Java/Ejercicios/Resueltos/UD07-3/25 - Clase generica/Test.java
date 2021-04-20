public class Test
{
  public static void visualizarVector(CVector<Double> v)
  {
    int ne = v.longitud();
	for (int i = 0; i < ne; i++)
	  System.out.println(v.valorEn(i) + " ");
	System.out.println();
  }
  
  public static void main(String[] args)
  {
    Double x[] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0};
	CVector<Double> vector1 = new CVector<Double>(x);
	
	visualizarVector(vector1);
	
	CVector<Double> vector2 = new CVector<Double>(vector1);
	for (int i = 0; i < vector2.longitud(); i++)
	{
	  vector2.ponerValorEn(i, vector2.valorEn(i)*10.0);
	}
	visualizarVector(vector2);
  }
}