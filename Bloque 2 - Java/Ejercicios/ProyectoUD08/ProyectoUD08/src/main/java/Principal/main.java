package Principal;

import Catalogo.Catalogo;
import Objetos.*;
import Errores.Errores;
import OperacionesFicheros.*;
import java.io.*;
import java.util.*;

public class main {
    
    public static void main(String[] args) {
        Catalogo catJuegos = new Catalogo<Videojuego>();
        int opcion;
        
        // Primero grabamos una serie de juegos en el archivo videojuegos.bin
        DataManager.grabarDatos();
        // Luego cargamos los datos en el catálogo
        DataManager.cargarDatos(catJuegos);
        
        do {
            opcion = menu();
            System.out.println("Ejecutando opción " + opcion + "...\n-----------\n");
            ejecutarOpcion(opcion, catJuegos);
        } while (opcion != 5);
        
        System.out.println("Grabando datos...");
        DataManager.grabarDatos(catJuegos);
    }
    /*------------------------------------------------------------------------*/
    // Funciones del menú: 2/2
    public static int menu() {
        // Muestra el menú y lee la opción a escoger.
        int opcion = 0;
        
        System.out.println("-------------MENU-------------");
        System.out.println("Juegos:");
        System.out.println("1. \tAlta de videojuego");
        System.out.println("2. \tBaja de videojuego");
        System.out.println("3. \tModificar videojuego");
        System.out.println("4. \tLista de videojuegos");
        System.out.println("5. \tSalir");
        System.out.println("------------------------------");
        
        InputStreamReader stream = new InputStreamReader(System.in);
        BufferedReader teclado = new BufferedReader(stream);
        
        do {
            try {
                opcion = Integer.parseInt(teclado.readLine());
            }
            catch (IOException e) {
                System.out.println("\n\tError en la entrada de datos.");
                opcion = 0;
            }
            catch (NumberFormatException e) {
                System.out.println("\n\tError: Se han introducido caracteres no válidos.");
                opcion = 0;
            }
        } while (opcion < 1 || opcion > 5);
        
        return opcion;
    }
    
    public static void ejecutarOpcion(int opcion, Catalogo catJuegos) {
        switch (opcion) {
            case 1 ->  {
                insertarVideojuego(catJuegos);
            }
            case 2 ->  {
                try {eliminarVideojuego(catJuegos);}
                catch (Errores e) {e.catVacio();}
            }
            case 3 ->  {
                try{modificarVideojuego(catJuegos);}
                catch (Errores e) {e.catVacio();}
            }
            case 4 ->  {
                mostrarDatos(catJuegos);
            }
        }
    }
    
    /*-----*/ 
    // Funciones de alta, baja, y modificación de juegos: 3/3
    public static void insertarVideojuego(Catalogo cat) {
        // Inicializamos el juego que vamos a insertar:
        Videojuego juego = new Videojuego();

        // Si es el primer dato
        if (cat.isEmpty()) {
            cat.add(juego);
        }
        
        //Vamos a buscar la posición en la que vamos a meter el juego
        else 
        {
            Iterator iter = cat.iterator();
            int cont = 0;
            boolean flag = false;
            Videojuego aux;
            
            while (iter.hasNext()) {
                aux = (Videojuego) iter.next(); // Hay que hacer casting
                if (Fecha.toInt(aux.getFecha()) <= Fecha.toInt(juego.getFecha())) {
                    cat.add(cont, juego);
                    flag = true;
                    break;
                }
                else cont++;
            }
            
            if (!flag)
                cat.add(juego);
        }
    }
    
    public static void insertarVideojuego(Catalogo cat, Videojuego vj) {
        // Si es el primer dato
        if (cat.isEmpty()) {
            cat.add(vj);
        }
        
        //Vamos a buscar la posición en la que vamos a meter el juego
        else 
        {
            Iterator iter = cat.iterator();
            int cont = 0;
            boolean flag = false;
            Videojuego aux;
            
            while (iter.hasNext()) {
                aux = (Videojuego) iter.next(); // Hay que hacer casting
                if (Fecha.toInt(aux.getFecha()) <= Fecha.toInt(vj.getFecha())) {
                    cat.add(cont, vj);
                    flag = true;
                    break;
                }
                else cont++;
            }
            
            if (!flag)
                cat.add(vj);
        }
    }
    
    public static void eliminarVideojuego(Catalogo cat) throws Errores {
        // Pedimos el título a eliminar:
        System.out.println("Título a eliminar: ");
        String tituloElim = pedirTitulo();
        boolean elim = false; // Bandera para saber si hemos eliminado algún juego.
        Iterator iter = cat.iterator();
        Videojuego aux;
        
        if (cat.isEmpty())
            throw new Errores();
        else {
            // Buscamos dicho título en el array
            while (iter.hasNext()) {
                aux = (Videojuego) iter.next();
                if (aux.getTitulo().toLowerCase().equals(tituloElim.toLowerCase())) {
                    iter.remove();
                    System.out.println("Juego eliminado.\n");
                    elim = true;
                    break;
                }
            }
        
            if (!elim)
                System.out.println("No existe dicho juego.\n");
        }
    }
    
    public static void modificarVideojuego(Catalogo cat) throws Errores {
        // Preguntamos por el título del videojuego a modificar
        System.out.println("Título del videojuego a modificar: ");
        String tituloElim = pedirTitulo();
        boolean modif = false; // Bandera para saber si hemos modificado algún juego
        Iterator iter = cat.iterator();
        int cont = 0;
        Videojuego aux;
        
        if (cat.isEmpty())
            throw new Errores();
        
        else {
            // Buscamos dicho título en el array
            while (iter.hasNext()) {
                aux = (Videojuego) iter.next();
                // Si lo encontramos, creamos un nuevo juego y lo insertamos en esa posición
                if (aux.getTitulo().toLowerCase().equals(tituloElim.toLowerCase())) {
                    Videojuego nuevo = new Videojuego();
                    cat.set(cont, nuevo);
                    System.out.println("Juego modificado.\n");
                    modif = true;
                    break;
                }
                cont++;
            }

            if (!modif)
                System.out.println("No existe dicho juego.\n");
        }
    }

    /*------------------------------------------------------------------------*/
    // Funciones para mostrar datos del catálogo: 1/1
    public static void mostrarDatos(Catalogo cat) {
        if (cat.isEmpty())
        {System.out.println("No se pueden mostrar datos de un catálogo vacío.\n");}
        else if (cat.get(0) instanceof Videojuego) {
            System.out.println("\t----Listado de videojuegos----");
            cat.mostrarDatos();
        }
    }

    /*------------------------------------------------------------------------*/
    // Funciones extra: 1/1
    public static String pedirTitulo() {
        Errores error = new Errores();
        boolean ejec;
        String res = null;
        
        InputStreamReader stream = new InputStreamReader(System.in);
        BufferedReader teclado = new BufferedReader(stream);

        do {
            try {
                ejec = false;
                res = teclado.readLine();

                if (res.length() > 40 || res.isEmpty()) {
                    throw error;
                }
            } catch (IOException e) {
                System.out.println("\n\tError en la entrada de datos.");
                System.out.println("\nIntroduzca el título:");
                ejec = true;
            } catch (Errores e) {
                e.invalidStr();
                System.out.println("\nIntroduzca el título:");
                ejec = true;
            }
        } while (ejec);
        
        return res;
    }
}