package Ej_HerenciaPersonas;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Persona {
    // Atributos
    protected String nombre;
    protected static int sueldo;
    protected int edad;
    
    // Constructor
    Persona() {
        setNombre();
        setEdad();
    }
    
    // Setters
    public void setNombre() {
        boolean ejec;
        InputStreamReader stream = new InputStreamReader(System.in);
        BufferedReader teclado = new BufferedReader(stream);
        
        do {
            try {
                ejec = false;
                System.out.println("\nIntroduzca el nombre de la persona: ");
                this.nombre = teclado.readLine();
            }
            catch (IOException e) {
                System.out.println("\n\tError en la entrada de datos\n");
                ejec = true;
            }
        } while (ejec);
    }
    
    public void setSueldo() {
        boolean ejec;
        InputStreamReader stream = new InputStreamReader(System.in);
        BufferedReader teclado = new BufferedReader(stream);
        
        do {
            try {
                ejec = false;
                System.out.println("\nIntroduzca el sueldo para todas las personas: ");
                Persona.sueldo = Integer.parseInt(teclado.readLine());
            }
            catch (IOException e) {
                System.out.println("\n\tError en la entrada de datos\n");
                ejec = true;
            }
        } while (ejec);
    }
    
    public void setEdad() {
        boolean ejec;
        InputStreamReader stream = new InputStreamReader(System.in);
        BufferedReader teclado = new BufferedReader(stream);
        
        do {
            try {
                ejec = false;
                System.out.println("\nIntroduzca la edad de la persona: ");
                this.edad = Integer.parseInt(teclado.readLine());
            }
            catch (IOException e) {
                System.out.println("\n\tError en la entrada de datos\n");
                ejec = true;
            }
            catch (NumberFormatException e) {
                System.out.println("\n\tError: Introduzca un número válido.\n");
                ejec = true;
            }
        } while (ejec);
    }
    
    // Getters
    public String getNombre() {
        return this.nombre;
    }
    
    public int getSueldo() {
        return Persona.sueldo;
    }
    public int getEdad() {
        return this.edad;
    }
    
    // Utilidades
    public void mostrarDatos() {
        System.out.println("\n\tNombre: " + this.nombre);
        System.out.println("\tEdad: " + this.edad);
        System.out.println("\tSueldo: " + Persona.sueldo);
    }
}
