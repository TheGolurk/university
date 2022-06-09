/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package login;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

public class Login {

    public static void main(String[] args) {

        String cadena = "jdbc:mysql://localhost:3306/ep4poo?useUnicode=true&characterEncoding=UTF-8&user=root&password=root";

            try{
                Class.forName("com.mysql.jdbc.Driver");
                Connection c = DriverManager.getConnection(cadena);
                System.out.println(c);

            }catch(Exception e){

                System.err.println(e);

            }


        }
        

}
