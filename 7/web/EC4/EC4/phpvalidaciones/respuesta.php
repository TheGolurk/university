<?php include 'includes/header.php'  ?>
    <?php 
    $nombre=$_POST['nombre'];
    $app=$_POST['app'];
    $apm=$_POST['apm'];
    $comentario=$_POST['mensaje'];

//Validaciones mediante cuadros de texto
?>
<?php
//isset: determina si una variable ha sido declarada y su valor no es NULO.
//trim: recorta una cadena al eliminar espacios a la izquierda y a la derecha o al eliminar caracteres que coincidan con una cadena especificada opcional.   
if(!isset($nombre)||trim($nombre)!=''){?>
<p>Nombre: <?php echo"$nombre"; ?> </p> 
<?php } else {
   echo"<br>El nombre es obligatorio";
}?>

<?php
if(!isset($app)||trim($app)!=''){?>
<p>Apellido Paterno: <?php echo"$app"; ?> </p> 
<?php } else {
   echo"<br>El Apellido paterno es obligatorio";
}?>
<?php
if(!isset($apm)||trim($apm)!=''){?>
<p>Apellido Materno: <?php echo"$apm"; ?> </p> 
<?php } else {
   echo"<br>El Apellido Materno es obligatorio";
}?>

<?php   if(isset($_POST['carrera'])){
            $cursos = $_POST['carrera'];
            echo"la carrera que elegiste es:<br>";
            foreach($cursos as $curso){
                echo"$curso <br>";
            }
        }else{
            echo"Elije por lo menos  una carrera";
        }

?>

<?php if(isset($_POST['area'])){
        $area = $_POST['area'];
        echo"Area de Especializacion: ";
        switch($area){
            case '1':
                echo"Front end y Back end";
            break;
            case '2':
                echo"Arduino e IOT";
            break;
            case '3':
                echo"Relacional y E-R";
            break;
            case '4':
                echo"Diferencial e Integral";
            break;
            default:
                echo"Opcion Invalida";
            break;
        }
    }
?>