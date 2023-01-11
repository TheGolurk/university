<?php include 'includes/header.php'?>
Estructuras Estaticas Arreglos
<?php
    echo"<hr>";
    //Declaracion de un arreglo como antes
    $tecnologias = ['HTML', 'CSS', 'JAVASCRIPT', 'PHP', 'MYSQL'];
    echo $tecnologias[0];
    echo"<br>";
    echo $tecnologias[1];
    echo"<br>";
    echo $tecnologias[2];
    echo"<br>";
    echo $tecnologias[3];
    echo"<br>";
    echo $tecnologias[4];
    echo"<hr>";
    //Declaracion de un arreglo en la actualidad
    $ide = array('Visual Code', 'Atom', 'Sublime', 'Notepad++', 'Brackets');
    echo $ide[4];
    echo $ide[3];
    echo $ide[4];
    echo $ide[1];
    echo $ide[0];
?>
