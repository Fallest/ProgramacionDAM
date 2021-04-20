import java.io.*;
import java.util.*;

public class DemasiadosObjetos extends Exception
{
  void informError(String tipo_clase)
  {
    System.out.println("\n\nSe ha creado el maximo numero permitido de objetos de tipo " + tipo_clase + " en la memoria.");
  }
}