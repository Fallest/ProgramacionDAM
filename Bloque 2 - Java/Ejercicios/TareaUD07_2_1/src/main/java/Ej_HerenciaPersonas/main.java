package Ej_HerenciaPersonas;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class main {
    public static void main(String[] args) {
        // Variables
        int cantMaquinistas, cantAdministrativos, cantPersonas;
        Persona p[];
        Maquinista m[];
        Administrativo a[];
        
        // Preguntar al usuario cuántas personas hay de cada tipo
        cantMaquinistas = pedirCantMaquinistas();
        cantAdministrativos = peditCantAdministrativos();
        cantPersonas = pedirCantPersonas();
        
        // Establecer el sueldo para todos
        Persona.setSueldo();
        
        p = new Persona[cantPersonas];
        m = new Maquinista[cantMaquinistas];
        a = new Administrativo[cantAdministrativos];
        
        introducirDatos(p, 'p');
        introducirDatos(m, 'm');
        introducirDatos(a, 'a');
        
        mostrarDatos(p);
        mostrarDatos(m);
        mostrarDatos(a);
        
        calcMedia(p);
        calcMedia(m);
        calcMedia(a);
    }

    private static int pedirCantMaquinistas() {
        int cantMaquinistas = 0;
        
        boolean ejec;
        InputStreamReader stream = new InputStreamReader(System.in);
        BufferedReader teclado = new BufferedReader(stream);
        
        do {
            try {
                ejec = false;
                System.out.println("\nIntroduzca la cantidad de maquinistas: ");
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
        int cantAdministrativos = 0;
        
        boolean ejec;
        InputStreamReader stream = new InputStreamReader(System.in);
        BufferedReader teclado = new BufferedReader(stream);
        
        do {
            try {
                ejec = false;
                System.out.println("\nIntroduzca la cantidad de administrativos: ");
                cantAdministrativos = Integer.parseInt(teclado.readLine());
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
        
        return cantAdministrativos;
    }

    private static int pedirCantPersonas() {
        int cantPersonas = 0;
        
        boolean ejec;
        InputStreamReader stream = new InputStreamReader(System.in);
        BufferedReader teclado = new BufferedReader(stream);
        
        do {
            try {
                ejec = false;
                System.out.println("\nIntroduzca la cantidad de personas que no son \nmaquinistas ni administrativos: : ");
                cantPersonas = Integer.parseInt(teclado.readLine());
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
        
        return cantPersonas;
    }
    
    private static void introducirDatos(Persona p[], char tipo) {
        int i;
        
        if (tipo == 'a') {
            for (i = 0; i < p.length; i++) {
                System.out.println("Administrativo/a " + (i+1));
                p[i] = new Administrativo();
            }
        }
        else if (tipo == 'm') {
            for (i = 0; i < p.length; i++) {
                System.out.println("Maquinista " + (i+1));
                p[i] = new Maquinista();
            }
        }
        else if (tipo == 'p') {
            for (i = 0; i < p.length; i++) {
                System.out.println("Persona " + (i+1));
                p[i] = new Persona();
            }
        }
    }

    private static void mostrarDatos(Persona p[]) {
        int i;
        
        for (i = 0; i < p.length; i++)
            if (p[i] != null)
                p[i].mostrarDatos();
    }
    
    private static void calcMedia(Persona p[]) {
        int i, suma = 0, cont = 0;
        float media;
        
        System.out.println("\n");
        
        if (p[0] instanceof Administrativo) {
            for (i = 0; i < p.length; i++) {
                suma += p[i].getEdad();
                cont ++;
            }
            media = (float) suma / cont;
            System.out.println("Media de edad de administrativos: " + media);
        }
        
        else if (p[0] instanceof Maquinista) {
            for (i = 0; i < p.length; i++) {
                suma += p[i].getEdad();
                cont ++;
            }
            media = (float) suma / cont;
            System.out.println("Media de edad de maquinistas: " + media);
        }
        
        else if (p[0] instanceof Persona) {
            for (i = 0; i < p.length; i++) {
                suma += p[i].getEdad();
                cont ++;
            }
            media = (float) suma / cont;
            System.out.println("Media de edad de personas: " + media);
        }
    }
}
