<?php include 'Static/connect/db.php';?>
<?php include 'includes/header.php';?>
<?php
        if(isset($_GET['id'])){
         $ID = $_GET['id'];
         $delete = "DELETE FROM servicios where id = $ID;";
         $exec = mysqli_query($conexion,$delete);
         sleep(2);
         header("Location: consultadeu.php");
        }
?>  


























