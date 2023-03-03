<?php
  session_start();

$user="root";
$pass="root";
$host="localhost:3306";
$datab="compratodo";

//conectar a la base de datos
$connection = mysqli_connect($host,$user,$pass);
$db=mysqli_select_db($connection,$datab);


$correo = $_POST['logemail'];
$contraseña = $_POST['logpass'];

$sql = "SELECT * FROM usuarios WHERE CORREO = '$correo' AND PASS = '$contraseña'";
$result = mysqli_query($connection, $sql);

if(mysqli_num_rows($result) == 1) {
    $row = mysqli_fetch_assoc($result);
    $_SESSION['nombre'] = $row['NOMBRE'];
    $_SESSION['id'] = $row['ID_USUARIO'];
} else {
    header("Location: error.php");
}
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="stylesheet" href="css/carga.css">
    <title>Document</title>
</head>
<body>
    <div class="center">
        <div class="lds-ripple">
            <div></div>
            <div></div>
        </div>
        <p><p><p>
        <b>Bienvenido usuario: <?php echo $_SESSION['nombre']; ?></b>
    </div>
<script type="text/javascript">
   setTimeout( function() { window.location.href = "index.php"; }, 1000 );
</script>
</body>
</html>
