package Objetos;

import Errores.Errores;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.Serializable;
import java.io.UnsupportedEncodingException;

public final class Videojuego implements Serializable {
    // Atributos
    private String titulo;
    private Fecha fecha;
    private String desarrolladora;
    private float precio;
    private int cantPlat;
    private Plataforma plataformas[];
    
    /*---------------------------------------------------------------*/// 2/2
    // Constructor: 
    public Videojuego() {
        setTitulo();
        setDesarrolladora();
        setFecha();
        setPrecio();
        setPlataforma();
    }
    
    public Videojuego(String titulo, String desarrolladora, String fecha, String precio, String plataformas) {
        setTitulo(titulo);
        setDesarrolladora(desarrolladora);
        setFecha(fecha);
        setPrecio(precio);
        setPlataforma(plataformas);
    }
    
    /*---------------------------------------------------------------*/// 11/11
    // Setters:
    public void setTitulo(String s) {
        this.titulo = s.trim();
    }
    
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
    /*------------------------------*/
    public void setDesarrolladora(String s) {
        this.desarrolladora = s.trim();
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
    /*------------------------------*/
    public void setFecha(String s) {
        try {
            this.fecha = Fecha.parseFecha(s.trim());
        } catch (Errores ex) {
            ex.invalidDate();
        }
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
                // He retirado la clase anónima para preservar el formato de la fecha original.
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
    /*------------------------------*/
    public void setPrecio(String s) {
        this.precio = Float.parseFloat(s.trim());
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
    /*------------------------------*/
    private void setCantPlat() {
        boolean ejec;
        Errores error = new Errores();
        
        InputStreamReader stream = new InputStreamReader(System.in);
        BufferedReader teclado = new BufferedReader(stream);
        
        do {
            try {
                ejec = false;

                System.out.println("\n\tIntroduzca la cantidad de plataformas (1-5):");
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
    
    public void setPlataforma(String s) {
        // La cadena viene dada como: Plataforma1, Plataforma2, Plataforma3, ...
        // Hay que separar por comas las diferentes plataformas
        String plats[] = s.split(",");
        this.plataformas = new Plataforma[plats.length];
        for (int i = 0; i < plats.length; i++) {
            try {
                this.plataformas[i] = Plataforma.convPlat(plats[i].trim());
            } 
            catch (Errores ex) {
                ex.invalidPlatform(plats[i].trim());
            }
        }
    }
    
    public void setPlataforma() {
        int i;
        boolean ejec;
        String aux;
        Errores error = new Errores();
        
        setCantPlat(); // Pedimos la cantidad de plataformas.
        
        this.plataformas = new Plataforma[this.cantPlat]; // Inicializamos el array.
        
        InputStreamReader stream = new InputStreamReader(System.in);
        BufferedReader teclado = new BufferedReader(stream);
        
        do {
            try {
                ejec = false;
                
                for (i = 0; i < this.cantPlat; i++)
                {                
                    System.out.println("\n\tIntroduzca la plataforma " + (i+1) + "(Windows, Mac, Linux, "
                            + "PlayStation o XBox): ");
                    // Método del enum Plataforma para convertir cadenas a Plataformas.
                    this.plataformas[i] = Plataforma.convPlat(teclado.readLine()); 
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
    
    /*---------------------------------------------------------------*/// 5/5
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
    
    public Plataforma[] getPlataformas() {
        return this.plataformas;
    }
    
    /*---------------------------------------------------------------*/// 4/4
    // Funciones auxiliares
    
    // Mostrar los datos:
    public void mostrarDatos() {
        int i;
        System.out.println("\tTítulo: " + this.titulo);
        System.out.println("\tDesarrolladora: " + this.desarrolladora);
        System.out.println("\tPrecio: " + this.precio + "€");
        System.out.println("\tFecha de lanzamiento: " + this.fecha.toStr(this.fecha));
        for (i = 0; i < this.cantPlat; i++)
            System.out.println("\tPlataforma " + (i+1) + ": " + this.plataformas[i]);
    }
    // Método toString:
    public String toString() {
        String cad;
        
        cad = this.titulo + "\n";
        cad += this.desarrolladora + "\n";
        cad += "Fecha de lanzamiento: " + this.fecha.toStr(this.fecha) + "\n";
        cad += "Plataformas: " + this.plataformas[0];
        for (int i = 1; i < this.plataformas.length; i++) {
            cad += " " + this.plataformas[i];
            if (i != this.plataformas.length - 1)
                cad += ", ";
        }
        cad += "\nPrecio: " + this.precio + "€";
        
        return cad;
    }
    
    // Método toBinary:
    public byte[] toBinary() throws UnsupportedEncodingException {
        // Creamos una cadena auxiliar para transformarla a bytes.
        String aux = (this.titulo + "; " 
                + this.desarrolladora + "; "
                + this.fecha.toStr(this.fecha) + "; "
                + this.precio + "; ");
        for (int i = 0; i < this.plataformas.length - 1; i++)
            aux += this.plataformas[i] + ", ";
        aux += this.plataformas[this.plataformas.length - 1] + "\n";
        
        return aux.getBytes("UTF-8");
    }
    
    // Método parseJuego:
    public static Videojuego parseJuego(String s) {
        // La cadena s es una cadena con el siguiente formato:
        // "Titulo; Desarrolladora; Fecha; Precio; Plataforma1, plataforma2, ..."
        String datos[] = s.split(";");
        
        return new Videojuego(datos[0], datos[1], datos[2], datos[3], datos[4]);
    }
}