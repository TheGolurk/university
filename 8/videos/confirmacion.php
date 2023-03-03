<?
    $id_producto = isset($_GET['id_producto']) ? $_GET['id_producto'] : "";
    // Conexión a la base de datos
    $host = "localhost:3306";
    $user = "root";
    $pass = "root";
    $dbname = "compratodo";

    // Conectar a la base de datos
    $conn = mysqli_connect($host, $user, $pass, $dbname);

    // Verificar conexión
    if (!$conn) {
    die("Conexión fallida: " . mysqli_connect_error());
    }
    // Obtener la cantidad disponible del producto
    $sql = "SELECT CANT_DIS FROM producto WHERE ID_PRODUCTO='$id_producto'";
    $result = mysqli_query($conn, $sql);

    // Verificar si la cantidad disponible es igual a cero
    if ($cantidad_disponible == 0) {
        // Eliminar el producto de la base de datos
        $sql = "DELETE FROM producto WHERE ID_PRODUCTO='$id_producto'";
        mysqli_query($conn, $sql);
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
        <b>Compra Realizada</b>
    </div>
<script type="text/javascript">
   setTimeout( function() { window.location.href = "index.php"; }, 1000 );
</script>
</body>
</html>