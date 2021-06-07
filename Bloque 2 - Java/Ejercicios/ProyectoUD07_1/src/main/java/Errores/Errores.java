package Errores;

public class Errores extends Exception {
    
    public void invalidStr () {
        System.out.println("\n\tError - Cadena no válida: Está vacía o es demasiado larga (1 - 40 caracteres).");
    }
    
    public void invalidDate() {
        System.out.println("\n\tError - Fecha no válida: Día, mes, o año fuera de rango.");
    }
    
    public void invalidPrice() {
        System.out.println("\n\tError - Precio no válido: Precio negativo.");
    }
    
    public void invalidCantArtistas() {
        System.out.println("\n\tError - Número no válido: Ningún o demasiados artistas (1 - 6).");
    }
    
    public void invalidCantPlat() {
        System.out.println("\n\tError - Número no válido: Ningúna o demasiadas plataformas (1 - 5).");
    }
    
    public void invalidPlatform() {
        System.out.println("\n\tError - Plataforma no válida: La plataforma debe ser \"Windows\", "
                + "\"Mac\", \"Linux\", \"PlayStation\", o \"Xbox\"");
    }
    
    public void catVacio() {
        System.out.println("\n\tError - Catálogo vacío: Introduzca elementos para borrar alguno.");
    }
}