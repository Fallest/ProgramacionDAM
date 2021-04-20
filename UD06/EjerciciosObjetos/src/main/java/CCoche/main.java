package CCoche;

// Autor: David Bernal Navarrete

import java.io.*;

public class main {
    public static void main(String args[])
    {
        boolean ejec = true;
        String key = "";
        CCoche coche = new CCoche();
        
        mostrarInstrucciones();
        
        InputStreamReader stream = new InputStreamReader(System.in);
        BufferedReader tecla = new BufferedReader(stream);
        
        do {
            try
            {
                System.out.println(">");
                key = tecla.readLine();
                
                switch (key)
                {
                    case "w":
                    {
                        coche.acelerar();
                        break;
                    }
                    case "s":
                    {
                        coche.frenar();
                        break;
                    }
                    case "q":
                    {
                        coche.subirMarcha();
                        break;
                    }
                    case "a":
                    {
                        coche.bajarMarcha();
                        break;
                    }
                    case "e":
                    {
                        coche.encenderElectronica();
                        break;
                    }
                    case "d":
                    {
                        coche.apagarElectronica();
                        break;
                    }
                    case "r":
                    {
                        coche.arrancarMotor();
                        break;
                    }
                    case "f":
                    {
                        coche.apagarMotor();
                        break;
                    }
                    case "g":
                    {
                        System.out.println("Introduzca la marcha que quiere poner: ");
                        key = tecla.readLine();
                        coche.ponerMarcha(Integer.parseInt(key));
                        break;
                    }
                    case "t":
                    {
                        coche.puntoMuerto();
                        break;
                    }
                    case "i":
                    {
                        mostrarInstrucciones();
                        break;
                    }
                    case "p":
                    {
                        ejec = false;
                        System.out.println("\nSaliendo del programa...");
                        break;
                    }
                }
            }
            catch(IOException e)
            {
                System.out.println("\nHa ocurrido un error. Vuelva a intentarlo.");
            }
        } while(ejec);
    }
    
    public static void mostrarInstrucciones()
    {
        System.out.println("\n\t\t---Instrucciones---");
        System.out.println("Todas las instrucciones se escriben y se ejecutan con enter.");
        System.out.println(" > w para acelerar");
        System.out.println(" > s para frenar");
        System.out.println(" > q para subir de marcha");
        System.out.println(" > a para bajar de marcha");
        System.out.println(" > e para encender la electrónica");
        System.out.println(" > d para apagar la electrónica");
        System.out.println(" > r para arrancar el motor");
        System.out.println(" > f para parar el motor");
        System.out.println(" > g para poner una marcha concreta");
        System.out.println(" > t para poner punto muerto");
        System.out.println("---------------------------");
        System.out.println(" > i para volver a ver las instrucciones");
        System.out.println(" > p para salir del programa");
        System.out.println("---------------------------");
        System.out.println("Para que el coche funcione se debe encender primero la electrónica y luego el motor.");
    }
}
