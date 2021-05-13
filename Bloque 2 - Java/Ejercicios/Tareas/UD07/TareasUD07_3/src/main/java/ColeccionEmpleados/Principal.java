package ColeccionEmpleados;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;



public class Principal {
    public static void main(String[] args) {
        Collection empleados = new ArrayList();
        
        if (preguntaUsuario())
            insertarDatos(empleados);
        else
            ejecOperaciones(empleados);
        
    }
    
    /*------------------------------------------------------------------------*/
    private static boolean preguntaUsuario() {
        String op;
        boolean ejec, res = false;
        
        do {
            System.out.print("¿Quiere insertar datos para los empleados? (s/n): ");
            op = Leer.dato();
            if (op.equals("s")) {
                ejec = false;
                res = true;
            }
            else if (op.equals("n")){
                ejec = false;
                res = false;
            }
            else {
                ejec = true;
                System.out.println("\n\t---Opción no válida---\n");
            }
        } while(ejec);
        
        return res;
    }
    
    /*------------------------------------------------------------------------*/
    private static void insertarDatos(Collection empleados) {
        boolean ejec = true;
        int cont = 0;
        Iterator iter = empleados.iterator();
        Empleado empleAux;
        
        System.out.println("--Deje el nombre en blanco para parar de introducir empleados--");
        System.out.println("---------------------------------------------------------------\n");
        
        do {
            try {
                System.out.println("Empleado " + (cont+1) + ":");
                cont++;
                empleAux = (Empleado) iter.next(); // Casting necesario a empleado
                empleAux = new Empleado(); // empleAux es un puntero hacia el elemento del array.
            }
            catch (IllegalArgumentException e) {
                // Uso una excepción propagada desde el constructor de Empleado
                // para parar el bucle.
                ejec = false;
            }
        } while(ejec);
    }

    /*------------------------------------------------------------------------*/
    private static void ejecOperaciones(Collection empleados) {
        System.out.println("Datos al inicio");
        mostrarDatos(empleados);
        
        borrarEmple(empleados);
        System.out.println("Datos al tras borrar empleados");
        mostrarDatos(empleados);
        
        mostrarDatosPos(empleados);
        
        modEmple(empleados);
        System.out.println("Datos tras modificar los empleados");
        mostrarDatos(empleados);
        
        insertarEmple((ArrayList) empleados); // Casting necesario
        System.out.println("Datos tras insertar empleados");
        mostrarDatos(empleados);
    }

    /*------------------------------------------------------------------------*/
    private static void mostrarDatos(Collection empleados) {
        Iterator iter = empleados.iterator();
        int cont = 0;
        
        while (iter.hasNext()) {
            System.out.println("Empleado " + cont + ": " + iter.next());
            cont++;
        }
        System.out.println("\n");
    }

    /*------------------------------------------------------------------------*/
    private static void borrarEmple(Collection empleados) {
        boolean ejec = true, flag = false; // flag sirve para saber si se ha encontrado un Empleado con el nombre dado.
        String nom, pregunta;
        Iterator iter = empleados.iterator();
        Empleado empleAux;
        
        do {
            nom = pedirNombre();
            
            while (iter.hasNext()) {
                empleAux = (Empleado) iter.next(); // Necesario un casting
                if (empleAux.getNombre().equals(nom)) {
                    iter.remove();
                    flag = true;
                }
            }
            
            if (!flag) 
                System.out.println("No existe ningún empleado con ese nombre.");
            
            System.out.println("¿Quiere borrar otro empleado? (s/n)");
            pregunta = Leer.dato();
            
            if (!pregunta.equals("s"))
                ejec = false;
        } while(ejec);
    }
    
    private static String pedirNombre() {
        boolean ejec = true;
        String nom = "";
        
        System.out.println("\n\tIntroduzca el nombre del empleado a borrar:");
        nom = Leer.dato();
        
        return nom;
    }

    /*------------------------------------------------------------------------*/
    private static void mostrarDatosPos(Collection empleados) {
        boolean ejec = true, flag = false; // flag sirve para saber si se ha encontrado un Empleado con la pos dada.
        String pregunta;
        int pos, cont = 0;
        Iterator iter = empleados.iterator();
        Empleado empleAux;
        
        do {
            pos = pedirPos();
            
            while (iter.hasNext()) {
                cont++;
                empleAux = (Empleado) iter.next(); // Necesario un casting
                if (cont == pos) {
                    System.out.println(empleAux);
                    flag = true;
                }
            }
            
            if (!flag) 
                System.out.println("No existe ningún empleado en esa posición.");
            
            System.out.println("¿Quiere mostrar otro empleado? (s/n)");
            pregunta = Leer.dato();
            
            if (!pregunta.equals("s"))
                ejec = false;
        } while(ejec);
    }
    
    private static int pedirPos() {
        boolean ejec = true;
        int pos = 1;
        
        System.out.println("\n\tIntroduzca la posición del empleado a mostrar:");
        pos = Leer.datoInt();
        
        return pos-1; // Tener en cuenta que el usuario da la posición de 1 en adelante.
    }

    /*------------------------------------------------------------------------*/
    private static void modEmple(Collection empleados) {
        boolean ejec = true, flag = false; // flag sirve para saber si se ha encontrado un Empleado con la pos dada.
        String pregunta;
        int pos, cont = 0;
        Iterator iter = empleados.iterator();
        Empleado empleAux;
        
        do {
            pos = pedirPos();
            
            while (iter.hasNext()) {
                cont++;
                empleAux = (Empleado) iter.next(); // Necesario un casting
                if (cont == pos) {
                    empleAux = new Empleado();
                    flag = true;
                }
            }
            
            if (!flag) 
                System.out.println("No existe ningún empleado en esa posición.");
            
            System.out.println("¿Quiere modificar otro empleado? (s/n)");
            pregunta = Leer.dato();
            
            if (!pregunta.equals("s"))
                ejec = false;
        } while(ejec);
    }

    /*------------------------------------------------------------------------*/
    private static void insertarEmple(ArrayList empleados) {
        boolean ejec = true;
        String pregunta;
        int pos, cont = 0;
        Iterator iter = empleados.iterator();
        Empleado empleAux;
        
        do {
            pos = pedirPos();
            
            if (pos < empleados.size())
                while (iter.hasNext()) {
                    cont++;
                    empleAux = (Empleado) iter.next(); // Necesario un casting
                    if (cont == pos) 
                        empleados.add(pos, new Empleado());
                        // Para poder usar esta versión de add tendremos que cambiar
                        // la declaración de la funcion, de:
                        // Collection empleados
                        // a:
                        // ArrayList empleados
                }
            else 
                System.out.println("Esa posición no está en el rango.");
            
            System.out.println("¿Quiere modificar otro empleado? (s/n)");
            pregunta = Leer.dato();
            
            if (!pregunta.equals("s"))
                ejec = false;
        } while(ejec);
    }
}
