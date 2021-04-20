package EjRecorridoAlumnos;

public class Alumno {
    
    // Atributos
    private String nombre;
    private int cantNumTlf;
    private int tlfArray[];
    
    Alumno() {
        setNombre();
        setTlf();
    }
    
    Alumno(String nombre, int cantTlf) {
        setNombre(nombre);
        setTlf(cantTlf);
    }
    
    
    // Setters
    public void setNombre() {
        System.out.println("Nombre del alumno: ");
        this.nombre = Leer.dato();
    }
    
    public void setNombre(String nom) {
        this.nombre = nom;
    }
    
    public void setTlf(int cantTlf) {
        // El parámetro es la cantidad de teléfonos que se van a dar.
        // Va a asignar al vector dicha cantidad de espacios y los va a rellenar
        // con los teléfonos que se lean por teclado.
        int i;
        this.tlfArray = new int[cantTlf];
        
        if (cantTlf < 0) 
        {
            System.out.println("No se puede introducir una cantidad negativa de números de teléfono.");
            setTlf();
        }
        // Debemos separar estos bloques, porque si no, se introducirán los datos dos veces,
        // una vez en la llamada a setTlf(), y otra vez en el bucle de a continuación.
        else {
            for (i = 0; i < cantNumTlf; i++)
            {
                System.out.println("Introduzca el teléfono nº " + (i+1) + ": ");
                this.tlfArray[i] = Leer.datoInt();

                if (this.tlfArray[i] < 100000000 || this.tlfArray[i] > 999999999)
                {
                    System.out.println("Formato de teléfono no válido.");
                    i--;
                }
            }
        }
    }
    
    public void setTlf() {
        int i;
        boolean ioCorrecta;
        
        do {
            ioCorrecta = true;
            // Pedir cuántos teléfonos se van a dar, y asignar al vector esa cantidad de espacios.
            System.out.println("¿Cuántos números de teléfono se van a insertar para el alumno " + this.nombre + "?: ");
            this.cantNumTlf = Leer.datoInt(); 

            // Comprobar que no se ha dado un número negativo.
            // Si se ha dado un número negativo, va a cambiar la bandera a false,
            // y va a saltar el resto del código, para volver al principio del bucle.
            if (cantNumTlf < 0) {
                System.out.println("No se puede introducir una cantidad negativa de números de teléfono.");
                ioCorrecta = false;
                continue;
            }
            
            this.tlfArray = new int[cantNumTlf];

            // Pedir un teléfono para cada espacio que le hemos dado al vector.
            for (i = 0; i < cantNumTlf; i++)
            {
                System.out.println("Introduzca el teléfono nº " + (i+1) + ": ");
                this.tlfArray[i] = Leer.datoInt();
                
                // Va a comprobar si el teléfono tiene un formato válido.
                // Si no lo es, va a volver al índice anterior y va a repetir los
                // mismos pasos hasta que se de un número válido.
                if (this.tlfArray[i] < 100000000 || this.tlfArray[i] > 999999999)
                {
                    System.out.println("Formato de teléfono no válido.");
                    i--;
                }
            }
        } while(!ioCorrecta);
    }
    
    // Getters
    public int getCantTlf() {
        return this.cantNumTlf;
    }
    
    public int getTlfFromArray(int i) {
        return this.tlfArray[i];
    }
    
    public String getNombre() {
        return this.nombre;
    }
}
