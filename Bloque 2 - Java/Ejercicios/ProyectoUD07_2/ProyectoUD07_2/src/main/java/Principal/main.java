package Principal;

import Catalogos.*;
import Objetos.*;
import Errores.Errores;
import java.io.*;
import java.util.*;

public class main {
    
    public static void main(String[] args) {
        Catalogo catCanciones = new Catalogo<Cancion>();
        Catalogo catJuegos = new Catalogo<Videojuego>();
        int opcion;
        
        do {
            opcion = menu();
            System.out.println("Ejecutando opción " + opcion + "...\n-----------\n");
            ejecutarOpcion(opcion, catCanciones, catJuegos);
        } while (opcion != 10);
    }
    /*------------------------------------------------------------------------*/
    // Funciones del menú: 2/2
    public static int menu() {
        // Muestra el menú y lee la opción a escoger.
        int opcion = 0;
        
        System.out.println("-------------MENU-------------");
        System.out.println("Canciones:");
        System.out.println("1. \tAlta de canción");
        System.out.println("2. \tBaja de canción");
        System.out.println("3. \tModificar canción");
        System.out.println("4. \tLista de canciones");
        System.out.println("");
        System.out.println("Videojuegos:");
        System.out.println("5. \tAlta de videojuego");
        System.out.println("6. \tBaja de videojuego");
        System.out.println("7. \tModificar videojuego");
        System.out.println("8. \tLista de videojuegos");
        System.out.println("");
        System.out.println("9. \tMostrar ambos catálogos");
        System.out.println("");
        System.out.println("10. \tSalir");
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
        } while (opcion < 1 || opcion > 10);
        
