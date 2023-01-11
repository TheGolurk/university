<?php include 'includes/header.php'?>
Operaciones Aritmeticas con PHP

<?php
    echo"<hr>";
    echo"10+20: " .(10+20);
?>

    <hr>

<?php
    $numero1 = 10;
    $numero2 = 20;
    $numero3 = 30;
    $numero4 = 40;
    //suma
    echo $numero1 + $numero2;
    echo"<hr>";
    //resta
    echo $numero4 - $numero3;
    echo"<hr>";
    //multiplicar
    echo $numero1 * $numero2;
    echo"<hr>";
    //division
    echo $numero4 / $numero1;
    echo"<hr>";
    //Uso de Parentesis
    echo ($numero1 + $numero2) * ($numero1 * .16);
    echo"<hr>";
    //incremento en 1
    echo"<hr>";
    $numero1++;
    echo$numero1;
    //decrementar en 1
    echo"<hr>";
    $numero1--;
    echo$numero1;
    //residuo
    echo"<hr>";
    echo 20%3;
?>
