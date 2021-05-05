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
        
        // Pedir la edad para borrar los empleados que tengan una edad menor.
        edadElim = pedirEdad();
        
        // Eliminar todos los empleados que tengan menor edad a la indicada.
        deleteEmple(col1, edadElim);
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
                edad = Leer.datoInt();
            }
            catch (NumberFormatException e) {
                ejec = true;
            }
        } while (ejec);
        
        return edad;
    }

    private static void deleteEmple(ArrayList col1, int edadElim) {
        Iterator iter = col1.iterator();
        
        while (iter.hasNext()) {
            if (iter.s)
        }
    }
}
