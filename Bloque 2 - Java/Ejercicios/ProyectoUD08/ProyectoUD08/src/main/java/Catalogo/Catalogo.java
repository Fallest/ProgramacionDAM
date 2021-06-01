package Catalogo;

import java.util.*;

public class Catalogo<T> {
    // Atributos
    private ArrayList<T> catalogo = new ArrayList<T>();
    
    /*---------------------------------------------------------------*/// 2/2
    // Constructores
    public Catalogo() {}
    
    public Catalogo(Collection cat) {
        setCat((ArrayList<T>)cat);
    }
    
    /*---------------------------------------------------------------*/// 4/4
    // Setters
    public void setCat(ArrayList cat) {
        // Se asume que el catálogo dado por parámetros ya está ordenado.
        // Esta función no se va a usar, de todas maneras.
        Iterator iter = cat.iterator();
        
        while (iter.hasNext()) {
            this.catalogo.add((T) iter.next());
        }
    }
    
    public void add(T elem) {
        this.catalogo.add(elem);
    }
    
    public void add(int pos, T elem) {
        this.catalogo.add(pos, elem);
    }
    
    public void set(int pos, T elem) {
        this.catalogo.set(pos, elem);
    }
    
    /*---------------------------------------------------------------*/// 2/2
    // Getters
    public ArrayList getCat() {
        return this.catalogo;
    }
    
    public T get(int pos) {
        return (T) this.catalogo.get(pos);
    }
    
    /*---------------------------------------------------------------*/// 3/3
    // Utilidades
    public void mostrarDatos() {
        Iterator iter = this.catalogo.iterator();
        T elemCat;
        
        while (iter.hasNext()) {
            elemCat = (T) iter.next();
            System.out.println(elemCat.toString()); // La clase Objeto deberá tener un método abstracto para el soString.
            System.out.println("-----");
        }
    }
    public boolean isEmpty() {
        return this.catalogo.isEmpty();
    }
    
    public Iterator iterator() {
        return this.catalogo.iterator();
    }
}