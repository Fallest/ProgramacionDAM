public class CPersona2
{
  private String nombre;
  private CFecha fechaNacimiento;
  
  public CPersona2()
  {
  }
  
  public CPersona2(String nom, int dd, int mm, int aa)
  {
    nombre = nom;
	fechaNacimiento = new CFecha(dd, mm, aa)
	{
	  public String obtenerFecha()
	  {
	    return "nacio el dia " + dia + " del mes " + mes + " de " + anio;
	  }
	};
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