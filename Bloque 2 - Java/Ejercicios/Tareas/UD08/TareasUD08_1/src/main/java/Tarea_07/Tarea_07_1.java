package Tarea_07;

import java.io.*;
import java.util.*;

public class Tarea_07_1 {
    public static void main(String[] args) {
        String frase = "";
        ArrayList frases = new ArrayList();
        boolean fin = false;
        
        while (!fin) {
            try {
                frase = leerFrase();
            }
            catch(IOException e) {
                System.out.println("Error al introducir datos.");
            }
            frases.add(frase);
            fin = comprobarFrase(frase);    
        }
        System.out.println("\n");
        mostrarFrases(frases);
    }    

    private static String leerFrase() throws IOException {
        char c;
        
        System.out.println("Introduzca una frase: ");
        c = (char) System.in.read();
        String frase = new String();
        
        while (c != '\n') {
            frase = frase + c;
            c = (char) System.in.read();
        }
        
        return frase;
    }

    private static boolean comprobarFrase(String frase) {
        return frase.equals("fin");
    }

    private static void mostrarFrases(ArrayList frases) {
        Iterator iter = frases.iterator();
        
        System.out.println("Frases escritas: \n");
        
        while (iter.hasNext()) 
            System.out.println(iter.next());
    }
}
