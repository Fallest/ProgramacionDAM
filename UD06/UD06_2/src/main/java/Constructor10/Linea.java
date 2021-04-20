package Constructor10;

import java.io.*;

public class Linea
{
    public Linea(int tam, char caracter)
    {
        int cont;
        System.out.print("\t\t");
        for(cont=1; cont<=tam; cont++)
            System.out.print(caracter);
    }
}