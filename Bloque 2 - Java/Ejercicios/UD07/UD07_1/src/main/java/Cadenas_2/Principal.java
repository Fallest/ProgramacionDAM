package Cadenas_2;

public class Principal {

    public static void main(String[] args)
    {
        String cad = "Primer valor asignado";
        System.out.println("\n\nEl valor que tiene la cadena, antes de llamar al metodo, es \"" + cad + "\"");
        cambiarCad(cad);
        System.out.println("\n\nEl valor que tiene la cadena, despues de llamar al metodo, es \"" + cad + "\"");
    }
    
    static void cambiarCad(String cade)
    {
        System.out.println("\n\nEl valor que tiene la cadena, al principio del metodo, es \"" + cade + "\"");
        cade = "Valor asignado dentro del metodo";
        System.out.println("\n\nEl valor que tiene la cadena, dentro del metodo, es \"" + cade + "\"");
        
    }
}
