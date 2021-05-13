package List_Tarea;

import java.util.*;

public class Principal {
    public static void main(String[] args) {
        String nombre, pregunta;
        Collection col = new ArrayList();
        boolean ejec = true;
        
        introducirNombre(col);
        do {
            ejec = preguntar();
            
            if (!ejec)
                break;
            
            introducirNombre(col);
        } while(ejec);
        
        mostrarCol(col);
        mostrarCol(col, 1);
    }

    private static boolean preguntar() {
        boolean res = false, ejec;
        String cad;
        
        do {
            ejec = false;
            System.out.println("¿Quieres introducir un nombre? (s/n)");
            cad = Leer.dato();

            if (cad.equals("n"))
                ejec = true;
            else if (!cad.equals("n") && !cad.equals("s"))
                System.out.println("Introduzca una respuesta válida."); ejec = true;
        } while(ejec);
        
        if (cad.equals("s"))
            res = true;
        
        return res;
    }

    private static void introducirNombre(Collection col) {
        String nom;
        
        System.out.println("Introduzca el nombre a introducir: ");
        nom = Leer.dato();
        
        col.add(nom);
    }

    private static void mostrarCol(Collection col) {
        
    }
    
    private static void mostrarCol(ArrayList col, int num) {
        // Método con polimorfismo: Si tiene un número en los parámetros,
        // muestra los datos al revés.
        Iterator iter = col.iterator();
        int cont = 0, tam = col.size();
        String aux;
        
        // Invertimos el array.
        while(tam > 0) {
            col.add(cont, iter.get(tam));
        }
        
        while (iter.hasNext()) {
            System.out.println("Elemento " + cont + ": " + (String)iter.next());
            cont++;
        }
    }
}