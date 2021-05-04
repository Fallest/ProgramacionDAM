package Ej_HerenciaEquipo;

public class Principal {
    public static void main(String[] args) {
        // Variables
        int opcion;
        Equipo[] equipos = new Equipo[20];
        
        // Bucle de ejecución para el menú
        do {
            mostrarMenu();
            opcion = leerOpcion();
            ejecutarOpcion(opcion, equipos);
        } while (opcion != 0);
    }
    
    private static void mostrarMenu() {
        System.out.println("-----MENU-----");
        
        System.out.println("1. Alta de equipo");
        System.out.println("2. Modificar datos de equipo");
        System.out.println("3. Alta de jugador");
        System.out.println("4. Listado de equipos");
        System.out.println("5. Listado de jugadores de un equipo");
        System.out.println("0. Salir");
        
        System.out.println("--------------");
    }
    
    private static int leerOpcion() {
        int op;
        
        do {
            System.out.println("Introduzca una opción: ");
            op = Leer.datoInt();
        } while (op < 0 || op > 5);
        
        return op;
    }
    
    private static void ejecutarOpcion(int op, Equipo[] equipos) {
        switch(op) {
            case 1:
                altaEquipo(equipos);
                break;
            case 2:
                modificarEquipo(equipos);
                break;
            case 3:
                altaJugador(equipos);
                break;
            case 4:
                listadoEquipos(equipos);
                break;
            case 5:
                listadoJugadoresEquipo(equipos);
                break;       
        }
    }
    
    private static void altaEquipo(Equipo[] equipos) {
        for (int i = 0; i < equipos.length; i++)
            if (equipos[i] == null) {
                System.out.println("Introduciendo equipo en la posición " + (i+1) + "...");
                equipos[i] = new Equipo();
                break;
            }
    }
    
    private static void menuModificar() {
        System.out.println("¿Qué quieres modificar del equipo?");
        System.out.println("1. CIF");
        System.out.println("2. Razón social");
        System.out.println("3. Ciudad");
        System.out.println("4. Cantidad de temporadas en una categoría");
        System.out.println("5. Posición de la última temporada");
        System.out.println("6. Ganador de campeonato\n");
    }
    
    private static void modificarEquipo(Equipo[] equipos) {
        int op;
        String cif;
        Jugador[] jugadoresAux;
        System.out.println("Introduzca el cif del equipo a modificar: ");
        cif = Leer.dato();
        
        do {
            menuModificar();
            op = Leer.datoInt();
        } while (op < 1 || op > 6);
        
        for (int i = 0; i < equipos.length; i++)
            if (equipos[i] != null && equipos[i].getCif().equals(cif)) {
                ejecutarMod(op, equipos[i]);
            }
    }
    
    private static void ejecutarMod(int op, Equipo equipo) {
        switch (op) {
            case 1:
                equipo.setCif();
                break;
            case 2:
                equipo.setRazSocial();
                break;
            case 3:
                equipo.setCiudad();
                break;
            case 4:
                equipo.setCantTempCat();
                break;
            case 5:
                equipo.setPosTemp();
                break;
            case 6:
                equipo.setGanador();
                break;
        }
    }
    
    private static void altaJugador(Equipo[] equipos) {
        String cif;
        Jugador[] jugadoresAux;
        System.out.println("Introduzca el cif del equipo en el que va a dar de alta un jugador: ");
        cif = Leer.dato();
        
        for (int i = 0; i < equipos.length; i++)
            if (equipos[i] != null && equipos[i].getCif().equals(cif)) {
                jugadoresAux = equipos[i].getJugadores();
                
                for (int j = 0; j < jugadoresAux.length; j++)
                    if (jugadoresAux[j] == null) {
                        System.out.println("Introduciendo un jugador en el equipo " +
                                (i+1) + " en la posición " + (j+1) + "...");
                        jugadoresAux[j] = new Jugador();
                        break;
                    }
            }
    }
    
    private static void listadoEquipos(Equipo[] equipos) {
        for (int i = 0; i < equipos.length; i++) {
            if (equipos[i] != null) {
                System.out.println("Equipo número " + (i+1) + ": ");
                equipos[i].mostrarDatos();
            }
        }
    }
    
    private static void listadoJugadoresEquipo(Equipo[] equipos) {
        String cif;
        System.out.println("Introduzca el cif del equipo: ");
        cif = Leer.dato();
        
        for (int i = 0; i < equipos.length; i++)
            if (equipos[i] != null && equipos[i].getCif().equals(cif)) {
                System.out.println("Jugadores del equipo con cif " + cif + ":");
                equipos[i].mostrarJugadores();
            }
    }
}
