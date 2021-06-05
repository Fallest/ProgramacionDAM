package CCoche;

// Autor: David Bernal Navarrete

import java.io.*;

/*
    En esta clase he implementado mucha más funciones de las necesarias, porque puedo.
    Cualquier duda, a preguntar.
*/

public class CCoche {
    // Atributos del coche
    private String marca, modelo, color;
    private int marcha = 0, velocidad = 0;
    private boolean electronicaOn = false;
    private boolean motorOn = false;
    
    CCoche()
    {
        setMarca();
        setModelo();
        setColor();
    }
    
    /*------------------------------------------------------*/
    /*Funcionalidades*/
    public void encenderElectronica()
    {
        if (!motorOn && !electronicaOn)
        {
            electronicaOn = true;
            System.out.println("\nSe ha encendido la electrónica.");
        }
        else if (!motorOn && electronicaOn)
            System.out.println("\nLa electrónica ya está encendida.");
        else 
            System.out.println("\nEl motor y la electrónica están en funcionamiento.");
    }
    
    public void arrancarMotor()
    {
        if (!motorOn && !electronicaOn)
        {
            encenderElectronica();
            System.out.println("\n\tSe ha arrancado el motor.");
            motorOn = true;
            marcha = 0;
            velocidad = 0;
        }
        else if (!motorOn && electronicaOn)
        {
            System.out.println("\nSe ha arrancado el motor.");
            motorOn = true;
            marcha = 0;
            velocidad = 0;
        }
        else
            System.out.println("\nEl motor ya está en funcionamiento.");
    }
    
    public void apagarElectronica()
    {
        if (motorOn && velocidad == 0)
        {
            apagarMotor();
            System.out.println("Se ha apagado la electrónica.");
            electronicaOn = false;
        }
        else if (!motorOn && electronicaOn && velocidad == 0)
        {
            System.out.println("Se ha apagado la electrónica.");
            electronicaOn = false;
        }
        else if (!electronicaOn)
            System.out.println("La electrónica ya está apagada.");
        else
        {
            System.out.println("Apagar el motor con el coche en movimiento es temerario.");
        }
    }
    
    public void apagarMotor()
    {
        if (motorOn && velocidad == 0)
        {
            System.out.println("El motor se ha parado.");
            motorOn = false;
        }
        else if (!motorOn)
            System.out.println("El motor ya está parado.");
        else
            System.out.println("Apagar el motor con el coche en movimiento es temerario.");
    }
    
    public void subirMarcha()
    {
        marcha++;
        switch(marcha)
        {
            case -1:
            {
                System.out.println("El coche está en marcha atrás.");
                break;
            }
            case 0:
            {
                System.out.println("El coche está en punto muerto.");
                break;
            }
            case 1:
            {
                System.out.println("El coche está en primera.");
                break;
            }
            case 2:
            {
                System.out.println("El coche está en segunda.");
                break;
            }
            case 3:
            {
                System.out.println("El coche está en tercera.");
                break;
            }
            case 4:
            {
                System.out.println("El coche está en cuarta.");
                break;
            }
            case 5:
            {
                System.out.println("El coche está en quinta.");
                break;
            }
            case 6:
            {
                System.out.println("El coche está en sexta.");
                break;
            }
            case 7:
                System.out.println("No puedes subir más marchas.");
                marcha--;
                break;
        }
    }
    
    public void bajarMarcha()
    {
        marcha--;
        switch(marcha)
        {
            case -2:
            {
                System.out.println("No puedes bajar más marchas.");
                marcha++;
                break;
            }
            case -1:
            {
                System.out.println("El coche está en marcha atrás.");
                break;
            }
            case 0:
            {
                System.out.println("El coche está en punto muerto.");
                break;
            }
            case 1:
            {
                System.out.println("El coche está en primera.");
                break;
            }
            case 2:
            {
                System.out.println("El coche está en segunda.");
                break;
            }
            case 3:
            {
                System.out.println("El coche está en tercera.");
                break;
            }
            case 4:
            {
                System.out.println("El coche está en cuarta.");
                break;
            }
            case 5:
            {
                System.out.println("El coche está en quinta.");
                break;
            }
            case 6:
            {
                System.out.println("El coche está en sexta.");
                break;
            }
        }
    }
    
    public void ponerMarcha(int m)
    {
        if ((m >= -1) && (m <= 6))
        {
            marcha = m;
            switch(marcha)
            {
                case -1:
                {
                    System.out.println("El coche está en marcha atrás.");
                    break;
                }
                case 0:
                {
                    System.out.println("El coche está en punto muerto.");
                    break;
                }
                case 1:
                {
                    System.out.println("El coche está en primera.");
                    break;
                }
                case 2:
                {
                    System.out.println("El coche está en segunda.");
                    break;
                }
                case 3:
                {
                    System.out.println("El coche está en tercera.");
                    break;
                }
                case 4:
                {
                    System.out.println("El coche está en cuarta.");
                    break;
                }
                case 5:
                {
                    System.out.println("El coche está en quinta.");
                    break;
                }
                case 6:
                {
                    System.out.println("El coche está en sexta.");
                    break;
                }
            }
        }
        else
            System.out.print("El coche no tiene esa marcha.");
        
    }
    
