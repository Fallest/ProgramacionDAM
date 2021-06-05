package CCuenta;

// Autor: David Bernal Navarrete

import java.io.*;

/*
    La gran cantidad de los comentarios están en la clase main.
    Si surge alguna duda con la clase, no dudéis en preguntar.
    Y mucho ánimo.
*/

public class CCuenta {
    private static int codContador = 0;
    private int codCuenta;
    private float saldo;
    private String titular, tipo;
    private static float interes;
    
    CCuenta()
    {}
    
    CCuenta(int i)
    {
        setCodCuenta();
        setSaldo();
        setTitular();
        setTipo();
        setInteres();
    }
    
    CCuenta(String type)
    {
        setCodCuenta();
        setSaldo();
        setTitular();
        setInteres();
        setTipo(type);
    }
    
    /*-------------------------------*/
    /*Setters*/
    public void setCodCuenta()
    {   
        // Como es automática no requiere interacción con el usuario.
        CCuenta.codContador++;
        this.codCuenta = CCuenta.codContador;
    }
    
    public void setSaldo()
    {
        // Setter del saldo que se pedirá al usuario.
        String cadaux = "";
        boolean ejec = true;
        InputStreamReader stream = new InputStreamReader(System.in);
        BufferedReader teclado = new BufferedReader(stream);
        
        do {
            try
            {
                System.out.println("\nIntroduzca el saldo de la cuenta (separador decimal '.'): ");
                cadaux = teclado.readLine();
                this.saldo = Float.parseFloat(cadaux);
                ejec = false;
            }
            catch(NumberFormatException e)
            {
                System.out.println("\nHa ocurrido un error. Se ha introducido una cadena.");
            }
            catch(IOException e)
            {
                System.out.println("\nHa ocurrido un error en la entrada de datos. Saliendo del programa...");
                System.exit(0);
            }
        } while(ejec);
    }
    
    public void setSaldo(float sal)
    {
        // Setter del saldo con parámetros.
        this.saldo = sal;
    }
    
    public void setTitular()
    {
        // Setter del titular que se pedirá al usuario.
        boolean ejec = true;
        InputStreamReader stream = new InputStreamReader(System.in);
        BufferedReader teclado = new BufferedReader(stream);
        
        do {
            try
            {
                System.out.println("\nIntroduzca el titular de la cuenta: ");
                this.titular = teclado.readLine();
                ejec = false;
            }
            catch(IOException e)
            {
                System.out.println("\nHa ocurrido un error en la entrada de datos. Saliendo del programa...");
                System.exit(0);
            }
        } while(ejec);
    }
    
    public void setTitular(String titul)
    {
        // Setter del titular con parámetros.
        this.titular = titul;
    }
    
    public void setTipo(String type)
    {
        // Setter del tipo con parámetros.
        this.tipo = type;
    }
    
    public void setTipo()
    {
        // Setter del tipo que se pedirá al usuario.
        boolean ejec = true;
        String cadaux = "";
        InputStreamReader stream = new InputStreamReader(System.in);
        BufferedReader teclado = new BufferedReader(stream);
        
        do {
            try
            {
                System.out.println("\nIntroduzca el tipo de la cuenta ('c' para corriente, 'a' para ahorros): ");
                cadaux = teclado.readLine();
                switch(cadaux)
                {
                    case "c":
                    {
                        this.tipo = "corriente";
                        ejec = false;
                        break;
                    }
                    case "a":
                    {
                        this.tipo = "ahorros";
                        ejec = false;
                        break;
                    }
                    default:
                    {
                        System.out.println("\nSe ha introducido una cadena no válida. Introduzca una correcta.");
                    }
                }
            }
            catch(IOException e)
            {
                System.out.println("\nHa ocurrido un error en la entrada de datos. Saliendo del programa...");
                System.exit(0);
            }
        } while(ejec);
    
    }
    
    public static void setInteres(float inter)
    {
        // Setter del interes de la cuenta con parámetros.
        CCuenta.interes = inter;
    }
    
    public void setInteres()
    {
        // Setter del interes de la cuenta preguntando al usuario.
        boolean ejec = true;
        String cadaux = "";
        InputStreamReader stream = new InputStreamReader(System.in);
        BufferedReader teclado = new BufferedReader(stream);
        
        do {
            try
            {
                System.out.println("\nIntroduzca el interés (usando '.' como separador de decimales): ");
                cadaux = teclado.readLine();
                
                CCuenta.interes = Float.parseFloat(cadaux);
                ejec = false;
            }
            catch(NumberFormatException e)
            {
                System.out.println("\nHa ocurrido un error en la entrada de datos. Por favor, asegúrese de que la entrada es correcta.");
            }
            catch(IOException e)
            {
                System.out.println("\nHa ocurrido un error en la entrada de datos. Saliendo del programa...");
                System.exit(0);
            }
        } while(ejec);
    }
    
    
    /*-------------------------------*/
    /*Getters*/
    /* this hace referencia al propio objeto de la clase. Básicamente es hablar de sí mismo.
    Es como si pusiéramos cuenta.codCuenta, pero para hacerlo dentro de la propia clase
    existe this.*/
    public int getCodCuenta()
    {return this.codCuenta;}
    
    public float getSaldo()
    {return this.saldo;}
    
    public static float getInteres()
    {return CCuenta.interes;} // Se usa el nombre de la clase porque es un método estático.

    public String getTipo()
    {return this.tipo;}
    
    public String getTitular()
    {return this.titular;}
    
    
    
}
