import java.io.Serializable;
import java.util.ArrayList;
import java.util.Scanner;

public class clientes implements Serializable {
    private String nombreCliente;
    private int edad;

    private ArrayList<casa> comprascasa;
    private ArrayList<casa> rentascasa;
    private ArrayList<departamento> comprasdepartamentos;
    private ArrayList<departamento> rentasdeptos;

    public clientes(ArrayList<casa> comprascasa, ArrayList<casa> rentascasa, ArrayList<departamento> comprasdepartamentos, ArrayList<departamento> rentasdeptos, String nombre, int edad) {
        this.comprascasa = comprascasa;
        this.rentascasa = rentascasa;
        this.comprasdepartamentos = comprasdepartamentos;
        this.rentasdeptos = rentasdeptos;
        this.nombreCliente = nombre;
        this.edad = edad;
    }

    public void agregarCompracasa() {
        Scanner leer = new Scanner(System.in);
        System.out.println("ingrese una casa presione enter");
        leer.nextLine();
        System.out.println("ingrese estado");
        String estado = leer.nextLine();
        System.out.println("ingrese municipio");
        String municipio = leer.nextLine();
        System.out.println("ingrese direccion");
        String direccion = leer.nextLine();
        System.out.println("ingrese numero de habitaciones");
        int  numA = leer.nextInt();
        System.out.println("ingrese metros cuadrados");
        double  metros2 = leer.nextDouble();
        System.out.println("ingrese la edad del inmueble");
        int edad = leer.nextInt();
        System.out.println("ingrese el numero de baños");
        int numb = leer.nextInt();
        System.out.println("ingrese numero de pisos");
        int nump = leer.nextInt();
        System.out.println("ingrese si tiene jardin");
        boolean tienjardin = leer.nextBoolean();
        casa casa = new casa(estado,municipio, direccion, numA,metros2, edad,numb,nump,tienjardin);
        comprascasa.add(casa);
    }

    public void agregarrentaCasa() {
        Scanner leer = new Scanner(System.in);
        System.out.println("ingrese una casa presione enter");
        leer.nextLine();
        System.out.println("ingrese estado");
        String estado = leer.nextLine();
        System.out.println("ingrese municipio");
        String municipio = leer.nextLine();
        System.out.println("ingrese direccion");
        String direccion = leer.nextLine();
        System.out.println("ingrese numero de habitaciones");
        int  numA = leer.nextInt();
        System.out.println("ingrese metros cuadrados");
        double  metros2 = leer.nextDouble();
        System.out.println("ingrese la edad del inmueble");
        int edad = leer.nextInt();
        System.out.println("ingrese el numero de baños");
        int numb = leer.nextInt();
        System.out.println("ingrese numero de pisos");
        int nump = leer.nextInt();
        System.out.println("ingrese si tiene jardin");
        boolean tienjardin = leer.nextBoolean();
        casa casa = new casa(estado,municipio, direccion, numA,metros2, edad,numb,nump,tienjardin);
        rentascasa.add(casa);
    }

    public void agregarCompraDepto() {
        Scanner leer = new Scanner(System.in);
        System.out.println("ingrese un depto presione enter");
        leer.nextLine();
        System.out.println("ingrese estado");
        String estado = leer.nextLine();
        System.out.println("ingrese municipio");
        String municipio = leer.nextLine();
        System.out.println("ingrese direccion");
        String direccion = leer.nextLine();
        System.out.println("ingrese numero de habitaciones");
       int  numA = leer.nextInt();
        System.out.println("ingrese metros cuadrados");
        double  metros2 = leer.nextDouble();
        System.out.println("ingrese la edad del inmueble");
        int edad = leer.nextInt();
        System.out.println("ingrese el numero de baños");
        int numb = leer.nextInt();
        System.out.println("ingrese el piso del departamento");
        int piso = leer.nextInt();
        System.out.println("ingrese si tiene elevador");
        boolean elevador = leer.nextBoolean();
        System.out.println("ingrese si tiene lavado");
        boolean lavado = leer.nextBoolean();
        departamento dpto = new departamento(estado,municipio, direccion, numA,metros2, edad,numb, piso, elevador, lavado);
        comprasdepartamentos.add(dpto);
    }

    public void agregarrentadpto() {
        Scanner leer = new Scanner(System.in);
        System.out.println("ingrese un depto presione enter");
        leer.nextLine();
        System.out.println("ingrese estado");
        String estado = leer.nextLine();
        System.out.println("ingrese municipio");
        String municipio = leer.nextLine();
        System.out.println("ingrese direccion");
        String direccion = leer.nextLine();
        System.out.println("ingrese numero de habitaciones");
        int  numA = leer.nextInt();
        System.out.println("ingrese metros cuadrados");
        double  metros2 = leer.nextDouble();
        System.out.println("ingrese la edad del inmueble");
        int edad = leer.nextInt();
        System.out.println("ingrese el numero de baños");
        int numb = leer.nextInt();
        System.out.println("ingrese el piso del departamento");
        int piso = leer.nextInt();
        System.out.println("ingrese si tiene elevador");
        boolean elevador = leer.nextBoolean();
        System.out.println("ingrese si tiene lavado");
        boolean lavado = leer.nextBoolean();
        departamento dpto = new departamento(estado,municipio, direccion, numA,metros2, edad,numb, piso, elevador, lavado);
        rentasdeptos.add(dpto);
    }

    public String getNombreCliente() {
        return nombreCliente;
    }

    public int getEdad() {
        return edad;
    }

    public ArrayList<casa> getComprascasa() {
        return comprascasa;
    }

    public ArrayList<casa> getRentascasa() {
        return rentascasa;
    }

    public ArrayList<departamento> getComprasdepartamentos() {
        return comprasdepartamentos;
    }

    public ArrayList<departamento> getRentasdeptos() {
        return rentasdeptos;
    }
}
