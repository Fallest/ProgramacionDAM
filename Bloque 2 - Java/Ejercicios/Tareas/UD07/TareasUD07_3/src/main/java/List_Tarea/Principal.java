package List_Tarea;

import java.util.*;

public class Principal {
    public static void main(String[] args) {
        Collection col = new ArrayList();
        boolean ejec;
        
        introducirNombre(col);
        do {
            ejec = preguntar();
            
            if (!ejec)
                break;
            
            introducirNombre(col);
        } while(ejec);
        System.out.println(col.size());
        System.out.println("Orden en el que se insertaron: ");
        mostrarCol(col);
        System.out.println("Orden inverso: ");
        mostrarCol(col, 1);
    }

    private static boolean preguntar() {
        boolean res = false, ejec;
        String cad;
        
        do {
            ejec = false;
            System.out.println("¿Quieres introducir un nombre? (s/n)");
            cad = Leer.dato();
            
            if (!cad.equals("s") && !cad.equals("n")) {
                System.out.println("Introduzca una respuesta válida."); 
                ejec = true;
            }
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
        // Método con polimorfismo: Si tiene un número en los parámetros,
        // muestra los datos al revés.

        Iterator iter = col.iterator();
        int cont = 0;
        
        while (iter.hasNext()) {
            System.out.println("Elemento " + cont + ": " + (String)iter.next());
            cont++;
        }
    }
    
    private static void mostrarCol(Collection col, int num) {
        // Método con polimorfismo: Si tiene un número en los parámetros,
        // muestra los datos al revés.
        
        ArrayList auxList = (ArrayList) col;
        int cont = col.size() - 1;
        
        while (cont >= 0) {
            System.out.println("Elemento " + cont + ": " + (String)auxList.get(cont));
            cont--;
        }
    }
}