import java.io.*;

public class Alumno implements Serializable {
    String nombre;
    int edad;
    
    Alumno()
    {
        System.out.println("Introduzca el nombre del alumno: ");
        nombre = Leer.dato();
        System.out.println("Introduzca la edad del alumno: ");
        edad = Leer.datoInt();
    }
    
    void visualizar()
    {
        System.out.println("El alumno se llama " + nombre + " y tiene " + edad + " años.");
    }
    
}
