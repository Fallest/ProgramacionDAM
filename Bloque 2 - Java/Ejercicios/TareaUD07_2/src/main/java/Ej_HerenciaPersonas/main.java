package Ej_HerenciaPersonas;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class main {
    public static void main(String[] args) {
        // Variables
        int cantMaquinistas, cantAdministrativos, cantPersonas;
        
        // Preguntar al usuario cuántas personas hay de cada tipo
        cantMaquinistas = pedirCantMaquinistas();
        cantAdministrativos = peditCantAdministrativos();
        cantPersonas = pedirCantPersonas();
        
        
    }

    private static int pedirCantMaquinistas() {
        int cantMaquinistas;
        
        boolean ejec;
        InputStreamReader stream = new InputStreamReader(System.in);
        BufferedReader teclado = new BufferedReader(stream);
        
        do {
            try {
                ejec = false;
                System.out.println("\nIntroduzca el nivel de estudio del administrador \n(ESO, Bachillerato, Grado universitario...): ");
                cantMaquinistas = Integer.parseInt(teclado.readLine());
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
        
        return cantMaquinistas;
    }

    private static int peditCantAdministrativos() {
        int cantAdministrativos;
        
        
        return cantAdministrativos,
    }

    private static int pedirCantPersonas() {
        int cantPersonas;
        
        return cantPersonas;
    }
}
