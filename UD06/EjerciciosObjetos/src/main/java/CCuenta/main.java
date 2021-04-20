package CCuenta;

// Autor: David Bernal Navarrete

import java.io.*;

/*
    Antes de que te pongas a leer todo el código y a comerte la cabeza:
        Si sientes que tu cabeza no da para más, para un rato, toma el aire, 
                        DESCANSA.
    Y recuerda:
                Vísteme despacio, que tengo prisa.

    En resumen: tómate tu tiempo, porque darte prisa al final resulta en que te
    haces más líos, y al final tardas más en comprenderlo cuanto más rápido vayas.
*/

public class main {
    
    public static void main(String args[])
    {
        // Necesitamos crear dos cuentas diferentes, una corriente y una de ahorros.
        // Llamamos al constructor sin parámetros para que no pida ningún dato.
        // De pedir los datos se encargan los módulos creados.
        CCuenta cuentaCorriente = new CCuenta();
        CCuenta cuentaAhorros = new CCuenta();
        int opcion = 0;
        
        crearCuentaCorriente(cuentaCorriente);
        crearCuentaAhorros(cuentaAhorros);
        
        // Mostrar el menú que se nos pide.
        do {
            mostrarMenu();
            opcion = leerOpcion();
            ejecutarOpcion(opcion, cuentaCorriente, cuentaAhorros);
        } while(opcion != 7);
        
    }
    
    public static void crearCuentaCorriente(CCuenta cuenta)
    {
        /*Vamos a ir llamando a los métodos del objeto cuenta.
        Se nos exige que el usuario solo tenga que introducir el titular,
        así que el resto lo inicializamos nosotros con valores neutrales.*/
        System.out.println("\nCuenta corriente:");
        cuenta.setCodCuenta();
        cuenta.setSaldo(0);
        cuenta.setTitular();
        cuenta.setTipo("corriente");
        cuenta.setInteres(0.05f); // Esto es un 5%, la f es para indicar que es float
        
        // Salidas por pantalla para ver qué hemos hecho
        System.out.println("\nSe ha creado una cuenta con los siguientes datos: ");
        System.out.println("\tCódigo de cuenta: " + cuenta.getCodCuenta());
        System.out.println("\tSaldo de la cuenta: " + cuenta.getSaldo());
        System.out.println("\tTitular de la cuenta: " + cuenta.getTitular());
        System.out.println("\tTipo de cuenta: " + cuenta.getTipo());
        System.out.println("\tInterés de la cuenta: " + cuenta.getInteres());
    }
    
    public static void crearCuentaAhorros(CCuenta cuenta)
    {
        // Lo mismo que en el anterior método.
        System.out.println("\nCuenta de ahorros:");
        cuenta.setCodCuenta();
        cuenta.setSaldo(0);
        cuenta.setTitular();
        cuenta.setTipo("ahorros");
        cuenta.setInteres(0.05f); // Esto es un 5%, la f es para indicar que es float
        
        // Salidas por pantalla para ver qué hemos hecho
        System.out.println("\nSe ha creado una cuenta con los siguientes datos: ");
        System.out.println("\tCódigo de cuenta: " + cuenta.getCodCuenta());
        System.out.println("\tSaldo de la cuenta: " + cuenta.getSaldo());
        System.out.println("\tTitular de la cuenta: " + cuenta.getTitular());
        System.out.println("\tTipo de cuenta: " + cuenta.getTipo());
        System.out.println("\tInterés de la cuenta: " + cuenta.getInteres());
    }
    
    public static void mostrarMenu()
    {
        // Mostrar un menú bonito y currado (lo he sacado a prueba y error vaya)
        System.out.println("\n\t\t--MENU--");
        System.out.println("-----------------------------------------");
        System.out.println("|  1. Cambiar interés\t\t\t|");
        System.out.println("|  2. Mostrar datos de una cuenta\t|");
        System.out.println("|  3. Realizar un ingreso\t\t|");
        System.out.println("|  4. Realizar un reintegro\t\t|");
        System.out.println("|  5. Actualizar saldo \t\t\t|");
        System.out.println("|  6. Comparar dos cuentas\t\t|");
        System.out.println("|  7. Salir\t\t\t\t|");
        System.out.println("-----------------------------------------");
    }
    
