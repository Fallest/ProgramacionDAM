package EjRecorridoProfesores;

public class Departamento {
    private Profesor profArray[] = new Profesor[6];
    private int numDep;
    
    Departamento() {
        setNumDept();
        setProfArray();
    }
    
    Departamento(int i ) {
        setNumDept(i);
        setProfArray();
    }
    
    // Setters
    public void setNumDept() {
        System.out.println("Introduzca un número de departamento: ");
        this.numDep = Leer.datoInt();
    }
    
    public void setNumDept(int num) {
        this.numDep = num;
    }
    
    public void setProfArray() {
        int i;
        
        for (i = 0; i < 6; i++)
        {
            System.out.println("Profesor nº " + (i+1) + ": ");
            // Llamada al constructor para poner la edad.
            this.profArray[i] = new Profesor();
        }
    }
    
    // Getters
    public Profesor[] getProfArray() {
        return this.profArray;
    }
}
