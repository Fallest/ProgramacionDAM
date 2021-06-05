package CRacional;

// Autor: David Bernal Navarrete

import java.io.*;

public class CRacional {

    private int nominador, denominador;
    
    /*------------------------------------------------------*/
    /*Constructores*/
    CRacional (int nom, int den)
    {
        this.nominador = nom;
        this.denominador = den;
    }
     
    CRacional()
    {
        setNominador();
        setDenominador();
    }
    
    /*------------------------------------------------------*/
    /*Funcionalidades*/
    public void mostrarFraccion()
    {
        double res = (double) this.getNominador() / this.getDenominador();
        System.out.println(this.getNominador() + " / " + this.getDenominador());
        System.out.println("\nEquivale aproximadamente a: \t" + res);
    }
    
    public String getFraccionCadena()
    {
        String cadaux = "";
        cadaux = this.getNominador()+ "/" + this.getDenominador();
        
        return cadaux;
    }
    
    public CRacional suma(CRacional frac1, CRacional frac2)
    {
        CRacional fracRes;
        int nom, den;
        
        nom = (int) (frac1.getNominador() * frac2.getDenominador()) + 
                (frac2.getNominador() * frac1.getDenominador());
        den = (int) frac1.getDenominador() * frac2.getDenominador();
        
        fracRes = new CRacional(nom, den);
        
        System.out.println("Suma entre " + frac1.getFraccionCadena() + " y " +
                frac2.getFraccionCadena());
        System.out.println("Resultado: " + fracRes.getFraccionCadena());
        
        return fracRes;
    }
    
    public CRacional resta(CRacional frac1, CRacional frac2)
    {
        CRacional fracRes;
        int nom, den;
        
        nom = (int) (frac1.getNominador() * frac2.getDenominador()) - 
                (frac2.getNominador() * frac1.getDenominador());
        den = (int) frac1.getDenominador() * frac2.getDenominador();
        
        fracRes = new CRacional(nom, den);
        
        System.out.println("Resta entre " + frac1.getFraccionCadena() + " y " +
                frac2.getFraccionCadena());
        System.out.println("Resultado: " + fracRes.getFraccionCadena());
        
        return fracRes;
    }
    
    public CRacional multiplicar(CRacional frac1, CRacional frac2)
    {
        CRacional fracRes;
        int nom, den;
        
        nom = frac1.getNominador() * frac2.getNominador();
        den = frac1.getDenominador() * frac2.getDenominador();
        
        fracRes = new CRacional (nom, den);
        
        System.out.println("Multiplicación entre " + frac1.getFraccionCadena() +
                " y " + frac2.getFraccionCadena());
        System.out.println("Resultado: " + fracRes.getFraccionCadena());
        
        return fracRes;
    }
    
    public CRacional dividir(CRacional frac1, CRacional frac2)
    {
        CRacional fracRes;
        int nom, den;
        
        nom = frac1.getNominador() * frac2.getDenominador();
        den = frac1.getDenominador() * frac2.getNominador();
        
        fracRes = new CRacional (nom, den);
        
        System.out.println("División entre " + frac1.getFraccionCadena() +
                " y " + frac2.getFraccionCadena());
        System.out.println("Resultado: " + fracRes.getFraccionCadena());
        
        return fracRes;
    }
    
    /*------------------------------------------------------*/
    /*Setters*/
    public void setNominador(int nom)
    {
        this.nominador = nom;
    }
    
    public void setDenominador(int den)
    {
        this.denominador = den;
    }
    
    public void setNominador()
    {
        String cadaux = "";
        boolean correctio = false;
        InputStreamReader stream = new InputStreamReader(System.in);
        BufferedReader teclado = new BufferedReader(stream);
        
        do
        {
            try 
            {
                System.out.println("\nIntroduzca el nominador: ");
                cadaux = teclado.readLine();
                nominador = Integer.parseInt(cadaux);
                correctio = true;
            }
            catch (NumberFormatException e)
            {
                System.out.println("Se ha introducido una letra.");
            }
            catch (IOException e)
            {
                System.out.println("Ha ocurrido un error. Saliendo del programa.");
                System.exit(0);
            }
        } while (!correctio);
    }
    
    public void setDenominador()
    {
        String cadaux = "";
        boolean correctio = false;
        InputStreamReader stream = new InputStreamReader(System.in);
        BufferedReader teclado = new BufferedReader(stream);
        
        do
        {
            try 
            {
                System.out.println("\nIntroduzca el denominador: ");
                cadaux = teclado.readLine();
                denominador = Integer.parseInt(cadaux);
                correctio = true;
            }
            catch (NumberFormatException e)
            {
                System.out.println("Se ha introducido una letra.");
            }
            catch (IOException e)
            {
                System.out.println("Ha ocurrido un error. Saliendo del programa.");
                System.exit(0);
            }
        } while (!correctio);
    }
    
    /*------------------------------------------------------*/
    /*Getters*/
    public int getNominador()
    {
        return this.nominador;
    }
    
    public int getDenominador()
    {
        return this.denominador;
    }
}
