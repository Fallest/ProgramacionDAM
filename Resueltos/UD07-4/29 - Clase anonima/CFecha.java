public class CFecha
{
  int dia, mes, anio;
  
  public CFecha(int dd, int mm, int aa)
  {
    dia = dd;
	mes = mm;
	anio = aa;
  }
  
  public String obtenerFecha()
  {
    return dia + "/" + mes + "/" + anio;
  }
}