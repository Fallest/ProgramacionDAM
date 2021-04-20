package Main;

public class main {
    public static void main(String args[])
    {
        // Ejercicio 1:
        Alumno.pedirCosteTitulo();
        /*------------------------------------------------*/
        // Ejercicio 2:
        Alumno alum1 = new Alumno('a');
        /*------------------------------------------------*/
        // Ejercicio 3:
        Alumno alum2, alum3;
        int edad_mellizos;
        
        System.out.println("\n\t\tIntroduzca la edad de los mellizos: ");
        edad_mellizos = Leer.datoInt();
        
        System.out.println("\n\t\t Alumno mellizo 1:");
        alum2 = new Alumno(edad_mellizos);
        System.out.println("\n\t\t Alumno mellizo 2:");
        alum3 = new Alumno(edad_mellizos);
        /*------------------------------------------------*/
        // Ejercicio 4:
        Alumno copia_alum1;
        copia_alum1 = alum1; // No es una copia real.
        /*------------------------------------------------*/
        // Ejercicio 5:
        mostrar_alumnos(alum1, alum2, alum3, copia_alum1);
        /*------------------------------------------------*/
        // Ejercicio 6:
        System.out.println("\n\t\tIntroduzca el nuevo coste del titulo: ");
        Alumno.pedirCosteTitulo();
        /*------------------------------------------------*/
        // Ejercicio 7:
        mostrar_alumnos(alum1, alum2, alum3, copia_alum1);
        /*------------------------------------------------*/
        // Ejercicio 8:
        System.out.println("Inicial del primer alumno: ");
        System.out.println(alum1.inicialNombre());
        /*------------------------------------------------*/
        // Ejercicio 9:
        System.out.println("Introduzca las nuevas notas del primer alumno: ");
        alum1.pedirNotas();
        /*------------------------------------------------*/
        // Ejercicio 10:
        int modulo;
        System.out.println("¿A qué módulo quiere cambiarle la nota del segundo alumno? (1- 5)");
        modulo = Leer.datoInt();
        alum2.pedirNotaConcreta(modulo); // No hace falta ponerle -1 porque ya está en la función.
        /*------------------------------------------------*/
        // Ejercicio 11:
        mostrar_alumnos(alum1, alum2, alum3, copia_alum1);
        /*------------------------------------------------*/
        // Ejercicio 12:
        alum1.pedirNotaConcreta(3);
        /*------------------------------------------------*/
        // Ejercicio 13:
        System.out.println("¿A qué módulo quiere cambiarle la nota de los hermanos? (1- 5)");
        modulo = Leer.datoInt();
        alum2.pedirNotaConcreta(modulo); // No hace falta ponerle -1 porque ya está en la función.
        alum3.pedirNotaConcreta(modulo);
        /*------------------------------------------------*/
        // Ejercicio 14:
        mostrar_alumnos(alum1, alum2, alum3, copia_alum1);
        /*------------------------------------------------*/
        // Ejercicio 15:
        float media_alumnos;
        media_alumnos = (float) (alum1.calcularMedia() + alum2.calcularMedia() + alum3.calcularMedia()) / 3;
        System.out.println("\tMedia de las notas de los alumnos: " + media_alumnos);
        /*------------------------------------------------*/
        // Ejercicio 16:
        System.out.println("\n\t\tLongitud del nombre del primer hermano: " + alum2.devNumCaractNombre());
        System.out.println("\n\t\tLongitud del nombre del segundo hermano: " + alum3.devNumCaractNombre());
        /*------------------------------------------------*/
        // Ejercicio 17:
        System.out.println("¿De qué módulo le gustaría ver las notas? (1- 5)");
        System.out.println("\tNotas del modulo " + modulo);
        System.out.println("\t\tAlumno 1: " + alum1.getNota(modulo));
        System.out.println("\t\tAlumno 2: " + alum2.getNota(modulo));
        System.out.println("\t\tAlumno 3: " + alum3.getNota(modulo));
        /*------------------------------------------------*/
    }
    
    // Ejercicio 5:
    static void mostrar_alumnos(Alumno alum1, Alumno alum2, Alumno alum3, Alumno alum4)
    {
        System.out.println("\n\t\tAlumno 1: ");
        alum1.visualTodosDatos();
        System.out.println("\n\t\tAlumno 2: ");
        alum2.visualTodosDatos();
        System.out.println("\n\t\tAlumno 3: ");
        alum3.visualTodosDatos();
        System.out.println("\n\t\tAlumno 4: ");
        alum4.visualTodosDatos();
    }
}
