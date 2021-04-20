public class Coche implements Vehiculo {

    int velocidad=0;

    // @Override
    public String frenar(int cuanto) {
        velocidad-=cuanto;
        return "El coche ha frenado ya y va a "+velocidad+"km/hora";
    }

    // @Override
    public String acelerar(int cuanto) {
        String cadena="";
        velocidad+=cuanto;
        if (velocidad>velocidadMaxima)
            cadena="Exceso de velocidad";
        cadena+="El coche ha acelerado y va a "+velocidad+"km/hora";
        return cadena;
    }

    public int plazas(){
        return 4;
    }

}