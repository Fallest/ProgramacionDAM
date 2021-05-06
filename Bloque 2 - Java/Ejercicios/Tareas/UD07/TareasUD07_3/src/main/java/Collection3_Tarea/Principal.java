package Collection3_Tarea;

import java.util.*;

public class Principal {

    public static void main(String[] args ) {
        // Creamos las dos colecciones: ArrayList y LinkedList
        Collection col1 = new ArrayList();
        Collection col2 = new LinkedList();
        
        // Objeto que será común a las dos colecciones
        Integer comun = new Integer(10);
        
        // Introducimos algunos datos en col1 de tipo Integer
        col1.add(new Integer(5));
        col1.add(new Integer(30));
        col1.add(new Integer(41));
        col1.add(new Integer(23));
        col1.add(comun);
        
        // Introducimos algunos datos en col2 de tipo String, pero añadimos el común
        col2.add(new String("a"));
        col2.add(new String("b"));
        col2.add(new String("c"));
        col2.add(new String("d"));
        col2.add(comun);
        
        // Vamos a mostrar los datos que tiene cada una
        mostrarDatos(col1);
        mostrarDatos(col2);
        
        // Añadimos a la col1 los elementos de col2
        addDatos(col1, col2);
        
        // Vamos a mostrar los datos que tiene cada una
        mostrarDatos(col1);
        mostrarDatos(col2);
        
        // Borramos de col1 los nodos que no estén en col2
        deleteDatos(col1, col2);
        
        // Vamos a mostrar los datos que tiene cada una
        mostrarDatos(col1);
        mostrarDatos(col2);
        
        // Borrar los nodos de col2 que estén en col1
        col1.removeAll(col2);
        
        // Vamos a mostrar los datos que tiene cada una
        mostrarDatos(col1);
        mostrarDatos(col2);
        
        // Borrar todos los hijos de col1
        col1.removeAll(col1);
    }
    
    public static void mostrarDatos(Collection lista) {
        Iterator iter1 = lista.iterator();
        int i = 0;
        
        while (iter1.hasNext()) {
            i++;
            System.out.println("Elemento " + i + ": " + iter1);
            iter1.next();
        }
    }
    
    public static void addDatos(Collection col1, Collection col2) {
        // Añade a la primera colección los datos de la segunda
        Iterator iter2 = col2.iterator();
        
        while(iter2.hasNext()) {
            col1.add(iter2);
            iter2.next();
        }
    }
    
    public static void deleteDatos(Collection col1, Collection col2) {
        // Elimina de col1 los nodos que no estén en col2
        Iterator iter1 = col1.iterator();
        
        while (iter1.hasNext()) {
            if (!col2.contains(iter1))  // Comprobar si existe o no el elemento de col1
                                        // en col2.
                col1.remove(iter1);
        }
    }
}
