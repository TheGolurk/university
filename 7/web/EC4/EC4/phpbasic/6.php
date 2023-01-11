<?php include 'includes/header.php'?>
Estructuras de control selectivo o bifurcativo
<?php
    echo"<br>";
    if(1<0){
        echo"Nunca voy a visualizarme";
    }
    if(0<1){
        echo"Me visualizo";
    }
    echo"<br>";
    if(1<0){
        echo"Nunca voy a visualizarme";
    }else{
        echo"Entonces yo si me visualizo";
    }
    echo"<br>";
    $edad1 = 13;
    $edad2 = 12;
    if($edad1 < $edad2){
        echo"Nunca voy a visualizarme";
    }elseif($edad1 == $edad2){
            echo"iguales";
           }else{
                echo"Edad 2 es menor";
           }
    echo"<br>";
    $numero1 = 13;
    if($numero1%2==0){
        echo"El numero es par";
    }else{
        echo"El numero es impar";
    }
?>
