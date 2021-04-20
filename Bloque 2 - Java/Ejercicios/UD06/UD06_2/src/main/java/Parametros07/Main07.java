package Parametros07;

public class Main07 {
    
    public static void main(String args[]) {
        
        int edad1, edad2, edad3;
        String nombre1, nombre2, nombre3;
        
        Alumno alum1 = new Alumno();
        Alumno alum2 = new Alumno();
        Alumno alum3 = new Alumno();

        System.out.println("\n\n\tIntroduzca la edad del primer alumno: ");
        edad1 = Leer.datoInt();
        System.out.println("\n\n\tIntroduzca el nombre del primer alumno: ");
        nombre1 = Leer.dato();
        
        System.out.println("\n\n\tIntroduzca la edad del segundo alumno: ");
        edad2 = Leer.datoInt();
        System.out.println("\n\n\tIntroduzca el nombre del segundo alumno: ");
        nombre2 = Leer.dato();
        
        System.out.println("\n\n\tIntroduzca la edad del tercer alumno: ");
        edad3 = Leer.datoInt();
        System.out.println("\n\n\tIntroduzca el nombre del tercer alumno: ");
        nombre3 = Leer.dato();
        
        
        
        
        alum1.setEdad(edad1);
        alum2.setEdad(edad2);
        alum3.setEdad(edad3);
        alum1.setNombre(nombre1);
        alum2.setNombre(nombre2);
        alum3.setNombre(nombre3);
        
        System.out.println("Alumno 1:");
        alum1.mostrarDatos();
        System.out.println("Alumno 2:");
        alum2.mostrarDatos();
        System.out.println("Alumno 3:");
        alum3.mostrarDatos();
         
        int media = (alum1.getEdad() + alum2.getEdad() + alum2.getEdad()) / 3;
        System.out.println("\n\n\tMedia de edades: Aproximadamente " + media);
    }
}
