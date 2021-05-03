package Polimorfismo_17;

public class Principal
{
  public static void main(String[] args)
  {
    Empleado[] empresa = { new Empleado(), new Jefe(), new Becario() };
	for (int i = 0; i < 3; i++)
	  empresa[i].visualTodosDatos();
  }
}