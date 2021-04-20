enum meses
{
  // Conjunto de valores
  enero(31), febrero(28), marzo(31), abril(30), mayo(31), junio(30), julio(31), agosto(31), septiembre(30), octubre(31), noviembre(30), diciembre(31);
  
  // Atributos
  private final int diasMes;
  
  //Metodos
  meses(int dias)  // Constructor
  {
    diasMes = dias;
  }
  
  public int DiasMes()
  {
    return diasMes;
  }
}