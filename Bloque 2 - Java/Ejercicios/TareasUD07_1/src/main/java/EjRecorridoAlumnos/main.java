package EjRecorridoAlumnos;

public class main {
    public static void main(String[] args) {
        int cantAlum;
        Alumno alumnos[]; // Declaramos el array, pero no le damos tamaño.
        
        // Obtenemos el tamaño que le vamos a dar al array.
        cantAlum = cantidadAlumnos();
        
        // Ahora inicializamos el array con el tamaño que queremos.
        alumnos = new Alumno[cantAlum];
        
        // Introducimos los datos para los alumnos con los métodos de la propia clase.
        pedirDatos(cantAlum, alumnos);
        
        // Mostramos los datos de todos los alumnos.
        mostrarDatos(cantAlum, alumnos);
    }
    
    public static int cantidadAlumnos() {
        int cantAlum;
        
        System.out.println("Introduzca la cantidad de alumnos: ");
        cantAlum = Leer.datoInt();
        
        return cantAlum;
    }
    
    public static void pedirDatos(int cantAlum, Alumno[] alumnos) {
        int i;
        
        for (i = 0; i < cantAlum; i++)
        {
            System.out.println("Alumno " + (i+1) + ": ");
            alumnos[i] = new Alumno(); // Tenemos que llamar al constructor.
            // El constructor llamará a los setters para el nombre y los teléfonos.
        }
    }
    
    public static void mostrarDatos(int cantAlum, Alumno[] alumnos) {
        int i, j;
        
        for ( i = 0; i < cantAlum; i++)
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