        return opcion;
    }
    
    public static void ejecutarOpcion(int opcion, Catalogo catCanciones, Catalogo catJuegos) {
        switch (opcion) {
            case 1 ->  {
                darAlta(catCanciones, opcion);
            }
            case 2 ->  {
                try {darBaja(catCanciones);}
                catch (Errores e) {e.catVacio();}
            }
            case 3 ->  {
                try{modificar(catCanciones, opcion);}
                catch (Errores e) {e.catVacio();}
            }
            case 4 ->  {
                mostrarDatos(catCanciones);
            }
            case 5 ->  {
                darAlta(catJuegos, opcion);
            }
            case 6 ->  {
                try {darBaja(catJuegos);}
                catch (Errores e) {e.catVacio();}
            }
            case 7 ->  {
                try{modificar(catJuegos, opcion);}
                catch (Errores e) {e.catVacio();}
            }
            case 8 ->  {
                mostrarDatos(catJuegos);
            }
            case 9 ->  {
                mostrarDatos(catCanciones);
                mostrarDatos(catJuegos);
            }
        }
    }
    
    /*------------------------------------------------------------------------*/
    // Funciones de alta, baja, y modificación: 2/2
    public static void darAlta(Catalogo cat, int opc) {
        if (cat.isEmpty())
        {
            if (opc == 5) {
                // Código para insertar un videojuego
                insertarVideojuego(cat);
            }
            else if (opc == 1) {
                // Código para insertar una canción
                insertarCancion(cat);
            }
        }
        else if (cat.get(0) instanceof Videojuego) {
            // Código para insertar un videojuego
            insertarVideojuego(cat);
        }
        else if (cat.get(0) instanceof Cancion) {
            // Código para insertar una canción
            insertarCancion(cat);
        }
    }
    
    public static void darBaja(Catalogo cat) throws Errores {
        // No se puede eliminar un objeto si la lista está vacía
        if (cat.isEmpty())
            throw new Errores();
        
        else if (cat.get(0) instanceof Videojuego) {
            // Código para eliminar un videojuego
            eliminarVideojuego(cat);
        }
        else if (cat.get(0) instanceof Cancion) {
            // Código para eliminar una canción
            eliminarCancion(cat);
        }
    }
    
    public static void modificar(Catalogo cat, int opc) throws Errores{
        if (cat.isEmpty())
            throw new Errores();
        else if (cat.get(0) instanceof Videojuego) {
            // Código para insertar un videojuego
            modificarVideojuego(cat);
        }
        else if (cat.get(0) instanceof Cancion) {
            // Código para insertar una canción
            modificarCancion(cat);
        }
    }
    
    /*-----*/ 
    // Funciones de alta, baja, y modificación de juegos: 1/2
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
    
    public static void eliminarVideojuego(Catalogo cat) {
        // Pedimos el título a eliminar:
        System.out.println("Título a eliminar: ");
        String tituloElim = pedirTitulo();
        boolean elim = false; // Bandera para saber si hemos eliminado algún juego.
        Iterator iter = cat.iterator();
        Videojuego aux;
        
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
    
    public static void modificarVideojuego(Catalogo cat) {
        // Preguntamos por el título del videojuego a modificar
        System.out.println("Título del videojuego a modificar: ");
        String tituloElim = pedirTitulo();
        boolean modif = false; // Bandera para saber si hemos modificado algún juego
        Iterator iter = cat.iterator();
        int cont = 0;
        Videojuego aux;
        
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

    /*-----*/
    // Funciones de alta, baja, y modificación de las canciones: 1/2
    public static void insertarCancion(Catalogo cat) {
        // Inicializamos la canción que vamos a insertar:
        Cancion cancion = new Cancion();

        // Si es el primer dato
        if (cat.isEmpty()) {
            cat.add(cancion);
        }
        
        //Vamos a buscar la posición en la que vamos a meter la canción.
        else 
        {
            Iterator iter = cat.iterator();
            int cont = 0;
            boolean flag = false;
            Cancion aux;
            
            while (iter.hasNext()) {
                aux = (Cancion) iter.next(); // Hay que hacer casting por alguna razón.
                if (aux.getTitulo().charAt(0) >= cancion.getTitulo().charAt(0)) {
                    cat.add(cont, cancion);
                    flag = true;
                    break;
                }
                else cont ++;
            }
            
            if (!flag)
                cat.add(cancion);
        }
    }

    public static void eliminarCancion(Catalogo cat) {
        // Pedimos el título a eliminar:
        System.out.println("Título a eliminar: ");
        String tituloElim = pedirTitulo();
        boolean elim = false; // Bandera para saber si hemos eliminado alguna canción.
        Iterator iter = cat.iterator();
        Cancion aux;
        
        // Buscamos dicho título en el array
        while (iter.hasNext()) {
            aux = (Cancion) iter.next();
            if (aux.getTitulo().toLowerCase().equals(tituloElim.toLowerCase())) {
                iter.remove();
                System.out.println("Canción eliminada.\n");
                elim = true;
                break;
            }
        }
        
        if (!elim)
            System.out.println("No existe dicha canción.\n");
    }
    
    public static void modificarCancion(Catalogo cat) {
        // Preguntamos por el título de la canción a modificar
        System.out.println("Título de la canción a modificar: ");
        String tituloElim = pedirTitulo();
        boolean modif = false; // Bandera para saber si hemos modificado alguna canción
        Iterator iter = cat.iterator();
        int cont = 0;
        Cancion aux;
        
        // Buscamos dicho título en el array
        while (iter.hasNext()) {
            aux = (Cancion) iter.next();
            // Si la encontramos, creamos una nueva canción y la insertamos en esa posición
            if (aux.getTitulo().toLowerCase().equals(tituloElim.toLowerCase())) {
                Cancion nueva = new Cancion();
                cat.set(cont, nueva);
                System.out.println("Canción modificada.\n");
                modif = true;
                break;
            }
            cont++;
        }
        
        if (!modif)
            System.out.println("No existe dicha canción.\n");
    }

    /*------------------------------------------------------------------------*/
    // Funciones para mostrar datos del catálogo: 1/1
    public static void mostrarDatos(Catalogo cat) {
        if (cat.isEmpty())
        {System.out.println("No se pueden mostrar datos de un catálogo vacío.\n");}
        else if (cat.get(0) instanceof Cancion) {
            System.out.println("\t----Listado de canciones----");
            cat.mostrarDatos();
        }
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