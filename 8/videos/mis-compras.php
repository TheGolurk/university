<?php
session_start();
if (!isset($_SESSION['nombre'])) {
  header("Location: index.php");
}
$id_usu = $_SESSION["id"];
?>

<!DOCTYPE html>
<html lang="en">
  <head>
    <meta charset="UTF-8" />
    <meta http-equiv="X-UA-Compatible" content="IE=edge" />
    <meta name="viewport" content="width=device-width, initial-scale=1.0" />
    <link
      rel="stylesheet"
      href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/6.2.1/css/all.min.css"
    />
    <link rel="stylesheet" href="css/estiloProd.css" />
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.0-alpha1/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-GLhlTQ8iRABdZLl6O3oVMWSktQOp6b7In1Zl3/Jr59b6EGGoI1aFkw7cmDA6j6gD" crossorigin="anonymous">
    <title>Tienda Online</title>
  </head>
  <body>
    <header class="main-header">
      <div class="container container--flex">
        <div class="main-header__container">
          <h1 class="main-header__title">CompraTodo.com</h1>
          <span class="icon-menu" id="btn-menu"
            ><i class="fas fa-bars"></i
          ></span>
          <nav class="main-nav" id="main-nav">
            <ul class="menu">
              <li class="menu__item"><a href="index.php" class="menu__link">INICIO</a></li>
              <li class="menu__item"><a href="producto.php" class="menu__link">AGREGAR PRODUCTO</a></li>
            </ul>
          </nav>
        </div>
        <div class="main-header__container">
          <span class="main-header__txt">Necesitas Ayuda?</span>
          <p class="main-header__txt"
            ><i class="fas fa-phone"></i> Llama al 7352233960</p>
        </div>
        <div class="main-header__container">
        <a href="login.php" class="main-header__link"><?php if (isset($_SESSION['nombre'])) {echo $_SESSION['nombre'];}?> <i class="fas fa-user"></i></a>
        </div>
      </div>
    </header>
    <script src="js/slider.js"></script>
    <main class="main">
      <div class="container">
        <h2 class="main-title">Todas tus Compras</h2>
            <table class="table table-light mx-auto">
              <thead>
                <tr>
                  <th scope="col">ID Compra</th>
                  <th scope="col">ID Producto</th>
                  <th scope="col">Cantidad</th>
                  <th scope="col">Precio</th>
                  <th scope="col">Fecha</th>
                </tr>
              </thead>
              <tbody>
                <?php
                // Conexión a la base de datos
                $host = "localhost:3306";
                $user = "root";
                $pass = "root";
                $dbname = "compratodo";

                // Conectar ala base de datos
                $conn = mysqli_connect($host, $user, $pass, $dbname);
                // Verificar la conexión
                if (!$conn) {
                    die("La conexión ha fallado: " . mysqli_connect_error());
                }
    
                // Consulta para obtener todas las compras del usuario
                $query = "SELECT * FROM compra WHERE ID_USUA = $id_usu";
                $result = mysqli_query($conn, $query);
    
                // Iterar sobre los resultados de la consulta y mostrarlos en la tabla
                while ($row = mysqli_fetch_assoc($result)) {
                    echo "<tr>";
                    echo "<td>" . $row['ID_COMPRA'] . "</td>";
                    echo "<td>" . $row['ID_PROD'] . "</td>";
                    echo "<td>" . $row['CANTIDAD'] . "</td>";
                    echo "<td>" . $row['TOTAL'] . "</td>";
                    echo "<td>" . $row['FECHA'] . "</td>";
                    echo "</tr>";
                }
    
                // Cerrar la conexión a la base de datos
                mysqli_close($conn);
                ?>
                </tbody>
            </table>
        </div>
    </main>
    <script src="js/menu.js"></script>
    
