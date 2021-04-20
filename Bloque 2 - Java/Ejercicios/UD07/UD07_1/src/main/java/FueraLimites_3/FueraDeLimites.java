package FueraLimites_3;

public class FueraDeLimites {

    public static void main(String[] args)
    {
        int posic;
        String cadena = "Buenos dias";
        boolean entrada;
        char caracter;
        
        do
        {
            System.out.println("\n\n\tIndica una posicion que este entre 0 y " + (cadena.length()-1) + ": ");
            posic = Leer.datoInt();
            try
            {
                caracter = cadena.charAt(posic);
                entrada = true;
                System.out.println("\n\n\tEn la cadena \"" + cadena + "\" el caracter situado en la posicion " + posic + " es " + caracter + ". ");
            }
            catch(StringIndexOutOfBoundsException e)
            {
                entrada = false;
                System.out.println("\n\n\tLa posicion que ha indicado no esta entre 0 y " + (cadena.length()-1));
                System.out.println("n\n\t Salida del programa.");
            }
        }while(entrada==true);
    }
}
