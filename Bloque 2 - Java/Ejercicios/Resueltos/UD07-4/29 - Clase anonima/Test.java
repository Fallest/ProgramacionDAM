public class Test
{
  public static void main(String args[])
  {
    CPersona unaPersona = new CPersona("Un nombre", 22, 2, 2014);
	System.out.println(unaPersona.obtenerNombre());
	System.out.println(unaPersona.obtenerFechaNa());
  }
}