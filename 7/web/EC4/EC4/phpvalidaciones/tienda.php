<?php include 'includes/header.php'  ?>
<script src="js/bootstrap.min.js"></script>
<?php 
    $art=$_POST['txtart'];
    $precio=$_POST['txtpre'];
?>
<table class="table table-dark">
<thead class="thead-dark">
<tr>
    <td>Articulo</td> <td>Codigo</td> <td>Precio</td> <td>Precio con descuento</td>
</tr>
</thead>
<?php 
    if(isset($_POST['opc'])){
        $codigo = $_POST['opc'];
        switch($codigo){
            case '1':
                $preciocd = $precio * .90;
                echo"<tr>";
                    echo"<td>$art</td>";
                    echo"<td>$codigo</td>";
                    echo"<td>$precio</td>";
                    echo"<td>$preciocd</td>";
                echo"</tr>";
                break;
            case '2':
                $preciocd = $precio * .80;
                echo"<tr>";
                    echo"<td>$art</td>";
                    echo"<td>$codigo</td>";
                    echo"<td>$precio</td>";
                    echo"<td>$preciocd</td>";
                echo"</tr>";
                break;
            default:
                echo"Articulo no existe";
                break;
        }
    }
?>
</table>
<a href="interface2.php">Back</a>
