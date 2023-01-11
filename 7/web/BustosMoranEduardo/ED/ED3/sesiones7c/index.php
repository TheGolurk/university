<?php include 'includes/header.php';?>
<?php
session_start();

$user = $_SESSION['usuario'];

if(isset($_SESSION['usuario'])){
    echo"Haz Iniciado Sesión como: $user";
?>    
    <p>Bienvenido a tu sesión, en ella podras encontrar......</p>
    <a href="logout.php">CERRAR</a>
<?php
    }else{
        header("Location: login.php");        
    }        
?>