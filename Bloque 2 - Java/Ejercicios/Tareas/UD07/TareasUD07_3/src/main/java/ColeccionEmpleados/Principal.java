package ColeccionEmpleados;



public class Principal {
    public static void main(String[] args) {
        Empleado[] empleados = new Empleado[20];
        
        if (preguntaUsuario(empleados))
            insertarDatos(empleados);
        else
            ejecOperaciones(empleados);
        
    }
    
    private static boolean preguntaUsuario(Empleado[] empleados) {
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
    
    private static void insertarDatos(Empleado[] empleados) {
        boolean ejec = true;
        int cont = 0;
        
        System.out.println("--Deje el nombre en blanco para parar de introducir empleados--");
        System.out.println("---------------------------------------------------------------\n");
        
        do {
            try {
                System.out.println("Empleado " + (cont+1) + ":");
                cont++;
                empleados[cont] = new Empleado();
            }
            catch (IllegalArgumentException e) {
                // Uso una excepción propagada desde el constructor de Empleado
                // para parar el bucle.
                ejec = false;
            }
        } while(ejec);
    }

    private static void ejecOperaciones(Empleado[] empleados) {
        mostrarDatos(empleados);
        
        borrarEmple(empleados);
        mostrarDatos(empleados);
        
        mostrarDatosPos(empleados);
        mostrarDatos(empleados);
        
        modEmple(empleados);
        mostrarDatos(empleados);
        
        insertarEmple(empleados);
        mostrarDatos(empleados);
    }

    private static void mostrarDatos(Empleado[] empleados) {
        throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
    }

    private static void borrarEmple(Empleado[] empleados) {
        throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
    }

    private static void mostrarDatosPos(Empleado[] empleados) {
        throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
    }

    private static void modEmple(Empleado[] empleados) {
        throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
    }

    private static void insertarEmple(Empleado[] empleados) {
        throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
    }
    
    
}
