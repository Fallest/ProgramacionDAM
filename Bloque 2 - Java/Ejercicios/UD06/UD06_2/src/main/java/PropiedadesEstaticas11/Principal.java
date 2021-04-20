package PropiedadesEstaticas11;

import java.io.*;

public class Principal
{
    public static void main(String args[]) throws IOException
    {
        Autor autor1, autor2;

        autor1 = new Autor();
        autor2 = new Autor();

        autor1.pedirIRPF();
        autor1.pedirDatos();
        autor2.pedirDatos();

        visualDosAutores(autor1, autor2);

        System.out.println("\nVamos a pedir de nuevo el IRPF con el fin de comprobar que este cambio afecta a todos los autores.");

        autor2.pedirIRPF();
        visualDosAutores(autor1, autor2);
    }

    static void visualDosAutores(Autor autor1, Autor autor2)
    {
        System.out.println("\n\nVamos a visualizar los datos del autor 1: ");
        autor1.visualDatosAutor();
        System.out.println("\n\nVamos a visualizar los datos del autor 2: ");
        autor2.visualDatosAutor();
    }
}