package CPolinomio;

// Autor: David Bernal Navarrete

import java.io.*;

public class main {
    public static void main (String args[])
    {
        boolean run = true;
        String cadaux = "";
        int x0, x1, x2, x3;
        
        do {
            try
            {
                InputStreamReader stream = new InputStreamReader(System.in);
                BufferedReader teclado = new BufferedReader(stream);
                
                System.out.println("\nIntroduzca los coeficientes en orden ascendente: ");
                System.out.println("\tTérmino independiente: ");
                cadaux = teclado.readLine();
                x0 = Integer.parseInt(cadaux);
                System.out.println("\tPrimer coeficiente: ");
                cadaux = teclado.readLine();
                x1 = Integer.parseInt(cadaux);
                System.out.println("\tSegundo coeficiente: ");
                cadaux = teclado.readLine();
                x2 = Integer.parseInt(cadaux);
                System.out.println("\tTercer coeficiente: ");
                cadaux = teclado.readLine();
                x3 = Integer.parseInt(cadaux);
                
                CPolinomio poli = new CPolinomio(x0, x1, x2, x3);
                
                realizarCalculo(poli);
                
                System.out.println("\n¿Quieres hacer cálculos con otro polinomio? (s/n)");
                cadaux = teclado.readLine();
                
                if(!("s".equals(cadaux)))
                    run = false;
            }
            catch(NumberFormatException e)
            {
                System.out.println("Has introducido caracteres.");
            }
            catch(IOException e)
            {
                System.out.println("Ha ocurrido un error grave. Saliendo del programa...");
                run = false;
            }
        } while(run);
    }
    
    public static void realizarCalculo(CPolinomio poli)
    {
        boolean ejecucion = true;
        InputStreamReader stream = new InputStreamReader(System.in);
        BufferedReader teclado = new BufferedReader(stream);
        String cadaux = "";
        int x;
        
        do {
            try
            {
                System.out.println("El polinomio es: " + poli.mostrarPoli());
                System.out.println("\n\tIntroduzca el valor de x: ");
                cadaux = teclado.readLine();
                x = Integer.parseInt(cadaux);
                System.out.println("\nEl valor de P(" + x + ") es: " + poli.calcularValor(x));
                
                System.out.println("\n\n¿Quieres probar otro valor para P(x) (s/n)?");
                cadaux = teclado.readLine();
                if (!("s".equals(cadaux)))
                    ejecucion = false;
            }
            catch (NumberFormatException e)
            {
                System.out.println("\tHas introducido una cadena en vez de un número.");
            }
            catch (IOException e)
            {
                System.out.println("\n\tHa ocurrido un error grave. Saliendo del programa.");
                System.exit(0);
            }
            
        } while(ejecucion);
    }
}
