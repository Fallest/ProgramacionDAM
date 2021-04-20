package Liberacion13;

import java.io.*;

public class Hijo
{
    String nombre;
    int anioNac;

    public int getAnioNac()
    {
        return anioNac;
    }

    public Hijo()
    {
        pedirNombre();
        pedirAnioNac();
    }

    public void visualDatosHijo()
    {
        System.out.println("\n\tLos datos del hijo son: ");
        visualNombre();
        visualAnioNac();
    }

    public void visualNombre()
    {
        System.out.println("\n\tNOMBRE: " + nombre);
    }

    public void visualAnioNac()
    {
        System.out.println("\n\tA�O DE NACIMIENTO: " + anioNac);
    }

    public void pedirNombre()
    {
        System.out.println("\n\tIndique el nombre del hijo: ");
        nombre = pedirCadena();
    }

    String pedirCadena()
    {
        String cadena="";
        InputStreamReader flujo = new InputStreamReader(System.in);
        BufferedReader teclado = new BufferedReader(flujo);

        try
        {
          cadena = teclado.readLine();
        }
        catch(IOException e)
        {
          System.out.println("Ha habido un error en la entrada de datos. Salimos del programa.");
          System.exit(1);
        }

        return cadena;
    }

    void pedirAnioNac()
    {
        String var;
        System.out.println("\n\tIndique el a�o de nacimiento: ");
        var = pedirCadena();
        anioNac = Integer.parseInt(var);
    }

    protected void finalize()
    {
        System.out.println("\n\tSe ha liberado un objeto de la clase HIJO. Sus datos son: ");
        visualNombre();
        visualAnioNac();
    }
}