package Ej_HerenciaEquipo;

import java.io.IOException;

public class Empresa {
    // Atributos
    private String cif;
    private String razon_social;
    private String ciudad;
    private static String pais = "España";
    
    // Constructor
    Empresa() {
        setCif();
        setRazSocial();
        setCiudad();
    }
    
    // Setters
    void setCif() {
        System.out.println("Introduzca el CIF de la empresa: ");
        this.cif = Leer.dato();
    }
    
    void setRazSocial() {
        System.out.println("Introduzca la razón social de la empresa: ");
        this.razon_social = Leer.dato();
    }
    
    void setCiudad() {
        System.out.println("Introduzca la ciudad de la empresa: ");
        this.ciudad = Leer.dato();   
    }
    
    // Getters
    String getCif() 
    {return this.cif;}
    
    String getRazSocial()
    {return this.razon_social;}
    
    String getCiudad() 
    {return this.ciudad;}
    
    String getPais() 
    {return this.pais;}
    
    // Utilidades
    public void mostrarDatos() {
        System.out.println("\tCif: " + this.cif);
        System.out.println("\tRazón social: " + this.razon_social);
        System.out.println("\tCiudad: " + this.ciudad);
        System.out.println("\tPaís: " + this.pais);
    }
}
