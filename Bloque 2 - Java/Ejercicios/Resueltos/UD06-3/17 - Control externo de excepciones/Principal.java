import java.io.*;

class Principal
{
  public static void main(String args[])
  {
    int num, suma = 0, cont = 0;
    boolean correcto = true;

    do{
      try
      {
        num = pedirNumeroEntero();
        suma = num + suma;
        cont++;
      }
      catch(NumberFormatException e)
      {
        System.out.println("\n\nHemos insertado letras en vez de numeros.");
        correcto = false;
      }
      catch(IOException e)
      {
        System.out.println("\n\nHa habido un error en la entrada de datos. Salimos del programa.");
        System.exit(0);
      }
    }while(correcto == true);

    if (cont == 0)
      System.out.println("\n\nNo se visualiza la suma ya que no se ha insertado nungun numero valido.");
    else
      System.out.println("\n\nLa suma de los numeros insertados es " + suma);

    System.out.println("\n\nFIN DEL PROGRAMA");
  }


  static String pedirCadena() throws IOException
  {
    String cadena="";

    InputStreamReader via = new InputStreamReader(System.in);
    BufferedReader teclado = new BufferedReader(via);

    cadena = teclado.readLine();
    return cadena;
  }


  static int pedirNumeroEntero() throws IOException
  {
    String cadena;
    int num = 0;

    System.out.println("\n\nInserta un numero: ");
    cadena = pedirCadena();
    try
    {
      num = Integer.parseInt(cadena);
    }
    catch(NumberFormatException e)
    {
      System.out.println("\n\nSe han insertado letras en vez de numeros.");
      throw e;
    }

    return num;
  }
} 