package Interfaces_14;

public class Libro extends Publicacion implements Prestable { 
    // Atributos: hereda los de publicación
    private boolean prestado = false;
    private Autor autor;
    
    // Constructor
    Libro(int cod, String titulo, int añoPubli, int numRevis) {
        setCod(cod);
        setTitulo(titulo);
        setAñoPubli(añoPubli);
        setAutor();
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
       
    public void setAutor() {
        this.autor = new Autor();
    }
    
    // Getters
    public int getCod() {return this.cod;}
    
    public String getTitulo() {return this.titulo;}
    
    public int getAñoPubli() {return this.añoPubli;}
    
    
    // toString
    public String toString() {
        return "Código: " + this.cod + 
                " / Presado: " + this.prestado
                + "\nTítulo " + this.titulo 
                + " - Año de publicación: " + this.añoPubli 
                + "\nAutor: " + this.autor;
    }

    // Métodos de la interfaz que SE TIENEN que implementar
    public void prestar() {
        if(this.prestado)
            System.out.println("No se puede prestar, ya está prestado.");
        else
            this.prestado = true;
    }

    public void devolver() {
        if(!this.prestado)
            System.out.println("No se puede devolver, ya está en la biblioteca.");
        else
            this.prestado = false;
    }
    
    public boolean prestado() {
        return this.prestado;
    }
}
