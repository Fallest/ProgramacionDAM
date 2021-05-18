package ContenidoWeb_03;

import java.io.*;
import java.net.*;

public class test
{
  public static void main(String[] args) throws IOException
  {
    String cadena;
	boolean seguimos = true;
	URL direcc = new URL("http://www.iesmajuelo.com");
	InputStream is = direcc.openStream();
	BufferedReader entrada = new BufferedReader(new InputStreamReader(is));

	System.out.println("\n\nEsta es la informacion que contiene el fichero html de la pagina web del instituto.");
	cadena = entrada.readLine();
	while(cadena!=null)
	{
	  if(!cadena.equals("\n"));
	    System.out.println(cadena);
		
	  cadena = entrada.readLine();
	}
    System.out.println("\nFIN DEL PROGRAMA\n");
  }
}