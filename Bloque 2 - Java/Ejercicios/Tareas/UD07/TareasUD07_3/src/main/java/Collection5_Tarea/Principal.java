package Collection5_Tarea;

import java.util.*;

public class Principal {
    
    public static void main(String[] args) {
        int edadElim;
        boolean ejec = true;
        Collection col1 = new ArrayList();
        
        // Insertar datos hasta que se detecte que se ha insertado un dato no
        // numérico como edad.
        do {
            try {
                insertarEmple(col1);
            }
            catch (NumberFormatException e) {
                ejec = false;
            }
        } while(ejec);
        
        System.out.println("Colección antes de borrar los empleados:");
        mostrarColec(col1);
        
        // Pedir la edad para borrar los empleados que tengan una edad menor.
        edadElim = pedirEdad();
        
        // Eliminar todos los empleados que tengan menor edad a la indicada.
        deleteEmple(col1, edadElim);
        
        System.out.println("Colección después de borrar los empleados:");
        mostrarColec(col1);
        
    }
    
    public static void insertarEmple(Collection col) {
        Empleado emple = new Empleado();
        col.add(emple);
    }
    
    public static int pedirEdad() {
        boolean ejec;
        int edad = 0;
        
        do {
            try {
                ejec = false;
                System.out.println("Introduzca una edad límite: ");
                edad = Leer.datoInt();
            }
            catch (NumberFormatException e) {
                ejec = true;
            }
        } while (ejec);
        
        return edad;
    }

    private static void deleteEmple(Collection col1, int edadElim) {
        Iterator iter = col1.iterator();
        Empleado empleAux; // Necesario para comprobar la edad.
        
        while (iter.hasNext()) {
            empleAux = (Empleado) iter.next(); // Casteo necesario, porque no le
                                               // decimos al programa que es un empleado
                                               // en ningún otro lado. Hay que aclarárselo.
            if (empleAux.getEdad() < edadElim)
                iter.remove(); // Tenemos que utilizar el remove del iterador
                                // porque estamos recorriendo la colección.
        }
    }
    
    private static void mostrarColec(Collection col) {
        Iterator iter = col.iterator();
        int cont = 0;
        
        while (iter.hasNext()) {
            System.out.println("Elemento " + cont + ": " + (Empleado)iter.next());
            cont++;
        }
        System.out.println("\n");
    }
}