    public static int leerOpcion()
    {
        // Para no usar punteros como en C, esta vez devolveremos el número de
        // la opción seleccionada para poder usarlo en ejecutarOpcion.
        // (Por eso en la declaración de la función pone "public static *int*"
        // El static es porque, como ya hemos visto en clase, no podemos llamar
        // a esta función desde otra función estática sin que esta también lo sea.
        // (La idea es que una función static solo puede llamar a funciones static).
        int opc = 0;
        String cadaux = "";
        
        // Esto es copiar y pegar en todos lados, cada vez que haga falta leer un dato
        InputStreamReader stream = new InputStreamReader(System.in);
        BufferedReader teclado = new BufferedReader(stream);
        
        do {
            /* El try-catch básicamente hace lo siguiente:
            En el bloque del try se intenta hacer una tarea concreta, que puede
            dar errores.
            Si este intento da un error, en vez de mostrarlo por pantalla y
            sacarnos del programa, el catch nos permite controlar el flujo de
            este error, pudiendo simplemente mostrar un mensaje y continuar
            con la ejecución normal del programa.
            El catch, a diferencia del try, recibe un parámetro, que es básicamente
            un objeto de tipo Exception, al cual le asignamos un nombre (e).
            Existen varios tipos de objetos Exception, pero con quedarnos con
            'NumberFormatException' e 'IOException' tendremos suficiente de momento.
            Como son muchos nombres y pueden resultar confusos, recomiento recordar
            cómo empiezan, y pulsar ctrl+espacio para que aparezca el completado
            de código, y nos aparecerán varias opciones (entre ella la que queramos
            poner la seleccionamos con las flechas y le damos a enter para que se
            ponga automáticamente).
            */
            try
            {
                System.out.println("\nIntroduzca una opción: ");
                // Siempre vamos a leer una cadena al principio, así que si lo que
                // buscamos recoger del teclado no es una cadena, tendremos que usar
                // una cadena auxiliar.
                cadaux = teclado.readLine(); // teclado es el objeto que se usa para recoger lo que escribimos,
                                            //  y uno se sus funcionalidades es readLine(), que lee hasta
                                            //  el próximo enter.

                /* Como lo que buscamos es un int y tenemos una cadena (cadaux),
                debemos convertir de String a Integer. Para ello, llamamos a la
                clase a la que queremos convertir, en este caso: Integer.
                Dicha clase tiene la funcionalidad parseInt(String a), que 
                convierte la cadena que le demos a un int, siempre que tenga
                el formato adecuado.
                Si no tiene el formato adecuado, nos lanzará la famosa excepción
                NumberFormatException, y el primer catch se encargará de "atraparla"
                y lidiar con ella. */
                opc = Integer.parseInt(cadaux);
            }
            catch(NumberFormatException e)
            {System.out.println("\nHa ocurrido un error. Por favor, introduzca un número.");}
            catch(IOException e)
            {
                System.out.println("\nHa ocurrido un error grave. Saliendo del programa...");
                System.exit(0); // Esto sale del programa con 0 segundos de retraso.
            }
        } while((opc < 1) || (opc > 7)); // Esto es como en C
    
        return opc;
    }
    
