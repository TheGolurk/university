package org.example;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

public class Main {
    public static void main(String[] args) {
        try (Connection conn = DriverManager.getConnection(getConnString())){

            System.out.println("on");

        }catch (SQLException e) {
            System.err.println(e);
        }
    }

    public static String getConnString() {
        return  "jdbc:mysql://localhost:3306/ep4poo?useUnicode=true&characterEncoding=UTF-8&user=root&password=root";
    }
}