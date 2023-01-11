<?php include 'includes/header.php'?>
Estructuras de control selectivo o bifurcativo
<?php
    echo"<hr>";
    $lenguaje = "HTML5";
    switch($lenguaje){
        case 'PHP':
            echo"Se trata de un lenguaje de programacion de back-end";
        break;

        case 'javaScript':
            echo"Se trata de un lenguaje de programacion de front-end y back-end";
        break;

        case 'CSS':
            echo"Se trata de un lenguaje de apariencia en una pagina Web y funciona en front-end";
        break;
            
        case 'HTML':
            echo"Se trata de un lenguaje de Etiquetado se encarga de estructura y contenido en Front-End";
        break;

        default;
            echo"Opcion no valida............";
        break;
    }

?>
