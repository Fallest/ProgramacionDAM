package Parametros07;

public class Alumno {
    private int edad;
    private String nombre;
    
    /*
    void Alumno(int edad, String nombre) {
        this.edad = edad;
        this.nombre = nombre;
    }
    */
    
    int getEdad() {
        return edad;
    }
    
    String getNombre () {
        return nombre;
    }
    
    void setEdad (int edad) {
        this.edad = edad;
    }
    
    void setNombre (String nombre) {
        this.nombre = nombre;
    }
    
    void mostrarDatos () {
        System.out.println("\tNombre: " + nombre);
        System.out.println("\tEdad: " + edad);
    }
}
