public class Jefe extends Empleado
{
  String deparJefe;
  String titulUniver;
    
  void instituniv()
  {
    System.out.println("\nTITULO UNIVERSITARIO: ");
    titulUniver = Leer.dato();
  }
  
  void insdepjef()
  {
    System.out.println("\nDEPARTAMENTO DONDE ES JEFE:");
    deparJefe = Leer.dato();
  }
  
  void insdatjef()
  {
    insdatemp();
    instituniv();
    insdepjef();
  }
  
  void vistituniv()
  {
    System.out.println("\nTITULO UNIVERSITARIO: " + titulUniver);
  }
  
  void visdepjef()
  {
    System.out.println("\nDEPARTAMENTO: " + deparJefe);
  }
  
  void visdatjef()
  {
    visdatemp();
    vistituniv();
    visdepjef();
  }
}