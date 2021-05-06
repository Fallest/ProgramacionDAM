package EjCadenasDiccionario;

public class PPareja {
    // Atributos
    private String pareja[] = new String[2];
    
    PPareja () {
        setCad1();
        setCad2();
    }
    
    PPareja(String cad1, String cad2) {
        this.pareja[0] = cad1;
        this.pareja[1] = cad2;
    }
    
    
    // Getters
    public String getCad1() {
        return this.pareja[0];
    }
    
    public String getCad2() {
        return this.pareja[1];
    }
    
    // Setters
    public void setCad1() {
        System.out.println("\tIntroduzca la palabra en inglés: ");
        this.pareja[0] = Leer.dato();
    }
    
    public void setCad1(String cad) {
        this.pareja[0] = cad;
    }
    
    public void setCad2() {
        System.out.println("\tIntroduzca la traducción al español: ");
        this.pareja[1] = Leer.dato();
    }
    
    public void setCad2(String cad) {
        this.pareja[1] = cad;
    }
}
