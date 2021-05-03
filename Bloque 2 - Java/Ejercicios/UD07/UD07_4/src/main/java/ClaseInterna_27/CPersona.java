public class CPersona
{
  private String nombre;
  private CFecha fechaNacimiento;
  
  private class CFecha
  {
    private int dia, mes, anio;
	
	private CFecha(int dd, int mm, int aa)
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
  
  public CPersona()
  {
  }
  
  public CPersona(String nom, int dd, int mm, int aa)
  {
    nombre = nom;
	fechaNacimiento = new CFecha(dd, mm, aa);
  }
  
  public String obtenerNombre()
  {
    return nombre;
  }
  
  public String obtenerFechaNa()
  {
    return fechaNacimiento.obtenerFecha();
  }
}