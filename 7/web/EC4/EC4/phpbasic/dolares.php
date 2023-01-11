<?php include 'includes/header.php'?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Conversion de Dolares a Pesos</title>
</head>
<body>
    <?php 
        $dolares = $_POST['txtdolares'];
        $pesos = $dolares*20;
    ?>
    <form method='post' action='dolares.php'>
        dolares <input type="text" name="txtdolares" value="<?php echo $dolares; ?>" disabled>
        <br><br>
        Resultado: <input type="text" value="<?php echo $pesos; ?>" disabled>
        <br><br>
        <a href="interfaz3.php">Pulsa Aqui para volver a calcular</a>
    </form>
</body>
</html>