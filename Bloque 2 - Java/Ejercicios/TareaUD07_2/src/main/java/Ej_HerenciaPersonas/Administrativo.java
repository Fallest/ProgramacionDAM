package Ej_HerenciaPersonas;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Administrativo extends Persona {
    // Atributos
    private String estudios;
    private int numOrdenador;
    
    // Constructor
    Administrativo() {
        // Al principio se va a llamar al constructor de persona, de forma implícita.
        setEstudios();
        setNumOrd();
    }
    
    // Setters
    public void setEstudios() {
        boolean ejec;
        InputStreamReader stream = new InputStreamReader(System.in);
        BufferedReader teclado = new BufferedReader(stream);
        
        do {
            try {
                ejec = false;
                System.out.println("\nIntroduzca el nivel de estudio del administrador \n(ESO, Bachillerato, Grado universitario...): ");
                this.estudios = teclado.readLine();
            }
            catch (IOException e) {
                System.out.println("\n\tError en la entrada de datos\n");
                ejec = true;
            }
        } while (ejec);
    }
    
    public void setNumOrd() {
        boolean ejec;
        InputStreamReader stream = new InputStreamReader(System.in);
        BufferedReader teclado = new BufferedReader(stream);
        
        do {
            try {
                ejec = false;
                System.out.println("\nIntroduzca el número del ordenador asignado: ");
                this.numOrdenador = Integer.parseInt(teclado.readLine());
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
    public String getEstudios() {
        return this.estudios;
    }
    
    public int getNumOrd() {
        return this.numOrdenador;
    }
    
    // Utilidades
    public void mostrarDatos() {
        System.out.println("\nTipo de persona: Administrativo");
        super.mostrarDatos();
        System.out.println("\tEstudios: " + this.estudios);
        System.out.println("\tNúmero de ordenador: " + this.numOrdenador);
    }
}
