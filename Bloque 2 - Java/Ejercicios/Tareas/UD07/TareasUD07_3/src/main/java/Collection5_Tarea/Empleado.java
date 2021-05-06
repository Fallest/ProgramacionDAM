
package Collection5_Tarea;

public class Empleado {
    // Atributos
    private String nombre;
    private int edad;
    
    Empleado() {
        setNombre();
        setEdad();
    }
    
    public void setNombre() {
        System.out.println("\tIntroduzca el nombre: ");
        this.nombre = Leer.dato();
    }
    
    public void setEdad() {
        System.out.println("\tIntroduzca la edad: ");
        this.edad = Leer.datoInt();
    }
}