    public static void ejecutarOpcion(int opc, CCuenta cuentaCorriente, CCuenta cuentaAhorros)
    {
        // Para un manejo de opciones simple y eficiente desde el punto de vista
        // computacional no hay nada mejor que un maravilloso switch()
        boolean ejec = true;
        int cod, cont = 0;
        
        do {
            if (opc != 1 && opc != 7) // No queremos que lea el código si las opciones no lo necesitan
            {
                // Leemos el código con el que vamos a trabajar
                cod = leerCod();

                // Como solo trabajamos con dos cuentas, nos podemos permitir dividir la estructura así.
                // Básicamente tenemos una estructura switch para cada cuenta.
                if (cod == cuentaCorriente.getCodCuenta())
                {
                    switch(opc)
                    {
                        case 2:
                        {
                            mostrarDatos(cuentaCorriente);
                            break; // No olvidar que en cada case del switch hay que poner un break;
                        }
                        case 3:
                        {
                            hacerIngreso(cuentaCorriente);
                            break; // No olvidar que en cada case del switch hay que poner un break;
                        }
                        case 4:
                        {
                            hacerReintegro(cuentaCorriente);
                            break; // No olvidar que en cada case del switch hay que poner un break;
                        }
                        case 5:
                        {
                            actualizarSaldo(cuentaCorriente);
                            break; // No olvidar que en cada case del switch hay que poner un break;
                        }
                        case 6:
                        {
                            compararCuentas(cuentaCorriente, cuentaAhorros);
                            break; // No olvidar que en cada case del switch hay que poner un break;
                        }
                        // No hace falta poner case 7, porque el 7 lo maneja el do-while de la función main.
                    }
                    ejec = false;
                }
                else if (cod == cuentaAhorros.getCodCuenta())
                {
                    switch(opc)
                    {                        
                        case 2:
                        {
                            mostrarDatos(cuentaAhorros);
                            break; // No olvidar que en cada case del switch hay que poner un break;
                        }
                        case 3:
                        {
                            hacerIngreso(cuentaAhorros);
                            break; // No olvidar que en cada case del switch hay que poner un break;
                        }
                        case 4:
                        {
                            hacerReintegro(cuentaAhorros);
                            break; // No olvidar que en cada case del switch hay que poner un break;
                        }
                        case 5:
                        {
                            actualizarSaldo(cuentaAhorros);
                            break; // No olvidar que en cada case del switch hay que poner un break;
                        }
                        case 6:
                        {
                            compararCuentas(cuentaCorriente, cuentaAhorros);
                            break; // No olvidar que en cada case del switch hay que poner un break;
                        }
                        // No hace falta poner case 7, porque el 7 lo maneja el do-while de la función main.
                    }
                    ejec = false;
                }
                else
                {
                    // Si el programa ha llegado aquí es porque el código introducido por
                    // el usuario no existe.
                    System.out.println("\nHa ocurrido un error. Has introducido un código no válido o no existente.");
                    cont++;
                }
            }
            else if(opc == 1) // Porque si la opc es 1, no tenemos que leer el codCuenta (el interés es static).
            {cambiarInteres();}
            
            // No es necesario poner la opcion 7, porque lo que haría sería un continue;, y eso ya lo hace el programa sin necesidad de indicárselo.
            
        } while (ejec && cont < 3); // Un bucle para irritar al usuario preguntándole por códigos hasta que acierte, porque no tiene otra forma de salir :) (En realidad ahora añadiré un contador o algo)
    }
    
    public static void cambiarInteres()
    {
        boolean ejec = true;
        String cadaux = "";
        
        // Mostrar el valor que tiene antes de preguntar
        System.out.println("\nInterés anterior: " + CCuenta.getInteres());
        /* Nota: Como esta función es static, la función getInteres también DEBE ser
        static, por lo que ya he mencionado antes.*/
        
        // Vamos a leer datos, así que...
        InputStreamReader stream = new InputStreamReader(System.in);
        BufferedReader teclado = new BufferedReader(stream);
        
        // Volvemos a usar la misma estructura del try-catch dentro de un do-while.
        do {
            try
            {
                System.out.println("\nIntroduzca el nuevo interés (separador decimal '.'): ");
                cadaux = teclado.readLine();
                CCuenta.setInteres(Float.parseFloat(cadaux)); 
                /* Nota: Como esta función es static, la función setInteres también DEBE ser
                static, por lo que ya he mencionado antes.
                Nota 2: En la anterior sentencia (la que empieza por CCuenta) lo que he hecho ha
                sido evitar el uso de una variable extra, para almacenar el valor de la
                conversión de String a float de la cadaux. Básicamente lo he hecho
                directamente dentro de la función, y como se que devuelve un float
                (que es lo que necesito para setInteres) se puede hacer.*/
                ejec = false;
            }
            catch(NumberFormatException e)
            {System.out.println("\nHa ocurrido un error. Introduce un número válido.");}
            catch(IOException e)
            {
                System.out.println("\nHa ocurrido un error grave. Saliendo del programa...");
                System.exit(0);
            }
        } while(ejec);
    }
    
