package EjRecorridoEmpleados;

public class Empleado {
    // Atributos
    private String nombre;
    private int sueldo;
    
    // Dos constructores, uno sin parámetros y el otro con parámetros.
    Empleado() {
        setNombre();
        setSueldo();
    }
    
    Empleado(String nombre, int sueldo) {
        setNombre(nombre);
        setSueldo(sueldo);
    }
    
    // Setters
    public void setNombre() {
        System.out.println("\tIntroduzca el nombre del empleado: ");
        this.nombre = Leer.dato();
    }
    
    public void setNombre(String nombre) {
        this.nombre = nombre;
    }
    
    public void setSueldo() {
        System.out.println("\tIntroduzca el sueldo del empleado: ");
        this.sueldo = Leer.datoInt();
    }
    
    public void setSueldo(int sueldo) {
        this.sueldo = sueldo;
    }
    
    // Getters
    public String getNombre() {
        return this.nombre;
    }
    
    public int getSueldo() {
        return this.sueldo;
    }
}
