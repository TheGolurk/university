<?php include 'Static/connect/db.php';?>
<?php include 'includes/header.php';?>
<?php 
$servicio=$_POST['nombre'];
$precio=$_POST['precio'];
$sql ="INSERT INTO servicios(nombre, precio)values('$servicio',$precio);";
    $query = mysqli_query($conexion,$sql);
    sleep(3);
    header("Location: Servicios.php");
?>