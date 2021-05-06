package ColeccionEmpleados;

public class Empleado {
    // Atributos
    private String nombre;
    private int sueldo;
    
    // Constructor
    Empleado() {
        setNombre();
        setSueldo();
    }
    
    // Setters 
    public void setNombre() {
        System.out.println("\tIntroduzca el nombre del empleado:");
        this.nombre = Leer.dato();
        
        if (this.nombre.equals(""))
            throw new IllegalArgumentException();
    }
    
    public void setSueldo() {
        System.out.println("\tIntroduzca el sueldo del empleado:");
        this.sueldo = Leer.datoInt();
    }
    
    // Getters
    public String getNombre() {
        return this.nombre;
    }
    
    public int getSueldo() {
        return this.sueldo;
    }
    
    // Utilidades
    public String toString() {
        return "\tNombre: " + this.nombre + "\n\tSueldo: " + this.sueldo;
    }
    
}
