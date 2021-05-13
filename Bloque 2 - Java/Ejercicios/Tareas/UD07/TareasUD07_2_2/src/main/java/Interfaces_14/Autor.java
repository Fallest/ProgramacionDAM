package Interfaces_14;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Autor {
    // Atributos
    private String nombre;
    private String apellidos;
    
    Autor() {
        setNombre();
        setApellidos();
    }

    private void setNombre() {
        boolean ejec;
        
        InputStreamReader stream = new InputStreamReader(System.in);
        BufferedReader teclado = new BufferedReader(stream);
        
        do {
            try {
                ejec = false;

                System.out.println("\n\tIntroduzca el nombre del autor:");
                this.nombre = teclado.readLine();
            }
            catch (IOException e) {
                System.out.println("\n\tError en la entrada de datos.");
                ejec = true;
            }
        } while (ejec);
    }

    private void setApellidos() {
        boolean ejec;
        
        InputStreamReader stream = new InputStreamReader(System.in);
        BufferedReader teclado = new BufferedReader(stream);
        
        do {
            try {
                ejec = false;

                System.out.println("\n\tIntroduzca los apellidos del autor:");
                this.apellidos = teclado.readLine();
            }
            catch (IOException e) {
                System.out.println("\n\tError en la entrada de datos.");
                ejec = true;
            }
        } while (ejec);
    }

    public String toString() {
        return "Autor: " + this.nombre + ", " + this.apellidos;
    }
}
