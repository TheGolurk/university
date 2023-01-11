<?php include 'includes/header.php'?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Conversion de edad a año de nacimiento</title>
</head>
<body>
    <?php 
        $edad = $_POST['txtedad'];
        $año = date("Y") - $edad;
    ?>
    <form method='post' action='edad.php'>
        Edad <input type="text" name="txtedad" value="<?php echo $edad; ?>" disabled>
        <br><br>
        Año de nacimiento : <input type="text" value="<?php echo $año; ?>" disabled>
        <br><br>
        <a href="interfaz3.php">Pulsa Aqui para volver a calcular</a>
    </form>
</body>
</html>