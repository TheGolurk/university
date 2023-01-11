     <?php include '../connect/db.php';?>   
     
     <?php
           header('Content-Type:application/xls');
           header('Content-Disposition: attachment;filename=test.xls');
    ?>
         <h1>CONSULTAR SERVICIOS Y PRECIOS</h1>
     <DIV>
      <TABLE>
       <THEAD>
           <TR>
             <TH>ID</TH>
             <TH>SERVICIOS</TH>
             <TH>PRECIOS</TH>
           </TR>
       </THEAD> 
        <?php 
             $query="SELECT *FROM servicios;";
             $resul_services=mysqli_query($conexion,$query);
               while($row=mysqli_fetch_array($resul_services))
                { ?>
                    <tr>
                       <TD> <?php echo $row['id']; ?> </TD>
                       <TD> <?php echo $row['nombre']; ?></TD>
                       <TD><?php echo $row['precio']; ?></TD>
                    </tr>
            <?php  }   ?>
       </TABLE>        
   </DIV>
