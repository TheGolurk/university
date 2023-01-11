<?php include 'includes/header.php'?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Conversion de Centimetros a Pulgadas</title>
</head>
<body>
    <?php 
        $centimetros = $_POST['txtcentimetros'];
        $pulgadas = $centimetros*0.393701;
    ?>
    <form method='post' action='centimetros.php'>
        Centimetros <input type="text" name="txtcentimetros" value="<?php echo $centimetros; ?>" disabled>
        <br><br>
        Resultado: <input type="text" value="<?php echo $pulgadas; ?>" disabled>
        <br><br>
        <a href="interfaz3.php">Pulsa Aqui para volver a calcular</a>
    </form>
</body>
</html>
