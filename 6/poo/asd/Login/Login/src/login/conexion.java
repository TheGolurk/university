/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package login;

import java.sql.Connection;
import java.sql.DriverManager;

public class conexion {
    
        public Connection conectar(){

            String cadena = "jdbc:mysql://localhost:3306/ep4poo?useUnicode=true&characterEncoding=UTF-8&user=root&password=root";

            try{
                Class.forName("com.mysql.jdbc.Driver");
                return DriverManager.getConnection(cadena);


            }catch(Exception e){

                System.err.println(e);

            }
        
        
            return null;
        
        }
    
}
