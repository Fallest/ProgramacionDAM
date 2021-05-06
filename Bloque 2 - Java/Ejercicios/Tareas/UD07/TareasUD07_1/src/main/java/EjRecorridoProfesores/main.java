package EjRecorridoProfesores;

public class main {
    public static void main(String[] args) {
        // Nota: no es neesario poner las llaves si solo se va a poner una 
            // instrucción después del for, del if, del else o del while.
            // Nota 2: La estructura if - else if también existe, en vez de poner:
            /*
            if x
                haz esto
            else 
                if y
                    haz esto otro
            
            Se puede hacer:
            if x
                haz esto
            else if y
                haz esto otro
            */
            
        // Variable interruptor
        String cad = "s";
        // Instituto con los departamentos y los profesores
        
        /*
        Este ejercicio es bastante lioso, porque tienes una array de Profesores
        dentro de un array de Departamentos.
        Lo que es imprescindible entender, es que el array de profesores es un 
        ATRIBUTO de un departamento. Es decir, no tratamos con objetos profesores
        de forma independiente a no ser que accedamos al array de departamentos,
        y luego al array de profesores que hay dentro de cada objeto departamento.
        
        */
        Departamento instituto[] = new Departamento[4];
        
        introducirDatos(instituto);
        
        do {
            buscarProfesor(instituto);
            
            System.out.println("¿Quiere buscar otro profesor (s/n)?: ");
            cad = Leer.dato();
        } while("s".equals(cad)); // Método equals de las cadenas, recomendable frente a '=='.
        
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
        
        // if-else para comprobar si se ha encontrado al menos una coincidencia.
        if (dep != 0)
        {
            System.out.println("Se ha encontrado una última coincidencia en el profesor " + numProf + " del departamento " + dep + ".");
        }
        else
            System.out.println("No se ha encontrado ninguna coincidencia.");
    }
}

