<?php include 'includes/header.php'?>
Concatenación entre cadenas y variables

<?php
    $nombre = "Eduardo";
    $Apellido_paterno = "Bustos";
    $Apellido_materno = "Moran";
    $edad = 20;
    echo"<hr>";
    echo $nombre . " " . $Apellido_paterno . " " . $Apellido_materno;
    echo"<hr>";
    echo "<h2>Mi nombre es: " . $nombre . " y mi edad Es: " . $edad."</h2>";
    echo"<hr>";
    echo"<h1>{$nombre} {$Apellido_paterno}</h1>";    
?>
<?php include 'includes/footer.php'?>