    public void puntoMuerto()
    {
        marcha = 0;
        System.out.println("El coche está en punto muerto.");
    }
    
    public void acelerar()
    {
        if (marcha >= 1)
        {
            velocidad += 10;
            if (velocidad < 0)
                System.out.println("O estás en pendiente o has tenido un día muy complicado.");
            else if (velocidad >= 0 && velocidad < 25)
                System.out.println("Aceleras hasta " + velocidad + " km/h.");
            else if (velocidad >= 20 && velocidad < 50)
                System.out.println("Aceleras hasta " + velocidad + " km/h. Límite permitido en poblado.");
            else if (velocidad >= 50 && velocidad < 75)
                System.out.println("Aceleras hasta " + velocidad + " km/h. Espero que estés en carretera.");
            else if (velocidad >= 75 && velocidad < 100)
                System.out.println("Aceleras hasta " + velocidad + " km/h. Ten cuidado.");
            else if (velocidad >= 100 && velocidad < 120)
                System.out.println("Aceleras hasta " + velocidad + " km/h. Límite establecido por la ley.");
            else if (velocidad >= 120 && velocidad < 180)
                System.out.println("Vas a " + velocidad + " km/h. Deberías tener cuidado...");
            else if (velocidad >= 180)
                System.out.println("Vas a " + velocidad + " km/h. El coche no puede acelerar más. Menos mal que no puede acelerar más.");
        }
        else if (marcha == 0)
        {
            System.out.println("No es una buena idea pisar el aceledador en punto muerto.");
        }
        else
        {
            velocidad -= 5;
            System.out.println("Estás yendo hacia atrás. Tú usa los retrovisores...");
        }
        
    }
    
    
    public void frenar()
    {
        if (velocidad - 10 > 0)
        {
            velocidad -= 10;
            if (velocidad < 0)
                System.out.println("O estás en pendiente o has tenido un día muy complicado.");
            else if (velocidad >= 0 && velocidad < 25)
                System.out.println("Frenas hasta " + velocidad + " km/h. Ha sido por el badén, no?");
            else if (velocidad >= 20 && velocidad < 50)
                System.out.println("Frenas hasta " + velocidad + " km/h. Límite permitido en poblado.");
            else if (velocidad >= 50 && velocidad < 75)
                System.out.println("Frenas hasta " + velocidad + " km/h. Espero que estés en carretera.");
            else if (velocidad >= 75 && velocidad < 100)
                System.out.println("Frenas hasta " + velocidad + " km/h. Ten cuidado.");
            else if (velocidad >= 100 && velocidad < 120)
                System.out.println("Frenas hasta " + velocidad + " km/h. Ya no eres una persona irresponsable.");
            else if (velocidad >= 120)
                System.out.println("Vas a " + velocidad + " km/h. Eso es lo que deberías haber hecho antes de ver el radar...");
        }
        else
        {
            velocidad = 0;
            System.out.println("Frenas y el coche está parado.");
        }
    }
    
    /*------------------------------------------------------*/
    /*Setters*/
    private void setMarca()
    {
        InputStreamReader stream = new InputStreamReader(System.in);
        BufferedReader teclado = new BufferedReader(stream);
        
        try
        {
            System.out.println("\n\tIntroduzca la marca del coche");
            this.marca = teclado.readLine();
        }
        catch (IOException e)
        {
            System.out.println("\nHa ocurrido un error. Se cerrará el programa.");
            System.exit(0);
        }
    }
    
    private void setModelo()
    {
        InputStreamReader stream = new InputStreamReader(System.in);
        BufferedReader teclado = new BufferedReader(stream);
        
        try
        {
            System.out.println("\n\tIntroduzca el modelo del coche");
            this.modelo = teclado.readLine();
        }
        catch (IOException e)
        {
            System.out.println("\nHa ocurrido un error. Se cerrará el programa.");
            System.exit(0);
        }
    }
    
    public void setColor()
    {
        InputStreamReader stream = new InputStreamReader(System.in);
        BufferedReader teclado = new BufferedReader(stream);
        
        try
        {
            System.out.println("\n\tIntroduzca el color del coche");
            this.color = teclado.readLine();
        }
        catch (IOException e)
        {
            System.out.println("\nHa ocurrido un error. Se cerrará el programa.");
            System.exit(0);
        }
    }
    
    /*------------------------------------------------------*/
    /*Getters*/
    public String getMarca()
    {
        return this.marca;
    }
    
    public String getModelo()
    {
        return this.modelo;
    }
    
    public String getColor()
    {
        return this.color;
    }
}
