package Data_12;

import java.io.*;

public class test
{
  public static void main (String[] args) throws IOException
  {
    int numInt;
	String cadena;
	float numFloat;
	FileOutputStream fichEscrit = new FileOutputStream("prueba.txt");
	DataOutputStream escritTipos = new DataOutputStream(fichEscrit);
	
	System.out.println("\nInserte un numero entero: ");
	numInt = Leer.datoInt();
	escritTipos.writeInt(numInt);
	
	System.out.println("\nInserte un numero con decimales: ");
	numFloat = Leer.datoFloat();
	escritTipos.writeFloat(numFloat);
	
	System.out.println("\nInserte una cadena: ");
	cadena = Leer.dato();
	escritTipos.writeChars(cadena);
	
	escritTipos.close();
	
	FileInputStream fichLect = new FileInputStream("prueba.txt");
	DataInputStream lectTipos = new DataInputStream(fichLect);
	
	numInt = lectTipos.readInt();
	numFloat = lectTipos.readFloat();
	cadena = lectTipos.readLine();
	
	System.out.println("\nLos datos leidos del fichero son: ");
	System.out.println("\t" + numInt + "\t" + cadena + "\t" + numFloat);
	
	fichLect.close();
  }
}