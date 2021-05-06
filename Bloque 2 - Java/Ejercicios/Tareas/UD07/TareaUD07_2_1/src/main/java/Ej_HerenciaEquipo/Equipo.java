package Ej_HerenciaEquipo;

public class Equipo extends Empresa {
    // Atributos
    private int cantTempCat;
    private int posTemp;
    private boolean ganador;
    private Jugador[] jugadores;
    
    // Constructor
    Equipo() {
        // Llamada al constructor de la superclase (implícito)
        setCantTempCat();
        setPosTemp();
        setGanador();
        setJugadores();
    }
    
    // Setters
    void setCantTempCat() {
        System.out.println("Introduzca la cantidad de temporadas que lleva el equipo en esta categoría: ");
        this.cantTempCat = Leer.datoInt();
    }
    
    void setPosTemp() {
        System.out.println("Introduzca la posición del equipo en la última temporada: ");
        this.posTemp = Leer.datoInt();
    }
    
    void setGanador() {
        String win;
        
        System.out.println("¿Ha ganado el equipo algún campeonato?(s/n)");
        win = Leer.dato();

        if ("s".equals(win))
            this.ganador = true;
        else
            this.ganador = false;
    }
    
    void setJugadores() {
        int cantJugadores;
        
        do {
            System.out.println("Introduzca la cantidad de jugadores que conforman el equipo (max 20): ");
            cantJugadores = Leer.datoInt();
        } while (cantJugadores < 0 || cantJugadores > 20); // Se permiten menos de 12
        
        this.jugadores = new Jugador[cantJugadores];
    }
    
    //Getters
    int getCantTempCat() 
    {return this.cantTempCat;}
    
    int getPosTemp() 
    {return this.posTemp;}
    
    boolean getGanador()
    {return this.ganador;}
    
    Jugador[] getJugadores() 
    {return this.jugadores;}
    
    // Utilidades
    public void mostrarDatos() {
        super.mostrarDatos();
        System.out.println("\tCantidad de temporadas en esta categoría: " + this.cantTempCat);
        System.out.println("\tPosición en la temporada pasada: " + this.posTemp);
        System.out.println("\tHa ganado algún campeonato: " + this.ganador);
    }
    
    public void mostrarJugadores() {
        for (int i = 0; i < this.jugadores.length; i++) {
            if (this.jugadores[i] != null) {
                System.out.println("Jugador número " + (i+1) + ": ");
                this.jugadores[i].mostrarDatos();
            }
        }
    }
}
