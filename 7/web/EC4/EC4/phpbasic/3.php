<?php include 'includes/header.php'?>
Concatenación entre cadenas y variables

<?php
    $nombre = "Lorena";
    $Apellido_paterno = "Valle";
    $Apellido_materno = "Gonzalez";
    $edad = 20;
    echo"<hr>";
    echo $nombre . " " . $Apellido_paterno . " " . $Apellido_materno;
    echo"<hr>";
    echo "<h2>Mi nombre es: " . $nombre . " y mi edad Es: " . $edad."</h2>";
    echo"<hr>";
    echo"<h1>{$nombre} {$Apellido_paterno}</h1>";    
?>
<?php include 'includes/footer.php'?>