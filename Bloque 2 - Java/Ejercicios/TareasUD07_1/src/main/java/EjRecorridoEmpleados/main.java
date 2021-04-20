package EjRecorridoEmpleados;

public class main {
    
    public static void main(String[] args) {
        // Array de empleados y tamaño del array
        Empleado empleados[];
        int cantEmple = getCantEmple();
        
        // Asignar el tamaño al array
        empleados = new Empleado[cantEmple];
        
        // Pedimos los datos
        pedirDatos(cantEmple, empleados);
        
        // Ordenamos el array
        empleados = ordenarArray(cantEmple, empleados);
        
        consultarSueldo(cantEmple, empleados);
    }
    
    public static int getCantEmple() {
        int cantEmple;
        
        do {
            System.out.println("Introduzca la cantidad de empleados que va a registrar: ");
            cantEmple = Leer.datoInt();
        } while(cantEmple < 0);
        
        return cantEmple;
    }
    
    public static void pedirDatos(int cantEmple, Empleado[] empleados) {
        int i;
        
        for (i = 0; i < cantEmple; i++)
        {
            System.out.println("Empleado Nº" + (i+1) + ": ");
            empleados[i] = new Empleado(); // Llamada al constructor para asignarle los valores
        }
    }
    
    public static Empleado[] ordenarArray(int cantEmple, Empleado[] empleados) {
        int i, j, min;
        Empleado EmpleOrden[] = empleados;
        Empleado aux;
        
        /*
        Usaremos el algoritmo de la burbuja:
            1-Vamos a ver el sueldo del empleado actual, y lo vamos a usar como mínimo.
            2-Vamos a buscar, en un bucle anidado, el sueldo de otro empleado que 
                sea menor que el que ya tenemos almacenado.
            3-Cuando lo encontremos, vamos a establecer ese empleado como el nuevo 
                mínimo, y salimos del bucle anidado.
            4-Intercambiamos las posiciones actual con la del mínimo encontrado.
            5-Repetir hasta haber iterado sobre toda la estructura.
        */
        for (i = 0; i < cantEmple; i++)
        {
            // Primero asignamos el acutal como el mínimo actual
            min = i;
            // Entramos en la iteración anidada para buscar un nuevo mínimo
            for (j = i; j < cantEmple; j++)
            {
                // Si encontramos un empleado con un sueldo menor del actual, 
                // cambiamos el mínimo y salimos.
                if (empleados[j].getSueldo() < empleados[i].getSueldo())
                {
                    min = j;
                    break;
                }
            }
            
            // Haya encontrado un nuevo mínimo o no, los intercambiamos.
            aux = empleados[i];
            empleados[i] = empleados[min];
            empleados[min] = aux;
        }
        
        return EmpleOrden;
    }
    
    public static void consultarSueldo(int cantEmple, Empleado[] empleados) {
        int sueldo, i;
        
        do {
            System.out.println("Inserte el sueldo límite (se mostrarán los inferiores o iguales): ");
            System.out.println("Para salir introduzca un número negativo.");
            sueldo = Leer.datoInt();
            
            for (i = 0; i < cantEmple; i++)
            {
                if (empleados[i].getSueldo() <= sueldo)
                {
                    System.out.println("Empleado " + (i+1) + ": ");
                    System.out.println("\tNombre: " + empleados[i].getNombre());
                    System.out.println("\tSueldo: " + empleados[i].getSueldo() + "€");
                }
            }
        } while (sueldo >= 0);
    }
}
