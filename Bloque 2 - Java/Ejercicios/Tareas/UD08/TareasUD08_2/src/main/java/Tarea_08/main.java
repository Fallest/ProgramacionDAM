package Tarea_08;

import java.io.*;

public class main {
    public static void main(String args[]) throws IOException {
        File archivExiste, archivNoExiste, dirExiste, dirNoExiste;
        archivExiste = new File("tarea_08/archivo.txt");
        archivNoExiste = new File("tarea_08/archivo2.txt");
        dirExiste = new File("tarea_08/directorio/");
        dirNoExiste = new File("tarea_08/directorio2/");
        
        System.out.println("Existe archivo 1: " + archivExiste.exists());
        System.out.println("Existe archivo 2: " + archivNoExiste.exists());
        System.out.println("Existe directorio 1: " + dirExiste.exists());
        System.out.println("Existe directorio 2: " + dirNoExiste.exists());
        
        System.out.println(archivExiste.getName() + " es archivo: " + archivExiste.getCanonicalPath().endsWith("txt"));
        System.out.println(dirExiste.getName() + " es archivo: " + dirExiste.getCanonicalPath().endsWith("txt"));
        
    }
}
