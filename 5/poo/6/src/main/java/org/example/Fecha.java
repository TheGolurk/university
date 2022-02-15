package org.example;

public class Fecha {
    private int Dia;
    private int Mes;
    private int Año;

    public Fecha(int dia, int mes, int año) {
        Dia = dia;
        Mes = mes;
        Año = año;
    }

    public Fecha(int dia, String mes, int año) {
        Dia = dia;
        Año = año;
        Año = obtenerMes(mes);
    }

    private int obtenerMes(String mes) {
        switch (mes) {
            case "Enero" -> {
                return 1;
            }
            case "Febrero" -> {
                return 2;
            }
            case "Marzo" -> {
                return 3;
            }
            case "Abril" -> {
                return 4;
            }
            case "Mayo" -> {
                return 5;
            }
            case "Junio" -> {
                return 6;
            }
            case "Julio" -> {
                return 7;
            }
            case "Agosto" -> {
                return 8;
            }
            case "Septiembre" -> {
                return 9;
            }
            case "Octubre" -> {
                return 10;
            }
            case "Noviembre" -> {
                return 11;
            }
            case "Diciembre" -> {
                return 12;
            }
            default -> {
                return 0;
            }
        }
    }

    public int getDia() {
        return Dia;
    }

    public void setDia(int dia) {
        Dia = dia;
    }

    public int getMes() {
        return Mes;
    }

    public void setMes(int mes) {
        Mes = mes;
    }

    public int getAño() {
        return Año;
    }

    public void setAño(int año) {
        Año = año;
    }

    public boolean FechaValida() {
        int dia = getDia();
        int mes = getMes();
        int año = getAño();

        if(dia > 31 || dia <0){
            return false;
        }
        if(mes >12 || mes <0){
            return false;
        }
        if(año <0 ){
            return false;
        }

        return true;
    }

    public Fecha FechaSiguiente(Fecha fechaActual, int dias) {
        int mes = fechaActual.getMes();
        int diasDelMes = diasMes(mes);

        int diasFaltantes = diasDelMes - fechaActual.getDia();
        int diferencia = dias - diasFaltantes;

        while (diferencia > diasDelMes) {
            mes++;
            diasDelMes = diasMes(mes);
            diferencia -= diasDelMes;

            if (mes == 12) {
                mes = 1;
                fechaActual.setAño( fechaActual.getAño() + 1 );
            }
        }
        fechaActual.setDia(diferencia);
        fechaActual.setMes(mes);

        return fechaActual;
    }

    public Fecha FechaAnterior( Fecha fechaActual, int dias ){
        int mes = fechaActual.getMes();
        int diasDelMes = diasMes(mes);

        diasDelMes = diasDelMes - (diasDelMes - fechaActual.getDia());

        int diasFaltantes = dias;

        while (diasFaltantes > diasDelMes) {
            diasFaltantes -= diasDelMes;

            mes--;
            if (mes == 0) {
                mes = 12;
                fechaActual.setAño( fechaActual.getAño() - 1 );
            }

            diasDelMes = diasMes(mes);
        }
        fechaActual.setDia( diasDelMes - diasFaltantes);
        fechaActual.setMes(mes);

        return fechaActual;
    }

    public int Diferencia(Fecha fecha1, Fecha fecha2){
        int f1 = diasMeses(fecha1.getMes()) + fecha1.getDia() + (365 * fecha1.getAño());
        int f2 = diasMeses(fecha2.getMes()) + fecha2.getDia() + (365 * fecha2.getAño());

        return f2 - f1;
    }

    private int diasMeses(int mes) {
        int meses = 0;
        if (mes > 1) {
            for (int i = 1; i < mes; i++) {
                meses += diasMes(i);
            }
        }

        return meses;
    }

    private int diasMes(int mes) {
        switch (mes) {
            case 1, 10, 12, 8, 7, 5, 3 -> {
                return 31;
            }
            case 2 -> {
                return 28;
            }
            case 4, 9, 11, 6 -> {
                return 30;
            }
            default -> {
                return 0;
            }
        }
    }

}
