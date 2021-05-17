package ProyectoJavaUD06;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Catalogo {
    // Los dos vectores son finales porque solo va a existir una copia de cada uno en main.
    private final Cancion canciones[];
    private final Videojuego videojuegos[];
    private static int tamCatalogo;
    
    /*------------------------------------------------------------------------*/
    // Constructor:
    Catalogo () {
        // Pedir el tamaño del catálogo.
        setTamCat();
        
        // Inicializar los vectores de cada tipo.
        this.canciones = new Cancion[tamCatalogo];
        this.videojuegos = new Videojuego[tamCatalogo];
    }
    
    /*------------------------------------------------------------------------*/
    // Setters:
    private void setTamCat() {
        boolean ejec;
        Errores error = new Errores();
        
        InputStreamReader stream = new InputStreamReader(System.in);
        BufferedReader teclado = new BufferedReader(stream);
        
        do {
            try {
                ejec = false;

                System.out.println("Introduzca el tamaño del catálogo (5-80):");
                this.tamCatalogo = Integer.parseInt(teclado.readLine());

                if ((this.tamCatalogo < 5) || (this.tamCatalogo > 80))
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
                e.invalidCatTam();
                ejec = true;
            }
        } while (ejec);
    }
    
    /*------------------------------------------------------------------------*/
    // Getters:
    public Cancion[] getCanciones() {
        return this.canciones;
    }
    
    public Videojuego[] getVideojuegos() {
        return this.videojuegos;
    }
    
    public int getTamCat() {
        return this.tamCatalogo;
    }
}