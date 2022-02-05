package com.upemor;

public class Alumno {
    private String Nombre;
    private int Edad;
    private String Matricula;
    private Materia[] Materias;

    public Alumno(String nombre, int edad, String matricula, Materia[] materias) {
        Nombre = nombre;
        Edad = edad;
        Matricula = matricula;
        Materias = materias;
    }

    public String getNombre() {
        return Nombre;
    }

    public void setNombre(String nombre) {
        Nombre = nombre;
    }

    public int getEdad() {
        return Edad;
    }

    public void setEdad(int edad) {
        Edad = edad;
    }

    public String getMatricula() {
        return Matricula;
    }

    public void setMatricula(String matricula) {
        Matricula = matricula;
    }

    public Materia[] getMaterias() {
        return Materias;
    }

    public void setMaterias(Materia[] materias) {
        Materias = materias;
    }

    public void RegistrarAlumno() {

    }

    public void ConsultarCalificaciones() {
        for (Materia m: this.getMaterias()) {
            System.out.println("Materia: " + m.getNombre() + " Calificaion: " + m.getCalificacion());
        }
    }

    public double CalcularPromedio(){
        double a = 0;

        for (Materia m: this.getMaterias()) {
            a += m.getCalificacion();
        }

        return a/this.Materias.length;
    }
}
