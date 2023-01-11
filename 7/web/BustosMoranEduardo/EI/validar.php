<?php include 'Static/connect/db.php';?>
<?php

if(isset($_POST['registrar'])){

    if(strlen($_POST['usuario']) >=1  && strlen($_POST['contrasena'])  >=1 && strlen($_POST['rol']) >= 1 ){

    $nombre = trim($_POST['usuario']);
    $password = trim($_POST['contrasena']);
    $rol = trim($_POST['rol']);

    $consulta= "INSERT INTO usuarios (usuario, contrasena, rol)
    VALUES ('$nombre', '$password', '$rol' )";

    mysqli_query($conn, $consulta);
    mysqli_close($conn);

    header('Location: Servicios.php');
  }
}
?>