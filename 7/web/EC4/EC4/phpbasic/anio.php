<?php include 'includes/header.php'?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Conversion de año de nacimiento a edad</title>
</head>
<body>
    <?php 
        $año = $_POST['txtaño'];
        $edad = date("Y") - $año;
    ?>
    <form method='post' action='anio.php'>
        Año <input type="text" name="txtaño" value="<?php echo $año; ?>" disabled>
        <br><br>
        Edad : <input type="text" value="<?php echo $edad; ?>" disabled>
        <br><br>
        <a href="interfaz3.php">Pulsa Aqui para volver a calcular</a>
    </form>
</body>
</html>
