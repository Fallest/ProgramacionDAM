package Principal;

import Catalogos.*;
import Objetos.*;
import Errores.Errores;
import java.io.*;
import java.util.*;

public class main {
    
    public static void main(String[] args) {
        Catalogo catalogo = new Catalogo();
        int opcion;
        
        do {
            opcion = menu();
            ejecutarOpcion(opcion, catalogo);
        } while (opcion != 8);
    }
    /*------------------------------------------------------------------------*/
    // Funciones del menú: 2/2
    public static int menu() {
        // Muestra el menú y lee la opción a escoger.
        int opcion = 0;
        
        System.out.println("-------------MENU-------------");
        System.out.println("1. \tAlta de canción");
        System.out.println("2. \tAlta de videojuego");
        System.out.println("3. \tBaja de canción");
        System.out.println("4. \tBaja de videojuego");
        System.out.println("5. \tMostrar catálogo completo");
        System.out.println("6. \tLista de canciones");
        System.out.println("7. \tLista de videojuegos");
        System.out.println("8. \tSalir");
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
        } while (opcion < 1 || opcion > 8);
        
        return opcion;
    }
    
    public static void ejecutarOpcion(int opcion, Catalogo catalogo) {
        switch (opcion) {
            case 1: {
                darAlta(catalogo.getCanciones(), opcion);
                break;
            }
            case 2: {
                darAlta(catalogo.getVideojuegos(), opcion);
                break;
            }
            case 3: {
                try {darBaja(catalogo.getCanciones());}
                catch (Errores e) {e.catVacio();}
                break;
            }
            case 4: {
                try {darBaja(catalogo.getVideojuegos());}
                catch (Errores e) {e.catVacio();}
                break;
            }
            case 5: {
                mostrarCatalogo(catalogo);
                break;
            }
            case 6: {
                mostrarDatos(catalogo.getCanciones(), opcion);
                break;
            }
            case 7: {
                mostrarDatos(catalogo.getVideojuegos(), opcion);
                break;
            }
        }
    }
    
    /*------------------------------------------------------------------------*/
    // Funciones de alta y baja: 2/2
    public static void darAlta(ArrayList lista, int opc) {
        if (lista.isEmpty())
        {
            if (opc == 2) {
                // Código para insertar un videojuego
                insertarVideojuego(lista);
            }
            else if (opc == 1) {
                // Código para insertar una canción
                insertarCancion(lista);
            }
        }
        else if (lista.get(0) instanceof Videojuego) {
            // Código para insertar un videojuego
            insertarVideojuego(lista);
        }
        else if (lista.get(0) instanceof Cancion) {
            // Código para insertar una canción
            insertarCancion(lista);
        }
    }
    
    public static void darBaja(ArrayList lista) throws Errores {
        Errores error = new Errores();
        
        // No se puede eliminar un objeto si la lista está vacía
        if (lista.isEmpty())
            throw error;
        
        else if (lista.get(0) instanceof Videojuego) {
            // Código para eliminar un videojuego
            eliminarVideojuego(lista);
        }
        else if (lista.get(0) instanceof Cancion) {
            // Código para eliminar una canción
            eliminarCancion(lista);
        }
    }
    
    /*-----*/ 
    // Funciones de alta y baja de juegos: 2/2
    public static void insertarVideojuego(ArrayList lista) {
        // Inicializamos el juego que vamos a insertar:
        Videojuego juego = new Videojuego();

        // Si es el primer dato
        if (lista.isEmpty()) {
            lista.add(juego);
        }
        
        //Vamos a buscar la posición en la que vamos a meter el juego.
        else 
        {
            Iterator iter = lista.iterator();
            int cont = 0;
            boolean flag = false;
            Videojuego aux;
            
            while (iter.hasNext()) {
                aux = (Videojuego) iter.next(); // Hay que hacer casting por alguna razón.
                if (Fecha.toInt(aux.getFecha()) <= Fecha.toInt(juego.getFecha())) {
                    lista.add(cont, juego);
                    flag = true;
                    break;
                }
            }
            
            if (!flag)
                lista.add(juego);
        }
    }
    
    public static void eliminarVideojuego(ArrayList lista) {
        // Pedimos el título a eliminar:
        System.out.println("Título a eliminar: ");
        String tituloElim = pedirTitulo();
        boolean elim = false; // Bandera para saber si hemos eliminado algún juego.
        Iterator iter = lista.iterator();
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

    /*-----*/
    // Funciones de alta y baja de las canciones: 2/2
    public static void insertarCancion(ArrayList lista) {
        // Inicializamos la canción que vamos a insertar:
        Cancion cancion = new Cancion();

        // Si es el primer dato
        if (lista.isEmpty()) {
            lista.add(cancion);
        }
        
        //Vamos a buscar la posición en la que vamos a meter la canción.
        else 
        {
            Iterator iter = lista.iterator();
            int cont = 0;
            boolean flag = false;
            Cancion aux;
            
            while (iter.hasNext()) {
                aux = (Cancion) iter.next(); // Hay que hacer casting por alguna razón.
                if (aux.getTitulo().charAt(0) >= cancion.getTitulo().charAt(0)) {
                    lista.add(cont, cancion);
                    flag = true;
                    break;
                }
                else cont ++;
            }
            
            if (!flag)
                lista.add(cancion);
        }
    }

    public static void eliminarCancion(ArrayList lista) {
        // Pedimos el título a eliminar:
        System.out.println("Título a eliminar: ");
        String tituloElim = pedirTitulo();
        boolean elim = false; // Bandera para saber si hemos eliminado alguna canción.
        Iterator iter = lista.iterator();
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

    /*------------------------------------------------------------------------*/
    // Funciones para mostrar datos del catálogo: 2/2
    public static void mostrarDatos(ArrayList lista, int opc) {
        if (lista.isEmpty())
        {System.out.println("No se pueden mostrar datos de un catálogo vacío.\n");}
        else if (lista.get(0) instanceof Videojuego) {
            Catalogo catAux = new Catalogo();
            catAux.setCatVideojuegos(lista);
            catAux.mostrarVideojuegos();
        }
        else if (lista.get(0) instanceof Cancion) {
            Catalogo catAux = new Catalogo();
            catAux.setCatCanciones(lista);
            catAux.mostrarCanciones();
        }
    }

    public static void mostrarCatalogo(Catalogo catalogo) {
        catalogo.mostrarDatos();
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
                System.out.println("\nIntroduzca el título:");
                res = teclado.readLine();

                if (res.length() > 40 || res.isEmpty()) {
                    throw error;
                }
            } catch (IOException e) {
                System.out.println("\n\tError en la entrada de datos.");
                ejec = true;
            } catch (Errores e) {
                e.invalidStr();
                ejec = true;
            }
        } while (ejec);
        
        return res;
    }
}