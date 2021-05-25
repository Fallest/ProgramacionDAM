package Objetos;

import Errores.Errores;

public abstract class Objeto {
    // Atributos
    protected String titulo;
    protected Fecha fecha;
    
    // Constructor vacío
    public Objeto() {}
    
    // Métodos abstractos
    public abstract void setTitulo();
    
    public void setTitulo(String titulo) {
        // Polimorfismo - Sobrecarga
        
        Errores error = new Errores();
        
        try {
            this.titulo = titulo;
            // Comprobar que el dato introducido es válido.
            if ((this.titulo.length() > 40) || (this.titulo.equals("")))
                throw error;
        }
        catch (Errores e) {
            e.invalidStr();
            setTitulo();
        }
    }
    
    public abstract void setFecha();
    
    public abstract String getTitulo();
    
    public abstract Fecha getFecha();
    
    public abstract void mostrarDatos();
    
    public abstract String toString();
    
    /*------------------------------------------------------------------------*/
    // Finalize:
    // Debido a que finalize se usa solo para borrar copias, no es necesario darle
    // funcionalidades extra.
    public void finalize() {}
}