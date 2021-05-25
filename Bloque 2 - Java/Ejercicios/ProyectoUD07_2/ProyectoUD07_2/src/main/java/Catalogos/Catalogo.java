package Catalogos;

import java.util.*;

public class Catalogo<T> {
    // Atributos
    private ArrayList catalogo = new ArrayList<T>();
    
    // Constructores: 2/2
    public Catalogo() {}
    
    public Catalogo(Collection cat) {
        setCat((ArrayList)cat);
    }
    
    // Setters: 1/1
    public void setCat(ArrayList cat) {
        // Se asume que el catálogo dado por parámetros ya está ordenado.
        // Esta función no se va a usar, de todas maneras.
        Iterator iter = cat.iterator();
        
        while (iter.hasNext()) {
            this.catalogo.add(iter.next());
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
    
    // Getters: 2/2
    public ArrayList getCat() {
        return this.catalogo;
    }
    
    public T get(int pos) {
        return (T) this.catalogo.get(pos);
    }
    
    // Utilidades: 3/3    
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