<?php 
include 'Static/connect/db.php';
include 'includes/header.php';
session_start();

$user = $_SESSION['usuario'];
if (isset($_SESSION['usuario'])) {
    echo "<h1>Bienvenida: $user</h1>";
} 
?>

<table class="table table-dark">
<thead>
        <tr>
            <td>No.</td>  <td>Servicio</td>  <td>Inversión</td>
       </tr>
</thead>
<?php 
         $consulta="SELECT *FROM servicios;";
         $result=mysqli_query($conn,$consulta);
        while($row = mysqli_fetch_array($result)){ ?>
          <tr>
            <td> <?php echo $row['id'];      ?> </td> <td> 
            <?php  echo $row['nombre'];  ?> </td>
            <td> <?php  echo $row['precio'];  ?> </td>
          </tr>
  <?php }  ?>  
</table> 
