<?php
  session_start();
  if (!isset($_SESSION['nombre'])) {
    echo "Sesion no iniciada";
  }else{
    echo $_SESSION['nombre'];
  }
  $id_usu = $_SESSION["id"];
?>

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

$id_producto = isset($_POST['id_producto']) ? $_POST['id_producto'] : "";
$cantidad = isset($_POST['cantidad']) ? $_POST['cantidad'] : "";

if ($id_producto != "" && $cantidad != "") {
  // Obtener los valores del producto
  $sql = "SELECT * FROM producto WHERE ID_PRODUCTO=" . $id_producto;
  $result = mysqli_query($conn, $sql);

  if (mysqli_num_rows($result) > 0) {
    $row = mysqli_fetch_assoc($result);
    $nombre = $row['NOMBRE'];
    $precio = $row['PRECIO'];
    $cantidad_disponible = $row['CANT_DIS'];
    
    // Calcular el total de la compra
    $total = $precio * $cantidad;
    

    // Insertar la compra en la base de datos
    $sql = "INSERT INTO compra (ID_PROD, ID_USUA, CANTIDAD, TOTAL, FECHA) VALUES ('$id_producto', '$id_usu', '$cantidad', '$total', NOW())";

    if (mysqli_query($conn, $sql)) {
      // Actualizar la cantidad disponible del producto
      $cantidad_disponible -= $cantidad;
      $sql = "UPDATE producto SET CANT_DIS='$cantidad_disponible' WHERE ID_PRODUCTO='$id_producto'";
      mysqli_query($conn, $sql);
      
      // Redirigir al usuario a la página de confirmación de compra
      header("Location: confirmacion.php?id_producto=".$id_producto);
      exit();
    } else {
      echo "Error: " . $sql . "<br>" . mysqli_error($conn);
    }
  }
}
?>
