package ProyectoJavaUD06;

public class Errores extends Exception {
    
    void invalidStr () {
        System.out.println("\n\tError - Cadena no válida: Está vacía o es demasiado larga (1 - 40 caracteres).");
    }
    
    void invalidDate() {
        System.out.println("\n\tError - Fecha no válida: Día, mes, o año fuera de rango.");
    }
    
    void invalidPrice() {
        System.out.println("\n\tError - Precio no válido: Precio negativo.");
    }
    
    void invalidCantArtistas() {
        System.out.println("\n\tError - Número no válido: Ningún o demasiados artistas (1 - 6).");
    }
    
    void invalidCantPlat() {
        System.out.println("\n\tError - Número no válido: Ningúna o demasiadas plataformas (1 - 5).");
    }
    
    void invalidPlatform() {
        System.out.println("\n\tError - Plataforma no válida: La plataforma debe ser \"Windows\", "
                + "\"Mac\", \"Linux\", \"PlayStation\", o \"Xbox\"");
    }
    
    void invalidCatTam() {
        System.out.println("\n\tError - Número no válido: Pocos o demasiados objetos de catálogo (5 - 80).");
    }
    
    void catLleno() {
        System.out.println("\n\tError - Catálogo completo: Borre elementos para introducir más.");
    }
    
    void catVacio() {
        System.out.println("\n\tError - Catálogo vacío: Introduzca elementos para borrar alguno.");
    }
}