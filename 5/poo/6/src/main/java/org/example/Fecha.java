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
        // OBTIENE LOS DIAS DEL MES
        int mes = fechaActual.getMes();
        int diasDelMes = diasMes(mes);

        int sumaDias = fechaActual.getDia() + dias;

        if (sumaDias <= diasDelMes) {
            fechaActual.setDia(sumaDias);
        } else {
            int diasFaltantes = diasDelMes - fechaActual.getDia();
            int diferencia = sumaDias - diasFaltantes;

            mes++;
            diasDelMes = diasMes(mes);
            while (diferencia > diasDelMes) {
                diferencia = diferencia - diasDelMes;

                mes++;
                // actualizar variable diasDelMes con el mes correcto
                // comprobar si el mes es 12 para pasar al siguiente año
                // mes > 12
                // fechaActual.setAño(); sumarle un año
            }

            // asignar valores
        }
        return new Fecha(1,1,1);
    }

    public Fecha FechaAnterior( Fecha fechaActual, int dias ){
        int mes = fechaActual.getMes();
        int diasDelMes = diasMes(mes);

        int restaDias = fechaActual.getDia() - dias;

        if (restaDias > 0) {
            fechaActual.setDia( restaDias );
            return fechaActual;
        } else {
            int diasFaltantes = dias - fechaActual.getDia();
            while (diasFaltantes > diasDelMes){
                diasFaltantes -= diasDelMes;
                if (mes == 1) {
                    mes = 12;
                } else {
                    mes--;
                }
            }


            fechaActual.setDia( diasDelMes - diasFaltantes);
            fechaActual.setMes(mes);
            fechaActual.setAño(getAño());

            return fechaActual;
        }

        // return fechaActual;
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
