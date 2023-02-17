<?php
$servername = "localhost";
$username = "root";
$password = "root";
$dbname = "EC1_WEB";

$conn = mysqli_connect($servername, $username, $password, $dbname);
if (!$conn) {
    die("Conexión fallida: " . mysqli_connect_error());
}

$nombre = $_POST["nombre"];
$apellido = $_POST["apellido"];
$edad = $_POST["edad"];
$contraseña = $_POST["contraseña"];

$sql = "INSERT INTO USER (nombre, apellido, edad, contraseña)
VALUES ('$nombre', '$apellido', '$edad', '$contraseña')";

if (mysqli_query($conn, $sql)) {
    echo "Nuevo registro creado exitosamente";
} else {
    echo "Error: " . $sql . "<br>" . mysqli_error($conn);
}

mysqli_close($conn);
?>
