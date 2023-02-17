<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
<table>
      <tr>
        <th>ID</th>
        <th>Nombre</th>
        <th>Apellido</th>
        <th>Edad</th>
      </tr>
      <?php
        $servername = "localhost";
        $username = "root";
        $password = "root";
        $dbname = "EC1_WEB";

        $conn = mysqli_connect($servername, $username, $password, $dbname);
        if (!$conn) {
            die("Conexión fallida: " . mysqli_connect_error());
        }

        $sql = "SELECT id, nombre, apellido, edad FROM USER";
        $result = mysqli_query($conn, $sql);

        if (mysqli_num_rows($result) > 0) {
            // Imprimir filas
            while($row = mysqli_fetch_assoc($result)) {
                echo "<tr>
                        <td>" . $row["id"]. "</td>
                        <td>" . $row["nombre"]. "</td>
                        <td>" . $row["apellido"]. "</td>
                        <td>" . $row["edad"]. "</td>
                      </tr>";
            }
        } else {
            echo "No hay resultados";
        }

        mysqli_close($conn);
      ?>
    </table>
</body>
</html>