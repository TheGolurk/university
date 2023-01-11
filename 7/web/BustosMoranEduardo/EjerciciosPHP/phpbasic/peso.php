<?php include 'includes/header.php'?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Conversion de Pesos a Dolares</title>
</head>
<body>
    <?php 
        $pesos = $_POST['txtpesos'];
        $dolares = $pesos/20;
    ?>
    <form method='post' action='peso.php'>
        pesos <input type="text" name="txtpesos" value="<?php echo $pesos; ?>" disabled>
        <br><br>
        Resultado: <input type="text" value="<?php echo $dolares; ?>" disabled>
        <br><br>
        <a href="interfaz3.php">Pulsa Aqui para volver a calcular</a>
    </form>
</body>
</html>