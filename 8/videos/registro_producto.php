<?php
session_start();
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
        Creando Producto
    </div>
    <?php
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
        // Recibir datos del formulario
        $nombre = $_POST["nombre"];
        $precio = $_POST["precio"];
        $cantidad = $_POST["cantidad"];
    
        // Recibir imagen
        if (isset($_FILES["imagen"]) && !empty($_FILES["imagen"]["tmp_name"])) {
            $imagen = $_FILES["imagen"];
            $extension = pathinfo($imagen["name"], PATHINFO_EXTENSION);
            $extension = strtolower($extension);
            $formatos_permitidos = array("jpeg", "png", "gif", "jpg");
    
            if (!in_array($extension, $formatos_permitidos)) {
                echo "Error: Formato de imagen no permitido.";
                exit;
            }
    
            $nombre_imagen = uniqid() . '.' . $extension;
            $ruta = 'imgBasedeDatos/' . $nombre_imagen;
            move_uploaded_file($imagen["tmp_name"], $ruta);
        } else {
            echo "Error: No se seleccionó una imagen válida.";
            exit;
        }
    
        // Recibir ID de usuario de la sesión
        $id_usu = $_SESSION["id"];
    
        // Insertar datos a la base de datos
        $sql = "INSERT INTO producto (NOMBRE, PRECIO, CANT_DIS, IMAGEN, ID_USU)
        VALUES ('$nombre', '$precio', '$cantidad', '$ruta', '$id_usu')";
    
        if (mysqli_query($conn, $sql)) {
            echo "Registro de producto exitoso";
        } else {
            echo "Error: " . $sql . "<br>" . mysqli_error($conn);
        }
    
        // Cerrar conexión
        mysqli_close($conn);
    
        ?>
        <script type="text/javascript">
        setTimeout( function() { window.location.href = "index.php"; }, 1000 );
        </script>
    </body>
</html>
    
