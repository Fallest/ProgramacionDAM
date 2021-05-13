package Interfaces_14;

public class Revista extends Publicacion {
    // Atributos: hereda los de publicación
    private int numRevista;
    
    // Constructor
    Revista(int cod, String titulo, int añoPubli, int numRevis) {
        setCod(cod);
        setTitulo(titulo);
        setAñoPubli(añoPubli);
        setNumRevista(numRevis);
    }

    // Setters
    // Los setters de Publicación se sobre escriben aquí.
    public void setCod(int cod) {
        this.cod = cod;
    }

    public void setTitulo(String titulo) {
        this.titulo = titulo;
    }

    public void setAñoPubli(int añoPubli) {
        this.añoPubli = añoPubli;
    }

    public void setNumRevista(int numRevis) {
        this.numRevista = numRevis;
    }
    
    // Getters
    public int getCod() {return this.cod;}
    
    public String getTitulo() {return this.titulo;}
    
    public int getAñoPubli() {return this.añoPubli;}
    
    public int getNumrevista() {return this.numRevista;}
    
    // toString
    public String toString() {
        return "Código: " + this.cod + 
                " / Número de revista: " + this.numRevista
                + "\nTítulo " + this.titulo 
                + " - Año de publicación: " + this.añoPubli ;
    }
}
