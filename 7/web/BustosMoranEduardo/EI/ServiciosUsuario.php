<?php include 'includes/header.php';?>
<?php

session_start();
error_reporting(0);

$validar = $_SESSION['usuario'];

if( $validar == null || $validar = ''){

  header("Location: login.php");
  die();
  
}


?>
<h1>Bienvenido Usuario <?php echo $_SESSION['usuario']; ?></h1>
		<div>
      <a class="btn btn-warning" href="logout.php">Log Out
      <i class="fa fa-power-off" aria-hidden="true"></i>
       </a>
<hr>  
<center>
<a href="consultageneral.php">
            <img src="./Static/img/query.png">          
           </a>        
<a href="Static/convertirpdf/excel.php">
         <img src="./Static/img/excelicon.png">          
</a> 
<a href="Static/convertirpdf/reporte.php">
         <img src="./Static/img/pdficon.png">          
</a>
</center>
<?php include 'includes/footer.php';?>