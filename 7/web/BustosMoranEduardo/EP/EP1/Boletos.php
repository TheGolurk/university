<?php include 'includes/header.php'  ?>
<?php
$boletos=$_POST['boletos'];
$descuento=$_POST['descuento'];
switch ($descuento) {
    case '1':
        $precioBoleto=(775*0.85)*$boletos;
        echo "<h2>Usted a Comprado $boletos boletos </h2>";
        echo "<h2>El total a pagar es  $precioBoleto</h2>";
        echo "<h2>Gracias por su compra</h2>";
        break;
    case '2':
        $precioBoleto=(775*0.82)*$boletos;
        echo "<h2>Usted a Comprado $boletos boletos </h2>";
        echo "<h2>El total a pagar es  $precioBoleto</h2>";
        echo "<h2>Gracias por su compra</h2>";
        break;
    case '3':
        $precioBoleto=(775*0.75)*$boletos;
        echo "<h2>Usted a Comprado $boletos boletos </h2>";
        echo "<h2>El total a pagar es  $precioBoleto</h2>";
        echo "<h2>Gracias por su compra</h2>";
        break;
    default:
        echo"opcion no valida";
        break;
}
?>

<?php include 'includes/footer.php'  ?>