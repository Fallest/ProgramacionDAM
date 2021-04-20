package CPolinomio;

// Autor: David Bernal Navarrete

import java.util.*;

public class CPolinomio {
    // Coeficientes del polinomio
    private int x0, x1, x2, x3;
    
    /*Constructor*/
   CPolinomio (int x0, int x1, int x2, int x3)
   {
       this.x0 = x0;
       this.x1 = x1;
       this.x2 = x2;
       this.x3 = x3;
   }
   
   public int calcularValor(int x)
   {    
       int res;
       res = (x0 + (x1 * x) + (x2 * x * x) + (x3 * x * x * x));
       return res;
   }
    
    public String mostrarPoli()
    {
        String cadpoli = ("P(x) = " + this.x0 + " + " + this.x1 + "*x + " +
                this.x2 + "*(x^2) + " + this.x3 + "*(x^3)");
        return cadpoli;
    }
}
