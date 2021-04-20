package EjRecorridoProfesores;

public class Profesor {
    // Atributos
    private int edad;
    
    Profesor() {
        System.out.println("\tIntroduzca la edad del profesor: ");
        this.edad = Leer.datoInt();
    }
    
    Profesor(int edad) {
        this.edad = edad;
    }
    
    // Getters
    public int getEdad() {
        return this.edad;
    }
}
