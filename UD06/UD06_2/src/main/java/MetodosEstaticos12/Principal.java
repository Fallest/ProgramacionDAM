package MetodosEstaticos12;

import java.io.*;

public class Principal
{
    public static void main(String args[]) throws IOException
    {
        Cuenta cliente1, cliente2;
        cliente1 = new Cuenta();
        cliente2 = new Cuenta();
        Cuenta.pedirBenef();  // o bien cliente1.pedirBenef() o incluso cliente2.pedirBenef(), pero es enga�oso.
        visDosClientes(cliente1, cliente2);

        cliente1.ingresar();
        cliente2.ingresar();

        System.out.println("\n\nLos datos de los clientes, tras los ingresos, son: ");
        visDosClientes(cliente1, cliente2);

        System.out.println("\n\nLa empresa modifica el beneficio que da a sus clientes.");
        Cuenta.pedirBenef();
        System.out.println("\n\nLos datos de los clientes, tras el cambio de beneficios, son: ");
        visDosClientes(cliente1, cliente2);
    }

    static void visDosClientes(Cuenta cliente1, Cuenta cliente2)
    {
        System.out.println("\nLos datos del cliente 1 son: ");
        cliente1.visualDatosCuenta();
        System.out.println("\nLos datos del cliente 2 son: ");
        cliente2.visualDatosCuenta();
    }
}