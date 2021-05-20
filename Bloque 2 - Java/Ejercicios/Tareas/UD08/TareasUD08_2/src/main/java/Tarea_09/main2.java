package Tarea_09;

import java.io.*;

public class main2 {

    public static void main(String[] args) throws IOException
    {
        int c;
        File file = new File("tarea_09/fichero.txt");
        String nombre = file.getName();
        String direc = file.getAbsolutePath();
	try
	{            
            FileInputStream f = new FileInputStream(file); // Vale / o \ //
            // Buscara en la raiz del disco donde esta el proyecto, si no pongo la barra buscara en la carpeta actual //

            while ((c=f.read()) != -1)
                System.out.print((char)c); // Si no se hace la conversion visualiza su codigo ASCII //
	}
	catch (FileNotFoundException e)
	{
	  System.out.println("\nEl ficher " + nombre + " no existe en " + direc + "\n");
	}
    }
}