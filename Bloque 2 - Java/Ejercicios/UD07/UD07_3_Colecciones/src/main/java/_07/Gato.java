package _07;

public class Gato{

    private String nombre;
    private String color;
    private String raza;

    public Gato(String nombre, String color, String raza) {
      this.nombre = nombre;
      this.color = color;
      this.raza = raza;
    }

    public String getNombre() {
      return nombre;
    }

    public String getRaza() {
      return raza;
    }

    public String toString() {
      return "Nombre: " + this.nombre + "\nColor: " + this.color + "\nRaza: " + this.raza;
    }

}