    public static void mostrarDatos(CCuenta cuenta)
    {
            System.out.println("\n\t---Datos de la cuenta---");
            System.out.println("\tCódigo de cuenta: " + cuenta.getCodCuenta());
            System.out.println("\tSaldo de la cuenta: " + cuenta.getSaldo());
            System.out.println("\tTitular de la cuenta: " + cuenta.getTitular());
            System.out.println("\tTipo de cuenta: " + cuenta.getTipo());
            System.out.println("\tInterés de la cuenta: " + CCuenta.getInteres()); 
            /*
            Nota: Alguien se habrá fijado en que en el getInteres se usa CCuenta en vez de cuenta.
            Alguien aún más atento se habrá dado cuenta de que estamos referenciando a la *clase*, 
            en vez de al objeto. Esto es porque getInteres es un método estático, y se le puede referir
            de las dos formas, siendo la más correcta usando la clase.
            Aunque el único alguien ahora mismo soy yo perdiendo la cabeza con este código. :)
            */
    }
    
    public static void hacerIngreso(CCuenta cuenta)
    {        
        boolean ejec = true;
        String cadaux = "";
        
        // Mostramos el saldo actual
        System.out.println("\nSaldo actual: " + cuenta.getSaldo());
        
        // Vamos a leer datos, así que...
        InputStreamReader stream = new InputStreamReader(System.in);
        BufferedReader teclado = new BufferedReader(stream);
        
        // Volvemos a usar la misma estructura del try-catch dentro de un do-while.
        do {
            try
            {
                System.out.println("\nIntroduzca el valor del ingreso (separador decimal '.'): ");
                cadaux = teclado.readLine();
                cuenta.setSaldo(cuenta.getSaldo() + Float.parseFloat(cadaux));
                /* Nota: Lo que he hecho ha sido evitar el uso de una variable
                extra, para almacenar el valor de la conversión de String a float 
                de la cadaux. Básicamente lo he hecho directamente dentro de la 
                función, y como se que devuelve un float
                (que es lo que necesito para setSaldo) se puede hacer.*/
                ejec = false;
            }
            catch(NumberFormatException e)
            {System.out.println("\nHa ocurrido un error. Introduce un número válido.");}
            catch(IOException e)
            {
                System.out.println("\nHa ocurrido un error grave. Saliendo del programa...");
                System.exit(0);
            }
        } while(ejec);
    }
    
    public static void hacerReintegro(CCuenta cuenta)
    {
        // Nota: Esta función y la anterior son básciamente iguales, solo cambia un par de cosas
        
        boolean ejec = true;
        String cadaux = "";
        
        // Mostramos el saldo actual
        System.out.println("\nSaldo actual: " + cuenta.getSaldo());
        
        // Vamos a leer datos, así que...
        InputStreamReader stream = new InputStreamReader(System.in);
        BufferedReader teclado = new BufferedReader(stream);
        
        // Volvemos a usar la misma estructura del try-catch dentro de un do-while.
        do {
            try
            {
                System.out.println("\nIntroduzca el valor del ingreso (separador decimal '.'): ");
                cadaux = teclado.readLine();
                cuenta.setSaldo(cuenta.getSaldo() - Float.parseFloat(cadaux));
                /* Nota: Lo que he hecho ha sido evitar el uso de una variable
                extra, para almacenar el valor de la conversión de String a float 
                de la cadaux. Básicamente lo he hecho directamente dentro de la 
                función, y como se que devuelve un float
                (que es lo que necesito para setSaldo) se puede hacer.*/
                
                // Aquí lo que hago es comprobar si el nuevo saldo de la cuenta es negativo
                // (uso 0f para indicar que estoy comparando floats)
                if (cuenta.getSaldo() < 0f)
                    System.out.println("\n\t\tLa cuenta está en números rojos.");
                
                ejec = false;
            }
            catch(NumberFormatException e)
            {System.out.println("\nHa ocurrido un error. Introduce un número válido.");}
            catch(IOException e)
            {
                System.out.println("\nHa ocurrido un error grave. Saliendo del programa...");
                System.exit(0);
            }
        } while(ejec);
    }
    
