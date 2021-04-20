package Liberacion13;

import java.io.*;

public class Principal
{
    public static void main(String args[]) throws IOException,InterruptedException
    {
        Hijo hijomayor;
        hijomayor = mayor();
        System.out.println("\nLlamamos a la funci�n recolectora.");
        System.gc();
        Thread.sleep(100);  // Para asegurar que se activa el recolector, parando el programa.
        System.out.println("\nYa hemos llamado a la funci�n recolectora.");

        /* Vemos que libera el espacio del objeto que ten�a la edad m�s joven. No se libera el espacio
        de otro objeto, ya que el objeto hijomayor apunta a dicho espacio, significando con ello que
        dicho espacio de memoria todav�a puede ser utilizado en cualquier momento. */

        System.out.println("\n\n\tLos datos del hijo mayor de los dos son: ");
        hijomayor.visualNombre();
        hijomayor.visualAnioNac();
    }

    static Hijo mayor()
    {
        Hijo hijo1, hijo2;
        hijo1 = new Hijo();
        hijo2 = new Hijo();

        if(hijo1.getAnioNac()<hijo2.getAnioNac())
            return hijo1;
        else
            return hijo2;
    }
}