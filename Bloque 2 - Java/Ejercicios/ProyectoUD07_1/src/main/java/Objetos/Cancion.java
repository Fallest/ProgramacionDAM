package Objetos;

import Errores.Errores;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public final class Cancion extends Objeto {
    // Atributos
    private String artistas[];
    private int cantArtistas;
    
    /*------------------------------------------------------------------------*/
    // Constructor:
    //      Usamos solo uno porque no le daremos uso a otros.
    //      Con crear una clase con funciones completas es suficiente.
    public Cancion () {        
        setTitulo();
        setArtistas();
        setFecha();
    }
    
    /*------------------------------------------------------------------------*/
    // Setters: 
    public void setTitulo() {
        // Polimorfismo - Sobrecarga
        
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

                System.out.println("\n\tIntroduzca el título de la canción (40 car. max.):");
                this.titulo = teclado.readLine();

                // Comprobar que el dato introducido es válido.
                if ((this.titulo.length() > 40) || (this.titulo.equals("")))
                    throw error;
            }
            catch (IOException e) {
                System.out.println("\n\tError en la entrada de datos.");
                ejec = true;
            }
            catch (Errores e) {
                e.invalidStr();
                ejec = true;
            }
        } while (ejec);
    }
    
    private void setCantArtistas() {
        boolean ejec;
        Errores error = new Errores();
        
        InputStreamReader stream = new InputStreamReader(System.in);
        BufferedReader teclado = new BufferedReader(stream);
        
        do {
            try {
                ejec = false;

                System.out.println("\tIntroduzca la cantidad de artistas (1-6):");
                this.cantArtistas = Integer.parseInt(teclado.readLine());

                if ((this.cantArtistas < 1) || (this.cantArtistas > 6))
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
                e.invalidCantArtistas();
                ejec = true;
            }
        } while (ejec);
    }
    
    public void setArtistas() {
        int i;
        boolean ejec;
        Errores error = new Errores();
        
        setCantArtistas(); // Pedimos la cantidad de artistas.
        
        this.artistas = new String[this.cantArtistas]; // Inicializamos el array.
        
        InputStreamReader stream = new InputStreamReader(System.in);
        BufferedReader teclado = new BufferedReader(stream);
        
        do {
            try {
                ejec = false;
                
                // Asignar todos los artistas
                for (i = 0; i < this.artistas.length; i++)
                {
                    System.out.println("\n\tIntroduzca el nombre del artista " + (i+1) + " (40 car. max.):");
                    this.artistas[i] = teclado.readLine();
                    
                    // Comprobar que el dato introducido es válido, cada vez.
                    if ((this.artistas[i].length() > 40) || (this.artistas[i].isEmpty()))
                        throw error;
                }
            }
            catch (IOException e) {
                System.out.println("\n\tError en la entrada de datos.");
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
                
                System.out.println("\n\tIntroduzca la fecha de estreno (DD/MM/YYYY): ");
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
    
    /*------------------------------------------------------------------------*/
    // Getters:
    public String getTitulo() {
        return this.titulo;
    }
    
    public String[] getArtistas() {
        return this.artistas;
    }
    
    public Fecha getFecha() {
        return this.fecha;
    }
    
    /*------------------------------------------------------------------------*/
    // Mostrar los datos:
    public void mostrarDatos() {
        int i;
        System.out.println("\tTítulo: " + this.titulo);
        for (i = 0; i < cantArtistas; i++)
            System.out.println("\tArtista " + (i+1) + ": " + this.artistas[i]);
        System.out.println("\tFecha de estreno: " + Fecha.toStr(this.fecha));
    }

    public String toString() {
        String cad;
        
        cad = this.titulo + " - ";
        for (int i = 0; i < this.artistas.length; i++)
            cad += this.artistas[i];
        
        cad += "\nFecha de estreno: " + this.fecha;
        return cad;
    }
}