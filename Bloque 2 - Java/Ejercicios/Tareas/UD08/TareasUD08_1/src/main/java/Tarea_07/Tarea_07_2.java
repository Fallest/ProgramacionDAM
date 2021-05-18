package Tarea_07;

import java.io.*;
import java.util.*;

public class Tarea_07_2 {
    public static void main(String[] args) throws IOException {
        ArrayList chars = new ArrayList();
        char cIni;
        char c;
        
        System.out.println("Introduzca el carácter inicial: ");
        cIni = pedirChar();
        System.out.println("Introduzca un carácter: ");
        c = pedirChar();
        
        while (c != cIni) {
            if (c != '\n') {
                System.out.println("Introduzca un carácter: ");
            }
            c = pedirChar();
            chars.add(c);
        }
        System.out.println("\n");
        mostrarFrase(chars);
    }    

    private static char pedirChar() throws IOException {
        char c;
        
        c = (char) System.in.read();
        
        return c;
    }

    private static void mostrarFrase(ArrayList chars) {
        Iterator iter = chars.iterator();
        String frase = "";
        
        while (iter.hasNext()) 
            frase = frase + iter.next();
        
        System.out.println("Frase: " + frase);
    }
}
