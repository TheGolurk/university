<?php include 'includes/header.php'?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Conversion de Metros a Centimetros</title>
</head>
<body>
    <?php 
        $metros = $_POST['txtmetros'];
        $centimetros = $metros*100;
    ?>
    <form method='post' action='ConvCM.php'>
        Metros <input type="text" name="txtmetros" disabled>
        <br><br>
        Resultado: <input type="text" value="<?php echo $centimetros; ?>" disabled>
        <br><br>
        <a href="interfaz2.php">Pulsa Aqui para volver a calcular</a>
    </form>
</body>
</html>
