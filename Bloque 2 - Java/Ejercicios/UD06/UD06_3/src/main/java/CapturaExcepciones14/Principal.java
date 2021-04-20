package CapturaExcepciones14;

import java.io.*;

class Principal
{
    /*
  public static void main(String args[]) throws IOException
  {
    int dividendo, divisor, cociente;
    String cadDividendo, cadDivisor;

    InputStreamReader via = new InputStreamReader(System.in);
    BufferedReader teclado = new BufferedReader(via);

    System.out.println("\n\n\tInserta el dividendo de la division: ");
    cadDividendo = teclado.readLine();
    dividendo = Integer.parseInt(cadDividendo);

    System.out.println("\n\n\tInserta el divisor de la division: ");
    cadDivisor = teclado.readLine();
    divisor = Integer.parseInt(cadDivisor);

    cociente = dividendo / divisor;

    System.out.println("\n\nEl resultado de dividir " + dividendo + " entre " + divisor + " da " + cociente);
  }
*/

    public static void main(String args[])
    {
        int cont = 1;
            while ((cont > 0) && (cont <= 5))
            {    
                try
                {
                    calcularDivision();
                    cont--;
                }
                catch(NumberFormatException e)
                {
                    System.out.println("\n\nHas insertado letras en vez de numeros, por lo que la division no se va a realizar.");
                    cont--;
                }
                catch(ArithmeticException e)
                {
                    System.out.println("\n\nHas insertado un 0 como divisor, por lo que la division no se va a realizar.");
                    cont++;
                }
                catch(Exception e)
                {
                     System.out.println("\n\nSe ha producido algun error, por lo que la division no se va a realizar.");
                     cont--;
                }
            }
    }
    
    static void calcularDivision() throws IOException 
    {
        int dividendo, divisor, cociente, resto;
        String cadDividendo, cadDivisor;

        InputStreamReader via = new InputStreamReader(System.in);
        BufferedReader teclado = new BufferedReader(via);
        
        System.out.println("\n\n\tInserta el dividendo de la division: ");
        cadDividendo = teclado.readLine();
        dividendo = Integer.parseInt(cadDividendo);

        System.out.println("\n\n\tInserta el divisor de la division: ");
        cadDivisor = teclado.readLine();
        divisor = Integer.parseInt(cadDivisor);

        cociente = dividendo / divisor;
        resto = dividendo - (divisor * cociente);

        System.out.println("\n\nEl resultado de dividir " + dividendo + " entre " + divisor + " da " + cociente);
        System.out.println("\n\nEl resto de la división es: " + resto);
    }
} 
