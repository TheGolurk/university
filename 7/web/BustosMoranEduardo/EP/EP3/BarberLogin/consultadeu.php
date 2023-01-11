<?php include 'Static/connect/db.php';?>
<?php include 'includes/header.php';?>
<table class="table table-dark">
<thead>        
        <tr>
            <td>No.</td>  <td>Servicio</td>  <td>Inversión</td> <td>D U</td>
       </tr>
</thead>
<?php 
         $consulta="SELECT *FROM servicios;";
         $result=mysqli_query($conexion,$consulta);
        while($row = mysqli_fetch_array($result)){ ?>
          <tr>
            <td> <?php echo $row['id'];      ?> </td> <td> 
            <?php  echo $row['nombre'];  ?> </td>
            <td> <?php  echo $row['precio'];  ?> </td>
            <td> 
            <a href="eliminar.php?id=<?php echo $row['id'];?>">
            <img src="./Static/img/d.png">          
           </a>  
            <a href="actualizar.php?id=<?php echo $row['id'];?>">
            <img src="./Static/img/EA.png">         
          </a> 
           </td>            
          </tr>
  <?php }  ?>  
</table> 