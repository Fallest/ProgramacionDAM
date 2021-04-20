package Conversion_4;

public class Conversion {

    public static void main(String[] args)
    {
        String cadena;
        int num1, num2, suma;
        
        System.out.println("\nInserta un numero: ");
        num1 = Leer.datoInt();
        System.out.println("\nInserta otro numero: ");
        num2 = Leer.datoInt();
        
        suma = num1 + num2;
        
        cadena = String.valueOf(suma);
        
        System.out.println("\n\t" + num1 + " + " + num2 + " = " + suma);
        System.out.println("\n\tDicho resultado esta formado por " + cadena.length() + " digitos.");
    }
}

