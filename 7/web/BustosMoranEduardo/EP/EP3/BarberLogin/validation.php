<?php include 'Static/connect/dblogin.php';?>
<?php include 'includes/header.php';?>
<?php
session_start();
$user= $_POST['usuario'];
$password= $_POST['contrasena'];
$sql = "SELECT *FROM USUARIOS WHERE usuario = '$user' and contrasena='$password';";

$exec=mysqli_query($conn,$sql);
$row = mysqli_fetch_assoc($exec);

if(($row['usuario']==$user)&&($row['contrasena']==$password)){
    $_SESSION['usuario']=$user;
    header("Location: Servicios.php");
}else{
    header("Location: index.php");
    }
?>