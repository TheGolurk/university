<?php include 'includes/header.php'?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Conversion de Litros a Galones</title>
</head>
<body>
    <?php 
        $litros = $_POST['txtlitros'];
        $galones = $litros*0.264172;
    ?>
    <form method='post' action='litros.php'>
        Litros <input type="text" name="txtlitros" value="<?php echo $litros; ?>" disabled>
        <br><br>
        Resultado: <input type="text" value="<?php echo $galones; ?>" disabled>
        <br><br>
        <a href="interfaz3.php">Pulsa Aqui para volver a calcular</a>
    </form>
</body>
</html>
