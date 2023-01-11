<?php include 'includes/header.php';?>
    <H5>Agregar servicios</H5>
    <form method="POST" name="frm1" id="frm1" action="altaservicios.php">
    <div class="form_container">
     <label for="nombre" class="formulario_label">
     Nombre del servicio:</label>
     <input type="text" name="nombre" id="nombre" class="formulario_input">
    </div> 
    <div class="form_container">
     <label for="precio" class="formulario_label">
      Precio del servicio:</label>
     <input type="text" name="precio" id="precio" class="formulario_input"        
         onkeypress="if((event.keyCode < 48) || (event.keyCode >57)){
         event.returnValue=false;
          } "  maxlength="4">
    </div>                  
    <BR>
    <div class="form_container">                    
    <input type="button" value="Enviar Datos"  class="formulario_btn" onclick="validacion()">                    
    <script src='Static/js/appvlidacion.js'></script>         
</form>  
<hr>  
<a href="consultageneral.php">
            <img src="./Static/img/query.png">          
           </a> 
<a href="consultadeu.php">
            <img src="./Static/img/update.png">          
</a>          
<a href="Static/convertirpdf/excel.php">
         <img src="./Static/img/excelicon.png">          
</a> 
<a href="Static/convertirpdf/reporte.php">
         <img src="./Static/img/pdficon.png">          
</a>
<a href="logout.php">CERRAR SESION</a> 
<?php include 'includes/footer.php';?>