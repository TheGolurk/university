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
    <form method='post' action='ConvCM.php'>
    Metros <Select name=txtmetros>
                <option>5</option>
                <option>10</option>
                <option>15</option>
                <option>20</option>
                <option>30</option>
                <option>40</option>
                <option>50</option>
                </Select> 
        <br><br>
        <input type="submit" value="Calcular">
    </form>
</body>
</html>