    public static void actualizarSaldo(CCuenta cuenta)
    {
        // Nota: Esta función y la anterior son básciamente iguales, solo cambia un par de cosas
        
        boolean ejec = true;
        String cadaux = "";
        
        // Mostramos el saldo actual
        System.out.println("\nSaldo actual: " + cuenta.getSaldo());
        
        // Vamos a leer datos, así que...
        InputStreamReader stream = new InputStreamReader(System.in);
        BufferedReader teclado = new BufferedReader(stream);
        
        // Volvemos a usar la misma estructura del try-catch dentro de un do-while.
        do {
            try
            {
                System.out.println("\nIntroduzca el nuevo valor del saldo (separador decimal '.'): ");
                cadaux = teclado.readLine();
                cuenta.setSaldo(Float.parseFloat(cadaux));
                
                // Aquí lo que hago es comprobar si el nuevo saldo de la cuenta es negativo
                // (uso 0f para indicar que estoy comparando floats)
                if (cuenta.getSaldo() < 0f)
                    System.out.println("\n\t\tLa cuenta está en números rojos.");
                
                ejec = false;
            }
            catch(NumberFormatException e)
            {System.out.println("\nHa ocurrido un error. Introduce un número válido.");}
            catch(IOException e)
            {
                System.out.println("\nHa ocurrido un error grave. Saliendo del programa...");
                System.exit(0);
            }
        } while(ejec);
    }
    
    public static void compararCuentas(CCuenta cuenta1, CCuenta cuenta2)
    {
        if (cuenta1.getSaldo() > cuenta2.getSaldo())
        {
            System.out.println("\nLa cuenta corriente tiene más saldo que la cuenta de ahorros.");
            System.out.println("\nLa diferencia entre las dos es: " + (cuenta1.getSaldo() - cuenta2.getSaldo()));
        }
        else if (cuenta1.getSaldo() < cuenta2.getSaldo())
        {
            System.out.println("\nLa cuenta de ahorros tiene más saldo que la cuenta corriente.");
            System.out.println("\nLa diferencia entre las dos es: " + (cuenta2.getSaldo() - cuenta1.getSaldo()));
        }
        else
        {
            System.out.println("\nLas cuentas tienen el mismo saldo.");
            System.out.println("\nEl saldo que ambas tienen es: " + cuenta1.getSaldo());
        }
    }
    
    public static int leerCod()
    {
        boolean ejec = true;
        String cadaux = "";
        int cod = 0;
        
        // Vamos a leer datos, así que...
        InputStreamReader stream = new InputStreamReader(System.in);
        BufferedReader teclado = new BufferedReader(stream);
        
        // Volvemos a usar la misma estructura del try-catch dentro de un do-while.
        do {
            try
            {
                System.out.println("\nIntroduzca el código de la cuenta: ");
                cadaux = teclado.readLine();
                cod = Integer.parseInt(cadaux);
                ejec = false;
            }
            catch(NumberFormatException e)
            {System.out.println("\nHa ocurrido un error. Introduce un número válido.");}
            catch(IOException e)
            {
                System.out.println("\nHa ocurrido un error grave. Saliendo del programa...");
                System.exit(0);
            }
        } while(ejec);
        
        return cod;
    }
}
