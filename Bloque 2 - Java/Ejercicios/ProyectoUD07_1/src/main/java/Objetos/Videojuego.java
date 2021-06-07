package Objetos;

import Errores.Errores;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public final class Videojuego extends Objeto {
    // Atributos
    private String desarrolladora;
    private float precio;
    private int cantPlat;
    private String plataformas[]; // Como no hemos dado enum, se usará una función 
                               // para controlar su valor.
    
    /*------------------------------------------------------------------------*/
    // Constructor: 
    public Videojuego() {
        setTitulo();
        setDesarrolladora();
        setFecha();
        setPrecio();
        setPlataforma();
    }
    
    /*------------------------------------------------------------------------*/
    // Setters:
    public void setTitulo() {
        // Prácticamente el mismo que de Cancion.
        // Usaremos una flag para seguir preguntando al usuario si no ha introducido
        // bien los datos. Además, creamos un objeto Errores para lanzarlo si es
        // necesario. Esto se va a repetir en todos los setters.
        boolean ejec;
        Errores error = new Errores();
        
        InputStreamReader stream = new InputStreamReader(System.in);
        BufferedReader teclado = new BufferedReader(stream);
        
        do {
            try {
                ejec = false;

                System.out.println("\n\tIntroduzca el título del videojuego (40 car. max.):");
                this.titulo = teclado.readLine();

                // Comprobar que el dato introducido es válido.
                if ((this.titulo.length() > 40) || (this.titulo.equals("")))
                    throw error;
            }
            catch (IOException e) {
                System.out.println("\nError en la entrada de datos.");
                ejec = true;
            }
            catch (Errores e) {
                e.invalidStr();
                ejec = true;
            }
        } while (ejec);
    }
    
    public void setDesarrolladora() {
        boolean ejec;
        Errores error = new Errores();
        
        InputStreamReader stream = new InputStreamReader(System.in);
        BufferedReader teclado = new BufferedReader(stream);
        
        do {
            try {
                ejec = false;

                System.out.println("\n\tIntroduzca el nombre de la empresa desarrolladora (40 car. max.):");
                this.desarrolladora = teclado.readLine();

                // Comprobar que el dato introducido es válido.
                if ((this.desarrolladora.length() > 40) || (this.desarrolladora.equals("")))
                    throw error;
            }
            catch (IOException e) {
                System.out.println("\nError en la entrada de datos.");
                ejec = true;
            }
            catch (Errores e) {
                e.invalidStr();
                ejec = true;
            }
        } while (ejec);
    }
    
    public void setFecha() {
        boolean ejec;
        String cad;
        
        InputStreamReader stream = new InputStreamReader(System.in);
        BufferedReader teclado = new BufferedReader(stream);
        
        do {
            try {
                ejec = false;
                
                System.out.println("\n\tIntroduzca la fecha de lanzamiento (DD/MM/YYYY): ");
                cad = teclado.readLine();
                this.fecha = new Fecha(Integer.parseInt(cad.substring(0, 2)),
                    Integer.parseInt(cad.substring(3, 5)), 
                    Integer.parseInt(cad.substring(6, 10)));
            }
            catch (IOException e) {
                System.out.println("\n\tError en la entrada de datos.");
                ejec = true;
            }
            catch (NumberFormatException e) {
                System.out.println("\n\tError: Se han introducido caracteres no válidos o de forma incorrecta.");
                ejec = true;
            } 
            catch (StringIndexOutOfBoundsException e) {
                System.out.println("\n\tError: Datos incorrectos.");
                ejec = true;
            }
            catch (Errores e)
            {
                e.invalidDate(); // Control de la excepción propagada desde Fecha.
                ejec = true;
            }
        } while (ejec);
    }
    
    public void setPrecio() {
        boolean ejec;
        Errores error = new Errores();
        
        InputStreamReader stream = new InputStreamReader(System.in);
        BufferedReader teclado = new BufferedReader(stream);
        
        do {
            try {
                ejec = false;
                
                System.out.println("\n\tIntroduzca el precio del videojuego (separador decimal \".\"):");
                this.precio = Float.parseFloat(teclado.readLine());

                // Comprobar que el dato introducido es válido.
                if (this.precio < 0f)
                    throw error;
            }
            catch (IOException e) {
                System.out.println("\n\tError en la entrada de datos.");
                ejec = true;
            }
            catch (NumberFormatException e) {
                System.out.println("\n\tError: formato de número incorrecto.");
                ejec = true;
            }
            catch (Errores e) {
                e.invalidPrice();
                ejec = true;
            }
        } while (ejec);
    }
    
    private void setCantPlat() {
        boolean ejec;
        Errores error = new Errores();
        
        InputStreamReader stream = new InputStreamReader(System.in);
        BufferedReader teclado = new BufferedReader(stream);
        
        do {
            try {
                ejec = false;

                System.out.println("\tIntroduzca la cantidad de plataformas (1-5):");
                this.cantPlat = Integer.parseInt(teclado.readLine());

                if ((this.cantPlat < 1) || (this.cantPlat > 5))
                    throw error;
            } 
            catch (IOException e) {
                System.out.println("\n\tError en la entrada de datos.");
                ejec = true;
            }
            catch (NumberFormatException e) {
                System.out.println("\n\tError: Se han introducido caracteres no válidos.");
                ejec = true;
            }
            catch (Errores e) {
                e.invalidCantPlat();
                ejec = true;
            }
        } while (ejec);
    }
    
    public void setPlataforma() {
        int i;
        boolean ejec;
        Errores error = new Errores();
        
        setCantPlat(); // Pedimos la cantidad de plataformas.
        
        this.plataformas = new String[this.cantPlat]; // Inicializamos el array.
        
        InputStreamReader stream = new InputStreamReader(System.in);
        BufferedReader teclado = new BufferedReader(stream);
        
        do {
            try {
                ejec = false;
                
                for (i = 0; i < this.cantPlat; i++)
                {                
                    System.out.println("\n\tIntroduzca la plataforma " + (i+1) + "(Windows, Mac, Linux, "
                            + "PlayStation o Xbox): ");
                    this.plataformas[i] = teclado.readLine();

                    if (!checkPlataforma(this.plataformas[i]))
                        throw error;
                }
            }
            catch (IOException e) {
                System.out.println("\n\tError en la entrada de datos.");
                ejec = true;
            }
            catch (Errores e)
            {
                e.invalidPlatform();
                ejec = true;
            }
        } while (ejec);
    }
    
    /*------------------------------------------------------------------------*/
    // Getters:
    public String getTitulo() {
        return this.titulo;
    }
    
    public String getDesarrolladora() {
        return this.desarrolladora;
    }
    
    public Fecha getFecha() {
        return this.fecha;
    }
    
    public float getPrecio() {
        return this.precio;
    }
    
    public String[] getPlataformas() {
        return this.plataformas;
    }
    
    /*------------------------------------------------------------------------*/
    // Checkers:
    private boolean checkPlataforma(String plataforma) {
        boolean esValida = false;
        
        if (plataforma.toLowerCase().equals("windows") ||
                plataforma.toLowerCase().equals("mac") ||
                plataforma.toLowerCase().equals("linux") ||
                plataforma.toLowerCase().equals("playstation") ||
                plataforma.toLowerCase().equals("xbox"))
            esValida = true;
        
        return esValida;
    }
    
    /*------------------------------------------------------------------------*/
    // Mostrar los datos:
    public void mostrarDatos() {
        int i;
        System.out.println("\tTítulo: " + this.titulo);
        System.out.println("\tDesarrolladora: " + this.desarrolladora);
        System.out.println("\tPrecio: " + this.precio + "€");
        System.out.println("\tFecha de lanzamiento: " + Fecha.toStr(this.fecha));
        for (i = 0; i < this.cantPlat; i++)
            System.out.println("\tPlataforma " + (i+1) + ": " + this.plataformas[i]);
    }
    
    public String toString() {
        String cad;
        
        cad = this.titulo + "\n";
        cad += this.desarrolladora + "\n";
        cad += "Fecha de lanzamiento: " + this.fecha + "\n";
        cad += "Plataformas: ";
        for (int i = 0; i < this.plataformas.length; i++)
            cad += this.plataformas[i] + ", ";
        cad += "\nFecha de estreno: " + this.fecha;
        cad += "\nPrecio: " + this.precio + "€";
        
        return cad;
    }
}