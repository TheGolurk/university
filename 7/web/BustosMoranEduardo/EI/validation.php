<?php include 'Static/connect/db.php'?>
<?php include 'includes/header.php';?>
<?php
session_start();
$user= $_POST['usuario'];
$password= $_POST['contrasena'];
$sql = "SELECT *FROM usuarios WHERE usuario = '$user' and contrasena='$password';";

$exec=mysqli_query($conn,$sql);
$row = mysqli_fetch_assoc($exec);
$filas=mysqli_fetch_array($exec);

if(($row['usuario']==$user)&&($row['contrasena']==$password)&&($row['rol']==1)){
    $_SESSION['usuario']=$user;
    header("Location: Servicios.php");
}else if(($row['usuario']==$user)&&($row['contrasena']==$password)&&($row['rol']==2)){
    $_SESSION['usuario']=$user;
    header("Location: ServiciosUsuario.php");
}
 else{
    header("Location: login.php");
 }
?>

