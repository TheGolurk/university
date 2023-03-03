<?php
  session_start();
  if (!isset($_SESSION['nombre'])) {
    header("Location: index.php");
  }

  $id_pro = $_GET["id"];
  $action = $_GET["action"];

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

  if ($action == "delete") {
    // Consultar productos
    $sql = "DELETE FROM producto WHERE ID_PRODUCTO=$id_pro";
    $result = mysqli_query($conn, $sql);

    // Verificar consulta
    if ($result) {
      header("Location: mis-productos.php");
    } else {
      echo "Error al eliminar producto.";
    }
  } else if ($action == "update") {
    // Modificar producto
  }

  // Cerrar conexión
  mysqli_close($conn);
?>
