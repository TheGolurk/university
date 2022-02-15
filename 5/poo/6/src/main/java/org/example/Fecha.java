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

    public int Diferencia( Fecha fecha1, Fecha fecha2){

        return 5;

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
