<?php include 'includes/header.php'?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Conversion de kilometros a pies, millas, metros, centimetros</title>
</head>
<body>
    <?php 
        $kilometros = $_POST['txtkilometros'];
        $pies = $kilometros*3280.84;
        $millas = $kilometros*0.621371;
        $metros = $kilometros*1000;
        $centimetros = $kilometros*100000;
        
    ?>
    <form method='post' action='kilometros.php'>
        Kilometros <input type="text" name="txtkilometros" value="<?php echo $kilometros; ?>" disabled>
        <br><br>
        Resultado en pies: <input type="text" value="<?php echo $pies; ?>" disabled>
        <br><br>
        Resultado en millas: <input type="text" value="<?php echo $millas; ?>" disabled>
        <br><br>
        Resultado en metros: <input type="text" value="<?php echo $metros; ?>" disabled>
        <br><br>
        Resultado en centimetros: <input type="text" value="<?php echo $centimetros; ?>" disabled>
        <br><br>
        <a href="interfaz3.php">Pulsa Aqui para volver a calcular</a>
    </form>
</body>
</html>
