package EjRecorridoProfesores;

public class main {
    public static void main(String[] args) {
        // Instituto con los departamentos y los profesores
        Departamento instituto[] = new Departamento[4];
        
        introducirDatos(instituto);
        
        buscarProfesor(instituto);
    }
    
    public static void introducirDatos(Departamento[] instituto) {
        // Inicializar todos los departamentos.
        int i;
        for (i = 0; i < 4; i++)
        {
            System.out.println("Departamento nº" + (i+1) + ": ");
            // Llamada al constructor con parámetro.
            instituto[i] = new Departamento(i+1);
        }
    }
    
    public static void buscarProfesor(Departamento[] instituto) {
        int edad, dep = 0, numProf = 0;
        Profesor prof;
        Profesor[] profesores;
        
        // Pedimos al usuario la edad.
        System.out.println("¿Qué edad quiere buscar?: ");
        edad = Leer.datoInt();
        
        int i, j;
        for (i = 0; i < 4; i++)
        {
            
            // Creamos una copia del array de profesores que hay dentro del departamento X.
            profesores = instituto[i].getProfArray();
            for (j = 0; j < 6; j++)
                // Entramos en la copia del array de profesores, y buscamos por la edad
                // que ha introducido el usuario.
                if (profesores[j].getEdad() == edad)
                    // Cuando la encontremos, creamos una copia del Profesor en nuestra variable local.
                    // Por la naturaleza del bucle, se almacenará el último valor encontrado,
                    // que es lo que buscamos si encontramos más de uno.
                    prof = profesores[j];
                    dep = i+1;
                    numProf = j;
        }
        
        if (dep != 0)
        {
            System.out.println("Se ha encontrado una última coincidencia en el profesor " + numProf + " del departamento " + dep + ".");
        }
        else
            System.out.println("No se ha encontrado ninguna coincidencia.");
    }
}

