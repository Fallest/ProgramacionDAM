public class Principal{

    public static void main(String[] args) {

      Empleado empresa[];
      int numEmp, pos;

      System.out.println("\n\tIndique cuantos empleados tiene la empresa: ");
      numEmp = Leer.pedirEnteroValidar();
      empresa = new Empleado[numEmp];

      for (pos = 0; pos < numEmp; pos++)
      {
        System.out.println("\nVamos a reservar y pedir los datos del empleado " + (pos+1) + ": ");
        empresa[pos] = new Empleado();  // La clase Empleado tiene constructor.
      }

      for (pos = 0; pos < numEmp; pos++)
      {
        System.out.println("\nVamos a visualizar los datos del empleado " + (pos+1) + ": ");
        empresa[pos].visualTodo();
      }
        
    }
}
