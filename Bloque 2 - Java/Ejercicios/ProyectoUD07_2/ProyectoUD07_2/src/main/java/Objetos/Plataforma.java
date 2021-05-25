package Objetos;

import Errores.Errores;

public enum Plataforma {
    Windows, Linux, Mac, PlayStation, XBox;
    
    public String toString() {
        String res = null;
        
        switch (this.name()) {
            case "Windows" -> {res = "Windows";}
            case "Linux" -> {res = "Linux";}
            case "Mac" -> {res = "Mac";}
            case "PlayStation" -> {res = "PlayStation";}
            case "XBox" -> {res = "XBox";}
        }
        
        return res;        
    }
    
    public static Plataforma convPlat(String plat) throws Errores {
        Plataforma res = null;
        
        switch (plat.toLowerCase()) {
            case "windows" -> {res = Plataforma.Windows;}
            case "linux" -> {res = Plataforma.Linux;}
            case "mac" -> {res = Plataforma.Mac;}
            case "playstation" -> {res = Plataforma.PlayStation;}
            case "xbox" -> {res = Plataforma.XBox;}
        }
        
        // Lanzar un error si la cadena de entrada no concuerda con ningún valor
        if (res == null)
            throw new Errores();
        
        return res;
    }
}
