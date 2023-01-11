<?php include 'includes/header.php'?>
Funciones para probar  Arreglos
<?php
    echo"<hr>";
    //Versiones anteriores
    $tecnologias = ['HTML', 'CSS', 'JAVASCRIPT', 'PHP', 'MYSQL'];
?>
<!----Función print_r--->
<PRE>
    <?php
        print_r($tecnologias);
    ?>
</PRE>
<!----Función var_dump--->
<?php
    $ide = array('Visual Code', 'Atom', 'Sublime', 'Notepad++', 'Brackets');
?>
<PRE>
    <?php
        var_dump($ide);
    ?>
</PRE>
