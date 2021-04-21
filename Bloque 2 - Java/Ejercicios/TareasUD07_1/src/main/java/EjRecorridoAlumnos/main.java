package EjRecorridoAlumnos;

public class main {
    public static void main(String[] args) {
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
        int cantAlum;
        Alumno alumnos[]; // Declaramos el array, pero no le damos tamaño.
        
        // Obtenemos el tamaño que le vamos a dar al array.
        cantAlum = cantidadAlumnos();
        
        // Ahora inicializamos el array con el tamaño que queremos.
        alumnos = new Alumno[cantAlum];
        
        // Introducimos los datos para los alumnos con los métodos de la propia clase.
        pedirDatos(alumnos);
        
        // Mostramos los datos de todos los alumnos.
        mostrarDatos(alumnos);
    }
    
    public static int cantidadAlumnos() {
        int cantAlum;
        
        System.out.println("Introduzca la cantidad de alumnos: ");
        cantAlum = Leer.datoInt();
        
        return cantAlum;
    }
    
    public static void pedirDatos(Alumno[] alumnos) {
        int i;
        // Se puede usar alumnos.length para obtener el tamaño del array
        for (i = 0; i < alumnos.length; i++)
        {
            System.out.println("Alumno " + (i+1) + ": ");
            alumnos[i] = new Alumno(); // Tenemos que llamar al constructor.
            // El constructor llamará a los setters para el nombre y los teléfonos.
        }
    }
    
    public static void mostrarDatos(Alumno[] alumnos) {
        int i, j;
        
        for ( i = 0; i < alumnos.length; i++)
        {
            System.out.println("Alumno " + (i+1) + ": ");
            System.out.println("\tNombre: " + alumnos[i].getNombre());
            System.out.println("\tNúmeros de teléfono: en total " + alumnos[i].getCantTlf());
            
            for (j = 0; j < alumnos[i].getCantTlf(); j++)
            {
                System.out.println("\t\tTeléfono nº" + (j+1) + ": " + alumnos[i].getTlfFromArray(j));
            }
            
            System.out.println("\n");
        }
    }
}
