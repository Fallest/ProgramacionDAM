package Ej_HerenciaEquipo;

public class Errores extends Exception {
    
    void invalidDate() {
        System.out.println("\n\tError - Fecha no válida: Día, mes, o año fuera de rango.");
    }
}