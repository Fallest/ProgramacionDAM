public class Recorrido {

    public static void main(String[] args) {
        
        float [][]notas = new float[6][3];
        
        for (int posf=0;posf<notas.length;posf++)
        {
            System.out.println("\nLos valores que hay en la fila " + (posf+1) + " son: ");
            for (int posc=0; posc<notas[posf].length;posc++)
                System.out.println("\n\tEl valor que hay en la columna " + (posc+1) + " es " + notas[posf][posc]);
        }
        
        
        int [][] tabla = {{23, 45, 11, 2}, {67, 2}, {1, 2, 3, 4, 5, 6}};
    
        for (int posf=0;posf<tabla.length;posf++)
        {
            System.out.println("\nLos valores que hay en la fila " + (posf+1) + " son: ");
            for (int posc=0; posc<tabla[posf].length;posc++)
                System.out.println("\n\tEl valor que hay en la columna " + (posc+1) + " es " + tabla[posf][posc]);
        }
        
      
    }
}
