package OperacionesFicheros;

import Catalogo.Catalogo;
import Principal.main;
import Errores.Errores;
import Objetos.*;
import java.io.*;
import java.util.*;

public class DataManager {
    
    /*
    NOTA:
    Las cadenas se convierten a bytes usando el método getBytes(), por lo que se
    pueden escribir con UTF-8, por lo cual los bytes de los archivos binarios van
    a corresponder a caracteres codificados en UTF-8.
    */
    
    /*---------------------------------------------------------------*/// 1/1
    // Funciones para cargar los datos del archivo en un catálogo
    public static void cargarDatos(Catalogo cat) {
        try {
            // Abrimos el archivo
            FileInputStream datos = new FileInputStream("datos/videojuegos.bin");
            
            /* 
            Voy a leer el archivo y convertirlo entero en una cadena seguida.
            Esa cadena la separaré luego por los saltos de línea, y luego por
            los ';'. 
            
            Para leer todos los bytes usaré la función readAllBytes().
            Para convertir los bytes en una cadena usando una codificación concreta,
            usaré el constructor de String.
            */
            
            String allData = new String(datos.readAllBytes(), "UTF-8");
            
            // Separamos por líneas con la función lines(), y la pasamos a una lista
            // para que sea más cómodo manejar los datos.
            List<String> allDataLines =  allData.lines().toList();
            
            Iterator iter = allDataLines.iterator();
            // Añadimos al catálogo cada juego que nos encontremos, haciendo uso de la
            // función parseJuego().
            while (iter.hasNext()) {
                main.insertarVideojuego(cat, Videojuego.parseJuego((String) iter.next()));
            }
            
            datos.close();
        } catch (FileNotFoundException ex) {
            //
        } catch (IOException ex) {
            //
        }
    }
    
    /*---------------------------------------------------------------*/// 3/3
    // Funciones para grabar los datos en el fichero "videojuegos.bin"
    public static void grabarDatos() {
        // Vamos a mostrar los datos que ya hay en el archivo (si existe)
        mostrarDatos();
        
        System.out.println("¿Quiere escribir nuevos datos? (s/n): ");
        if (preguntar()) {
            // Preguntar si se quieren sobreescribir los datos o añadir más
            System.out.println("¿Quiere sobreescribir los datos existentes? (s/n): ");
            if (preguntar())
                cargarSobreescrito();
            else
                cargarNuevo();
        }
    }

    public static void cargarSobreescrito() {
        boolean ejec = true;
        Videojuego vj;
        // Abrimos el archivo para escribir en él (añadiendo información)
        File fiche = new File("datos/videojuegos.bin");
        try (FileOutputStream f = new FileOutputStream(fiche)) {
            do {
                ejec = false;
                // Cargar datos para un nuevo videojuego
                vj = new Videojuego();
                
                // Escribir en el archivo binario los datos de el juego
                f.write(vj.toBinary());
                
                // Preguntar si se quiere escribir otro
                System.out.println("¿Quiere grabar otro videojuego en el archivo? (s/n): ");
                ejec = preguntar();
            } while (ejec);
            
            f.close();
        } catch (FileNotFoundException ex) {
            // Si no existe el archivo.
        } catch (IOException ex) {
            // Potencial IOException.
        }
    }
    
    public static void cargarNuevo() {
        boolean ejec = true;
        Videojuego vj;
        // Abrimos el archivo para escribir en él
        File fiche = new File("datos/videojuegos.bin");
        try (FileOutputStream f = new FileOutputStream(fiche, true)) { // Solo cambia esta línea
            do {
                ejec = false;
                // Cargar datos para un nuevo videojuego
                vj = new Videojuego();
                
                // Escribir en el archivo binario los datos de el juego
                f.write(vj.toBinary());
                
                // Preguntar si se quiere escribir otro
                System.out.println("¿Quiere grabar otro videojuego en el archivo? (s/n): ");
                ejec = preguntar();
            } while (ejec);
            
            f.close();
        } catch (FileNotFoundException ex) {
            // Si no existe el archivo.
        } catch (IOException ex) {
            // Potencial IOException.
        }
    }
    
    /*---------------------------------------------------------------*/// 
    // Funciones para grabar los datos de un catálogo dado en un archivo de un tipo concreto
    public static void grabarDatos(Catalogo cat) {
        grabarBinario(cat);
        grabarPersistente(cat);
        grabarTexto(cat);
    }
    
    public static void grabarBinario(Catalogo cat) {
        Videojuego vj;
        Iterator iter = cat.iterator();
        // Creamos el archivo y lo abrimos
        File fiche = new File("datos/videojuegosBinario.bin");
        try (FileOutputStream f = new FileOutputStream(fiche)) {
             while (iter.hasNext()) {
                vj = (Videojuego) iter.next();
                
                // Escribir en el archivo binario los datos de el juego
                f.write(vj.toBinary());
            }
            
            f.close();
        } catch (FileNotFoundException ex) {
            // Si no existe el archivo.
        } catch (IOException ex) {
            // Potencial IOException.
        }
    }
    
    public static void grabarPersistente(Catalogo cat) {
        Iterator iter = cat.iterator();
        
        try (ObjectOutputStream fiche = new ObjectOutputStream(new FileOutputStream("datos/videojuegosPersistente.bin"))) {
            while (iter.hasNext()) {                
                fiche.writeObject((Videojuego) iter.next());
            }
            
            fiche.close();
        } catch (IOException ex) {
            // Potencial IOException.
        }
    }
    
    public static void grabarTexto(Catalogo cat) {
        Videojuego vj;
        Iterator iter = cat.iterator();
        
        try (FileWriter fiche = new FileWriter("datos/videojuegosTexto.txt")) {
            while (iter.hasNext()) {
                vj = (Videojuego) iter.next();
                
                // Escribir en el archivo binario los datos de el juego
                /*Uso el toBinary para escribirlo en el archivo con el formato de la cadena
                que uso al escribir en binario, me parece mejor que la forma en la que
                está el toString.*/
                fiche.write(new String(vj.toBinary(), "UTF-8"));
            }
            
            fiche.close();
        } catch (IOException ex) {
            // Potencial IOException.
        }
    }    
    
    /*---------------------------------------------------------------*/// 1/1
    // Mostrar los datos del archivo (si los hay)
    public static void mostrarDatos() {
        System.out.println("Datos contenidos en el archivo: \n");
        
        try {
            FileInputStream fichero = new FileInputStream("datos/videojuegos.bin");
            
            int c;
            
            while ((c=fichero.read()) != -1)
                System.out.print((char)c);
            
            fichero.close();
        }
        catch (FileNotFoundException e) {
            // No hace falta hacer nada en caso de que no exista, ya se creará en
            // la otra función.
        } catch (IOException ex) {
            // Si hay alguna excepción de entraga o salida.
        }
        System.out.println("\n\n");
    }
    
    /*---------------------------------------------------------------*/// 1/1
    // Función para preguntar al usuario
    public static boolean preguntar() {
        boolean ejec;
        String aux = null;
        
        InputStreamReader stream = new InputStreamReader(System.in);
        BufferedReader teclado = new BufferedReader(stream);

        do {
            try {
                ejec = false;
                aux = teclado.readLine();
                
                if (!aux.equals("s") && !aux.equals("n"))
                    throw new Errores();

            } catch (IOException e) {
                System.out.println("\n\t Introduzca una respuesta correcta: ");
                ejec = true;
            }
            catch (Errores e) {
                System.out.println("\n\t Introduzca una respuesta correcta: ");
                ejec = true;
            }
        } while (ejec);
        
        return aux.equals("s");
    }
}
