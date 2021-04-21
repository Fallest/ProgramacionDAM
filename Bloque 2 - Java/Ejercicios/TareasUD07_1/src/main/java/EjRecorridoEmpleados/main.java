package EjRecorridoEmpleados;

public class main {
    
    public static void main(String[] args) {
        // Array de empleados y tamaño del array
        Empleado empleados[];
        int cantEmple = getCantEmple();
        
        // Asignar el tamaño al array
        empleados = new Empleado[cantEmple];
        
        // Pedimos los datos
        pedirDatos(empleados);
        
        // Ordenamos el array
        empleados = ordenarArray(empleados);
        
        consultarSueldo(empleados);
    }
    
    public static int getCantEmple() {
        int cantEmple;
        
        do {
            System.out.println("Introduzca la cantidad de empleados que va a registrar: ");
            cantEmple = Leer.datoInt();
        } while(cantEmple < 0);
        
        return cantEmple;
    }
    
    public static void pedirDatos(Empleado[] empleados) {
        int i;
        // Se puede usar empleados.length para obtener el tamaño del array
        for (i = 0; i < empleados.length; i++)
        {
            System.out.println("Empleado Nº" + (i+1) + ": ");
            empleados[i] = new Empleado(); // Llamada al constructor para asignarle los valores
        }
    }
    
    public static Empleado[] ordenarArray(Empleado[] empleados) {
        int i, j, min;
        Empleado aux;
        
        /*
        Usaremos el algoritmo de la burbuja:
            1-Vamos a ver el sueldo del empleado actual, y lo vamos a usar como mínimo.
            2-Vamos a buscar, en un bucle anidado, el sueldo de otro empleado que 
                sea menor que el que ya tenemos almacenado.
            3-Cuando lo encontremos, vamos a establecer ese empleado como el nuevo 
                mínimo.
            4-Intercambiamos las posiciones actual con la del mínimo encontrado.
            5-Repetir hasta haber iterado sobre toda la estructura.
        */
        for (i = 0; i < empleados.length; i++)
        {
            // Primero asignamos el acutal como el mínimo actual
            min = i;
            // Entramos en la iteración anidada para buscar un nuevo mínimo
            for (j = i + 1; j < empleados.length; j++)
                // Si encontramos un empleado con un sueldo menor del actual
                // cambiamos el mínimo.
                if (empleados[j].getSueldo() < empleados[i].getSueldo())
                    min = j;
            // Nota: no es neesario poner las llaves si solo se va a poner una 
            // instrucción después del for, del if, del else o del while.
            // Nota 2: La estructura if - else if también existe, en vez de poner:
            /*
            if x
                haz esto
            else 
                if y
                    haz esto otro
            
            Se puede hacer:
            if x
                haz esto
            else if y
                haz esto otro
            */
            
            // Haya encontrado un nuevo mínimo o no, los intercambiamos.
            aux = empleados[i];
            empleados[i] = empleados[min];
            empleados[min] = aux;
        }
        // Se puede devolver el propio parámetro, y nos ahorramos crear una copia.
        return empleados;
    }
    
    public static void consultarSueldo(Empleado[] empleados) {
        int sueldo, i;
        
        do {
            System.out.println("Inserte el sueldo límite (se mostrarán los inferiores o iguales): ");
            System.out.println("Para salir introduzca un número negativo.");
            sueldo = Leer.datoInt();
            
            for (i = 0; i < empleados.length; i++)
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
