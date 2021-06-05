package Main;

import java.io.*;

public class Alumno
{
    private int notas[] = new int[5]; // Todo alumno est� matriculado en cinco m�dulos.
    private String nombre;
    private int edad;
    static private float costeTitulo; // Para que sepan cu�nto les va a costar el t�tulo.

    public Alumno()
    {
    }

    public Alumno(char pedir) // Para distinguirlo del constructor por defecto se le pone algo que lo distinga (el par�metro char, por ejemplo).
    {
        pedirTodosLosDatos();
    }

    public Alumno(int ed)
    {
        this.pedirNombre();
        this.pedirNotas();
        edad = ed;
    }

    public static void pedirCosteTitulo()
    {
        int entraCorrec = 0;
        String costeTituloCad;

        do {
            System.out.println("\n\tIndica cual es el coste del titulo: ");
            costeTituloCad = pedirCadena();
            try
            {
                costeTitulo = Integer.parseInt(costeTituloCad);
                entraCorrec = 1;
            }
            catch(NumberFormatException e)
            {
                System.out.println("\n\tSe han insertado letras en vez de numeros. Por favor, intentalo de nuevo.");
            }
        }while (entraCorrec == 0);
    }

    public static void inicializarCosteTitulo(float coste)
    {
        costeTitulo = coste;
    }

    public static String pedirCadena()
    {
        String cadena="fallo";
        InputStreamReader flujo = new InputStreamReader(System.in);
        BufferedReader teclado = new BufferedReader(flujo);

        try
        {
            cadena = teclado.readLine();
        }
        catch(IOException e)
        {
            System.out.println("Ha habido un error en la entrada de datos. Salimos del programa.");
            System.exit(0);
        }
        finally
        {
            return cadena;
        }
    }

    public void pedirNotas()
    {
        int pos, entracorrec;
        String cadnota;

        System.out.println("\n\tVamos a insertar las cinco notas que tiene el alumno " + nombre + ": ");

        for(pos = 0; pos < 5; pos++)
        {
            entracorrec = 0;
            do{
                System.out.println("\n\tInserta la nota " + (pos + 1) + ": ");
                cadnota = pedirCadena();
                try
                {
                    notas[pos] = Integer.parseInt(cadnota);
                    if (notas[pos] < 1 || notas[pos] > 10)
                        System.out.println("\n\tSe ha insertado una nota que no est� entre 0 y 10. Por favor, intentalo de nuevo.");
                    else
                        entracorrec = 1;
                }
                catch (NumberFormatException e)
                {
                    System.out.println("\n\tSe han insertado letras en vez de numeros. Por favor, intentalo de nuevo.");
                }
            }while (entracorrec == 0);
        }
    }

    public void pedirNotaConcreta (int pos)
    {
        int entracorrec = 0;
        String cadnota;

        System.out.println("\n\tVamos a insertar la nota de " + nombre + " (que corresponde al modulo " + pos + "): ");

        do{
            System.out.println("\n\tInserta dicha nota: ");
            cadnota = pedirCadena();
            try
            {
                notas[pos-1] = Integer.parseInt(cadnota);
                if (notas[pos-1] < 1 || notas[pos-1] > 10)
                    System.out.println("\n\tSe ha insertado una nota que no est� entre 0 y 10. Por favor, intentalo de nuevo.");
                else
                    entracorrec = 1;
            }
            catch (NumberFormatException e)
            {
                System.out.println("\n\tSe han insertado letras en vez de numeros. Por favor, intentalo de nuevo.");
            }
        }while (entracorrec == 0);
    }

    public void pedirNotaConcreta()
    {
        int entraCorrec = 0, pos = 0;
        String cadPos;

        do{
            System.out.println("\n\tIndica la posicion del modulo del que quiere indicar la nota del alumno " + nombre + ": ");
            cadPos = pedirCadena();
            try
            {
                pos = Integer.parseInt(cadPos);
                if (pos < 1 || pos > 5)
                    System.out.println("\n\tSe ha insertado una posicion que no esta entre 1 y 5. Por favor, intentalo de nuevo.");
                else
                    entraCorrec = 1;
            }
            catch (NumberFormatException e)
            {
                System.out.println("\n\tSe han insertado letras en vez de numeros. Por favor, intentalo de nuevo.");
            }
        }while (entraCorrec == 0);

        pedirNotaConcreta(pos);
    }

    public void pedirNombre()
    {
        System.out.println("\n\tInserta el nombre del alumno: ");
        nombre = pedirCadena();
    }

    public void pedirEdad()
    {
        String cadedad;
        System.out.println("\n\tInserta la edad del alumno: ");
        cadedad = pedirCadena();
        edad = Integer.parseInt(cadedad);
    }

    public void pedirTodosLosDatos()
    {
        System.out.println("\n\tVamos a insertar los datos de un alumno nuevo: ");
        pedirNombre();
        pedirEdad();
        pedirNotas();
    }

    int devNumCaractNombre()
    {
        int tam;
        tam = nombre.length();
        return tam;
    }

    public void visualTodosDatos()
    {
        visualNombre();
        visualEdad();
        visualNotas();
        visualCosteTitulo();
    }

    public static void visualCosteTitulo()
    {
        System.out.println("\n\tEl coste del titulo es: " + costeTitulo);
    }

    public void visualNombre()
    {
        System.out.println("\n\tNombre: " + nombre);
    }

    public void visualEdad()
    {
        System.out.println("\n\tEdad: " + edad);
    }

    public void visualNotas()
    {
        int pos;
        System.out.println("\n\tNotas: ");
        for (pos = 0; pos < 5; pos++)
            System.out.println("\tNota " + (pos+1) + ": " + notas[pos]);
    }

    public float calcularMedia()
    {
        int pos, suma = 0;
        float media;

        for (pos = 0; pos < 5; pos++)
            suma = suma + notas[pos];

        media = (float) suma / 5;
        return media;
    }

    public char inicialNombre()
    {
        return nombre.charAt(0);
    }

    public int getNota(int pos)
    {
        return notas[pos-1];
    }

    public String getNombre()
    {
        return nombre;
    }
}