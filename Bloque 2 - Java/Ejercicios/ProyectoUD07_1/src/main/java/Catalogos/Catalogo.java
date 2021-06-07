package Catalogos;

import Objetos.*;
import java.util.*;

public class Catalogo {
    // Atributos
    private Collection canciones = new ArrayList<Cancion>();
    private Collection videojuegos = new ArrayList<Videojuego>();
    
    // Constructores: 2/2
    public Catalogo() {} // Dejamos un constructor vacío, no hace falta inicializar
                         // ningún valor.
    
    public Catalogo(Collection catCanc, Collection catJuegos) {
        setCatCanciones((ArrayList)catCanc);
        setCatVideojuegos((ArrayList)catJuegos);
    }
    
    // Setters: 2/2
    public void setCatCanciones(ArrayList catCanc) {
        // Se asume que el catálogo dado por parámetros ya está ordenado.
        // Esta función no se va a usar, de todas maneras.
        Iterator iter = catCanc.iterator();
        
        while (iter.hasNext()) {
            this.canciones.add(iter.next());
        }
    }
    
    public void setCatVideojuegos(ArrayList catJuegos) {
        // Se asume que el catálogo dado por parámetros ya está ordenado.
        // Esta función no se va a usar, de todas maneras.
        Iterator iter = catJuegos.iterator();
        
        while (iter.hasNext()) {
            this.videojuegos.add(iter.next());
        }
    }
    
    // Getters: 2/2
    public ArrayList getCanciones() {
        return (ArrayList) this.canciones;
    }
    
    public ArrayList getVideojuegos() {
        return (ArrayList) this.videojuegos;
    }
    
    // Utilidades: 3/3    
    public void mostrarDatos() {
        // Solo hay que llamar a los otros dos métodos juntos
        mostrarCanciones();
        mostrarVideojuegos();
    }
    
    public void mostrarCanciones() {
        System.out.println("-----Canciones-----");
        
        Iterator iter = this.canciones.iterator();
        Cancion cancAux;
        
        while (iter.hasNext()) {
            cancAux = (Cancion) iter.next();
            cancAux.mostrarDatos();
            System.out.println("-----");
        }
    }
    
    public void mostrarVideojuegos() {
        System.out.println("-----Videojuegos-----");
        
        Iterator iter = this.videojuegos.iterator();
        Videojuego juegoAux;
        
        while (iter.hasNext()) {
            juegoAux = (Videojuego) iter.next();
            juegoAux.mostrarDatos();
            System.out.println("-----");
        }
    }
}