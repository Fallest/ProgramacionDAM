package Tarea_09;

import java.io.*;
import java.util.*;

public class main3 {

    public static void main(String[] args) throws IOException
    {
        int c;
        File file = new File("tarea_09/fichero.txt");
        String nombre = file.getName();
        String direc = file.getAbsolutePath();
        Map<Character, Integer> dictAscii;
        dictAscii = new HashMap<>();
        
	try
	{            
            FileInputStream f = new FileInputStream(file); // Vale / o \ //
            // Buscara en la raiz del disco donde esta el proyecto, si no pongo la barra buscara en la carpeta actual //

            while ((c=f.read()) != -1) {
                System.out.print((char)c); // Si no se hace la conversion visualiza su codigo ASCII //
                
                if (dictAscii.containsKey((char) c))
                    dictAscii.put((char) c, dictAscii.get((char) c) + 1);
                else
                    dictAscii.put((char) c, 1);
            }
	}
	catch (FileNotFoundException e)
	{
	  System.out.println("\nEl ficher " + nombre + " no existe en " + direc + "\n");
	}
        
        System.out.println("\nConteo de elementos ASCII en el texto: ");
        dictAscii.entrySet().forEach(ch -> {
            if (ch.getKey() != '\n' && ch.getKey() != ' ')
                System.out.println(ch.getKey() + ": " + ch.getValue() + " veces.");
        });
    }
}