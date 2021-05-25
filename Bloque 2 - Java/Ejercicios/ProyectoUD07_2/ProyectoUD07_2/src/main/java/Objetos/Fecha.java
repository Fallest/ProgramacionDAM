package Objetos;

import Errores.Errores;

public class Fecha {
    // Atributos
    private int dia;
    private int mes;
    private int año;
    
    /*------------------------------------------------------------------------*/
    // Constructor:
    public Fecha (int dia, int mes, int año) throws Errores {
        Errores error = new Errores();
        
        if (!checkFecha(dia, mes, año))
            throw error; // No hace falta hacer try catch aquí, puesto que se
                         // propaga a la función que llama a este constructor.
        else {
            this.dia = dia;
            this.mes = mes;
            this.año = año;
        }
    }
    
    /*------------------------------------------------------------------------*/
    // Setters:
    public void setDia(int dia) throws Errores {
        Errores error = new Errores();
        
        if (!checkFecha(dia, this.mes, this.año))
            throw error;
        else
            this.dia = dia;
    }
    
    public void setMes(int mes) throws Errores {
        Errores error = new Errores();
        
        if (!checkFecha(this.dia, mes, this.año))
            throw error;
        else
            this.mes = mes;
    }

    public void setAño(int año) throws Errores {
        Errores error = new Errores();
        
        if (!checkFecha(dia, this.mes, año))
            throw error;
        else
            this.año = año;
    }
    
    /*------------------------------------------------------------------------*/
    // Getters:
    public int getDia() {
        return this.dia;
    }
    
    public int getMes() {
        return this.mes;
    }

    public int getAño() {
        return this.año;
    }

    /*------------------------------------------------------------------------*/
    // Checkers:
    //      (sé que no los hemos dado, pero uso el concepto porque es para el control 
    //      de errores de fechas).
    private boolean checkFecha(int dia, int mes, int año) {
        // Va a devolver false si la fecha no es válida.
        boolean esValido = true;
        
        // Comprobación básica de los días, meses y años.
        if ((dia < 1 || dia > 31) || (mes < 1 || mes > 12) || (año < 1 || año > 2030))
            esValido = false;
        
        // Tratamiento de años bisiestos (solo febrero).
        switch (año % 4) {
            case 0: {
                if (mes == 2 && dia > 29)
                    esValido = false;
                break;
            }
            default: {
                if (mes == 2 && dia > 28)
                    esValido = false;
                break;
            }
        }
        
        // Tratamiento del resto de meses.
        if ((mes == 4 || mes == 6 || mes == 9 || mes == 11) && dia > 30)
            esValido = false;
        
        return esValido;
    }
    
    /*------------------------------------------------------------------------*/
    // Funciones de utilidades:
    public static int toInt(Fecha fecha) {
        int diasTotales, i;
        
        /*
        Para calcular los días correspondientes a los años, multiplicamos el año
        por 365, y para sumar los años bisiestos, solo calculamos la cantidad de
        años bisiestos que hay, y sumamos +1 por cada año bisiesto, porque tienen
        un día más.
        Al hacer esto nos ahorramos tener que tratar el febrero de los años bisiestos
        al sumar los días correspondientes a los meses.
        */
        diasTotales = (fecha.getAño()*365 + fecha.getAño() / 4);
        
        /*
        Para calcular los días correspondientes a los meses, vamos a usar un bucle
        for, en el que vamos a ir sumando la cantidad de días del mes correspondiente
        empezando desde un mes anterior al de la fecha. La razón para empezar por el
        mes anterior, es que si por ejemplo tenemos 20/3, comenzará por el 3, y sumará
        31, en vez de 20. La suma de los días de el mes de la fecha se hace después.
        */
        for (i = fecha.getMes() - 1; i > 0; i--) {
            // Meses de 31 días.
            if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12)
                diasTotales += 31;
            // Febrero.
            else if (i == 2) 
                diasTotales += 28; // Siempre 28, porque el día extra del año bisiesto
                                   // ya se añade con los años.
            // Meses de 30 días.
            else
                diasTotales += 30;
        }
                
        // Suma de los días de la fecha
        diasTotales += fecha.getDia();
        
        return diasTotales;
    }
    
    public String toStr(Fecha fecha) {
        String fechaCad;
        
        fechaCad = String.valueOf(fecha.dia) + "/" + String.valueOf(fecha.mes) + "/"
                + String.valueOf(fecha.año);

        return fechaCad;
    }
}