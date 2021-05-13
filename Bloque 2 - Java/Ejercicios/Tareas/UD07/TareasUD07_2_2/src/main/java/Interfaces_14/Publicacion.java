package Interfaces_14;

public abstract class Publicacion {
    // Atributos
    protected int cod;
    protected String titulo;
    protected int añoPubli;
    
    // Constructor vacío, esta clase no se puede instanciar (es abstract)
    // Eso no significa que no se puede escribir nada, sino que no se puede
    // hacer new a esta clase.
    Publicacion() {}
    
    // Setters sin código (se implementan en los hijos)
    public abstract void setCod(int cod);
    
    public abstract void setTitulo(String titulo);
    
    public abstract void setAñoPubli(int añoPubli);
    
    // Getters
    public abstract int getCod();
    
    public abstract String getTitulo();
    
    public abstract int getAñoPubli();
    
    // Método toString(), se implementa en los hijos
    public abstract String toString();
}
