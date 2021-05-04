package Ej_HerenciaEquipo;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Jugador {
    // Atributos
    private String nombre;
    private int dorsal;
    private Fecha fechaNac;
    
    // Constructor
    Jugador() {
        setNombre();
        setDorsal();
        setFechaNac();
    }
    
    // Setters
    void setNombre() {
        System.out.println("\tIntroduzca el nombre del jugador: ");
        this.nombre = Leer.dato();
    }
    
    void setDorsal() {
        System.out.println("\tIntroduzca el dorsal del jugador: ");
        this.dorsal = Leer.datoInt();
    }
    
    void setFechaNac() {
        boolean ejec;
        String cad;
        
        InputStreamReader stream = new InputStreamReader(System.in);
        BufferedReader teclado = new BufferedReader(stream);
        
        do {
            try {
                ejec = false;
                
                System.out.println("\n\tIntroduzca la fecha de nacimiento (DD/MM/YYYY): ");
                cad = teclado.readLine();
                this.fechaNac = new Fecha(Integer.parseInt(cad.substring(0, 2)),
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
    
    // Getters
    String getNombre() 
    {return this.nombre;}
    
    int getDorsal() 
    {return this.dorsal;}
    
    Fecha getFecha() 
    {return this.fechaNac;}
    
    // Utilidades
    public void mostrarDatos() {
        System.out.println("\tNombre: " + this.nombre);
        System.out.println("\tDorsal: " + this.dorsal);
        System.out.println("\tFecha de nacimiento: " + Fecha.toStr(this.fechaNac));
    }
}
