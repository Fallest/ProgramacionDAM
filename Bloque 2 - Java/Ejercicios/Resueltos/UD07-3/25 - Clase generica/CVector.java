import java.util.*;

public class CVector<T>
{
  private ArrayList<T> vector;
  
  // Crea un CVector con un espacio para n elementos
  public CVector(int... ne) // ne elementos
  {
    int nElementos;
	if (ne.length < 1)
	  nElementos = 10; // elementos por omision
	else
	  nElementos = ne[0];
	vector = new ArrayList<T>(nElementos);
  }
  
  // Crea un CVector desde una matriz
  public CVector(T[] m)
  {
    int nElementos = m.length;
	vector = new ArrayList<T>(nElementos);
	for (int i = 0; i < nElementos; i++)
	  vector.add(m[i]);
  }
  
  // Constructor copia
  public CVector(final CVector v)
  {
    copiar(v);
  }
  
  // Copia un vector en otro
  public CVector copiar(final CVector v)
  {
    int nElementos = v.longitud();
	vector = new ArrayList<T>(nElementos);
	for (int i = 0; i < nElementos; i++)
	  vector.add((T)v.vector.get(i));
	return this;
  }
  
  public void ponerValorEn (int i, T valor)
  {
    int nElementos = this.longitud();
	if (i >= 0 && i < nElementos)
	  vector.set(i, valor);
	else
	  System.out.println("Indice fuera de limites");
  }
  
  public T valorEn (int i)
  {
    if (i >= 0 && i < this.longitud())
	  return vector.get(i);
	else
	{
	  System.out.println("Indice fuera de limites");
	  return null;
	}
  }
  
  public int longitud()
  {
    return vector.size();
  }
}