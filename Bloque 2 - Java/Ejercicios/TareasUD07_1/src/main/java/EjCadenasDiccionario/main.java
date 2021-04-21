package EjCadenasDiccionario;

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
        
        // El diccionario es un array de parejas. La clase PPareja
        // se usa para crear un objeto, que es una pareja de Strings.
        // Al usar un objeto nos ahorramos liarnos en main con vectores.
        PPareja diccionario[]; // No le damos tamaño todavía.
        int tamDict;
        
        // Pedir tamaño
        tamDict = pedirTamDict();
        
        // Asignar el tamaño
        diccionario = new PPareja[tamDict];
        
        // Pedir datos
        diccionario = pedirDatos(diccionario);
        
        // Ordenar el diccionario por las palabras en inglés.
        diccionario = ordenarDict(diccionario);
        
        // Modo traduccion
        traducir(diccionario);
    }
    
    public static int pedirTamDict() {
        boolean ejec;
        int res = 0;
        
        do {
            try {
                System.out.println("Introduzca el tamaño del diccionario: ");
                res = Leer.datoInt();
                ejec = false;
            }
            catch (NumberFormatException e) {
                System.out.println("\nSe han introducido caracteres no válidos.");
                ejec = true;
            }
        } while (ejec);
        
        return res;
    }
    
    public static PPareja[] pedirDatos(PPareja[] dict) {
        int i;
        
        for (i = 0; i < dict.length; i++)
        {
            System.out.println("Pareja número " + (i+1) + ": ");
            dict[i] = new PPareja(); // Llamada al constructor para pedir las dos cadenas.
        }
        
        // La función crea una copia del parámetro dict, entonces lo devolvemos
        // directamente, no hace falta crear un diccionario "auxiliar", porque
        // lo hemos modificado dentro de la función, pero esto no se transmite hacia fuera.
        return dict;
    }
    
    public static PPareja[] ordenarDict(PPareja[] dict) {
        int i, j, min;
        PPareja aux;
        
        // Algoritmo para ordenar
        for (i = 0; i < dict.length; i++)
        {
            // Tomamos como mínimo al actual
            min = i;
            // Vamos a buscar en el resto de la estructura
            for (j = i + 1; j < dict.length; j++)
                // Si encontramos una cadena cuya letra inicial es menor que la
                // actual, le asignamos un nuevo menor
                if (dict[i].getCad1().charAt(0) < dict[j].getCad1().charAt(0))
                    min = j;
            
            // Intercambiamos los valores
            aux = dict[i];
            dict[i] = dict[min];
            dict[min] = aux;
        }
        
        return dict;
    }
    
    public static void traducir(PPareja[] dict) {
        boolean ejec = true, flag;
        String cad;
        int i;
        
        do {
            // Levantamos la bandera. Lo hacemos en cada iteración del bucle.
            flag = true;
            System.out.println("Introduzca una palabra en inglés: (\"fin\" para salir)");
            cad = Leer.dato();
            
            // Primero comprobamos si se ha escrito "fin".
            if (cad.equals("fin"))
            {
                ejec = false;
                System.out.println("\nSaliendo del programa...");
                continue;
            }
            
            // Buscamos la cadena correspondiente en la estructura.
            for (i = 0; i < dict.length; i++)
                if (cad.equals(dict[i].getCad1()))
                {
                    System.out.println("\tTraducción: " + dict[i].getCad2());
                    // Bajamos la bandera si hemos encontrado una palabra
                    flag = false;
                }
            
            // Si la bandera sigue levantada después del bucle, significa que no hay traducción.
            if (flag)
                System.out.println("\tLa traducción a esa palabra no existe.");
        } while(ejec);
    }
}
