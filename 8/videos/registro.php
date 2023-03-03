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
        creando usuario
    </div>
    <?php
    $host = "localhost:3306";
    $user = "root";
    $pass = "root";
    $dbname = "compratodo";

    // Conectar a la base de datos
    $conn = mysqli_connect($host, $user, $pass, $dbname);

    if (!$conn) {
        header("Location: index.php");
        exit;
    }

    $nombre = (isset($_POST["logname"]) && !empty($_POST["logname"])) ? $_POST["logname"] : null;
    $ape = (isset($_POST["logape"]) && !empty($_POST["logape"])) ? $_POST["logape"] : null;
    $correo = (isset($_POST["logemail"]) && !empty($_POST["logemail"])) ? $_POST["logemail"] : null;
    $contraseña = (isset($_POST["logpass"]) && !empty($_POST["logpass"])) ? $_POST["logpass"] : null;
    $dir = (isset($_POST["logdir"]) && !empty($_POST["logdir"])) ? $_POST["logdir"] : null;

    // Comprobar si todos los campos están definidos y no están vacíos
    if (!$nombre || !$ape || !$correo || !$contraseña || !$dir) {
        header("Location: login.php");
        exit;
    }

    $sql = "INSERT INTO usuarios (NOMBRE, APELLIDO, CORREO, PASS, DIRECCION)
                VALUES ('$nombre', '$ape', '$correo', '$contraseña', '$dir')";

    $result = mysqli_query($conn, $sql);

    if (!$result) {
        echo "Error al insertar el registro: " . mysqli_error($conn);
        exit;
    }
    ?>
    <script type="text/javascript">
    setTimeout( function() { window.location.href = "index.php"; }, 1000 );
    </script>
</body>
</html>

