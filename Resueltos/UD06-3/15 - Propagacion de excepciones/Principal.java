import java.io.*;

class Principal
{
  public static void main(String args[])
  {
    int num1;

    System.out.println("\n\nInserta un numero: ");

    try
    {
      num1 = pedirEntero();
      System.out.println("\n\nEl numero insertado es " + num1);
    }
    catch(NumberFormatException e)
    {
      System.out.println("\n\nSe han insertado letras en vez de un numero. MENSAJE QUE VISUALIZA EL MAIN.");
    }
  }


  static String pedirCadena()
  {
    String cadena="";

    InputStreamReader via = new InputStreamReader(System.in);
    BufferedReader teclado = new BufferedReader(via);

    try
    {
      cadena = teclado.readLine();
    }
    catch(IOException e)
    {
      System.out.println("\n\nHa ocurrido un error y el programa se va a cerrar.");
      System.exit(0);
    }

    return cadena;
  }


  static int pedirEntero()
  {
    String cadena;
    int num = 0;

    cadena = pedirCadena();
    num = Integer.parseInt(cadena);

    return num;
  }

/*
  static int pedirEntero()
  {
    String cadena;
    int num = 0;

    cadena = pedirCadena();

    try
    {
      num = Integer.parseInt(cadena);
    }
    catch(NumberFormatException e)
    {
      System.out.println("\n\nSe han insertado letras en vez de un numero. MENSAJE QUE VISUALIZA EL METODO PEDIRENTERO.");
    }

    return num;
  }
*/
} 
