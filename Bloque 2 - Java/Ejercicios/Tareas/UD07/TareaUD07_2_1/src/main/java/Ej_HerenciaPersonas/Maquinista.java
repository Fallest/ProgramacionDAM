package Ej_HerenciaPersonas;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Maquinista extends Persona {
    // Atributos
    private int numMaquina;
    private int numAños;
    
    // Constructor
    Maquinista() {
        // Al principio se va a llamar al constructor de persona, de forma implícita.
        setNumMaquina();
        setNumAños();
    }
    
    // Setters
    public void setNumMaquina() {
        boolean ejec;
        InputStreamReader stream = new InputStreamReader(System.in);
        BufferedReader teclado = new BufferedReader(stream);
        
        do {
            try {
                ejec = false;
                System.out.println("\nIntroduzca el número de máquina del maquinista: ");
                this.numMaquina = Integer.parseInt(teclado.readLine());
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
    
    public void setNumAños() {
        boolean ejec;
        InputStreamReader stream = new InputStreamReader(System.in);
        BufferedReader teclado = new BufferedReader(stream);
        
        do {
            try {
                ejec = false;
                System.out.println("\nIntroduzca el número de años trabajados en esa máquina: ");
                this.numAños = Integer.parseInt(teclado.readLine());
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
    public int getNumMaquina() {
        return this.numMaquina;
    }
    
    public int getNumAños() {
        return this.numAños;
    }
    
    // Utilidades
    public void mostrarDatos() {
        System.out.println("\nTipo de persona: Maquinista");
        super.mostrarDatos();
        System.out.println("\tNúmero de máquina: " + this.numMaquina);
        System.out.println("\tAños trabajando en esa máquina: " + this.numAños);
    }
}
