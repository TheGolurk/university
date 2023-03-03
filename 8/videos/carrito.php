<?php
  session_start();
  if (!isset($_SESSION['nombre'])) {
    echo "Sesion no iniciada";
  }else{
    echo $_SESSION['nombre'];
  }
  $id_usu = $_SESSION["id"];
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/6.2.1/css/all.min.css">
    <link rel="stylesheet" href="css/estilo.css">
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.0-alpha1/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-GLhlTQ8iRABdZLl6O3oVMWSktQOp6b7In1Zl3/Jr59b6EGGoI1aFkw7cmDA6j6gD" crossorigin="anonymous">
    <title>Tienda Online</title>
</head>
<body>
    <header class="main-header">
        <div class="container container--flex">
          <div class="main-header__container">
            <h1 class="main-header__title">CompraTodo.com</h1>
            <span class="icon-menu" id="btn-menu"><i class="fas fa-bars"></i></span>
            <nav class="main-nav" id="main-nav">
              <ul class="menu">
                <li class="menu__item"><a href="index.php" class="menu__link">INICIO</a></li>
                <li class="menu__item"><a href="producto.php" class="menu__link">AGREGAR PRODUCTO</a></li>
                <li class="menu__item"><a href="cerrar-sesion.php" class="menu__link">CERRAR SESIÓN</a></li>
                <li class="menu__item"><a href="mis-productos.php" class="menu__link">MIS PRODUCTOS</a></li>
                <li class="menu__item"><a href="mis-compras.php" class="menu__link">MIS COMPRAS</a></li>
              </ul>
            </nav>
          </div>
          <div class="main-header__container">
            <span class="main-header__txt">Necesitas Ayuda?</span>
            <p class="main-header__txt"><i class="fas fa-phone"></i> Llama al 7352233960</p>
          </div>
          <div class="main-header__container">
          <a href="login.php" class="main-header__link"><?php if (isset($_SESSION['nombre'])) {echo $_SESSION['nombre'];}?> <i class="fas fa-user"></i></a>
          </div>
        </div>
      </header>
      <main class="main">
        <div class="container">
          <h2 class="main-title">Mira Tu Carrito, Si no quiere comprar nada salga</h2>
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

          $id = isset($_GET['id']) ? $_GET['id'] : "";

          if ($id != "") {
              // Recuperar los valores del producto
              $sql = "SELECT * FROM producto WHERE ID_PRODUCTO=" . $id;
              $result = mysqli_query($conn, $sql);

              if (mysqli_num_rows($result) > 0) {
                  $row = mysqli_fetch_assoc($result);
                  $id_producto = $row['ID_PRODUCTO'];
                  $nombre = $row['NOMBRE'];
                  $precio = $row['PRECIO'];
                  $cantidad = $row['CANT_DIS'];
                  $imagen = $row['IMAGEN'];
                  $id_usuario = $row['ID_USU'];

                  if ($id_usuario == $id_usu) {
                      echo "<p>No puedes comprar un producto que tú mismo ingresaste.</p>";
                  } else {
          ?>
                      <table class="table table-light mx-auto">
                          <thead>
                              <tr>
                                  <th scope="col">Nombre</th>
                                  <th scope="col">Precio</th>
                                  <th scope="col">Cantidad</th>
                                  <th scope="col">Comprar</th>
                              </tr>
                          </thead>
                          <tbody>
                              <form method="post" action="compra.php">
                                  <tr>
                                      <td><?= $nombre ?></td>
                                      <td><?= $precio ?></td>
                                      <td>
                                          <input type="number" name="cantidad" value="<?= 1 ?>" min="1" max="<?= $cantidad ?>" required>
                                      </td>
                                      <td>
                                          <input type="hidden" name="id_producto" value="<?= $id ?>">
                                          <button type="submit" class="btn btn-primary">Comprar</button>
                                      </td>
                                  </tr>
                              </form>
                          </tbody>
                      </table>
          <?php
                  }
              }
          }
          ?>
          <p></p>
        </div>
      </main>
      <footer class="main-footer">
        <div class="footer__section">
          <h2 class="footer__title">Sobre Nosotros</h2>
          <p class="footer__txt">Somos una Alternativa a todas las paginas de marketplace actuales, el proposito es brindarte una grata experiencia en el comprar y vender productos</p>
        </div>
        <div class="footer__section">
          <h2 class="footer__title">Direccion :</h2>
          <p class="footer__txt">P.º Cuauhnáhuac 566, Lomas del Texcal, 62574 Jiutepec, Mor.</p>
          <h2 class="footer__title">Contacto</h2>
          <p class="footer__txt">Celular : +52 735 223 3960</p>
          <p class="footer__txt">Email : bmeo191668@upemor.edu.mx</p>
        </div>
        <div class="footer__section">
          <h2 class="footer__title">Quick Links</h2>
          <a href="" class="footer__link">Inicio</a>
          <a href="" class="footer__link">Registrar Producto</a>
        </div>
        <p class="copy">© 2021 CompraTodo.com. All Rights Reserved | Design by INCOG89</p>
      </footer>
</body>
</html>