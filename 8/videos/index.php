<?php
  session_start();
  if (!isset($_SESSION['nombre'])) {
    echo "Sesion no iniciada";
  }
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/6.2.1/css/all.min.css">
    <link rel="stylesheet" href="css/estilo.css">
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
                <li class="menu__item"><a href="" class="menu__link">INICIO</a></li>
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
      <div class="container-slider">
        <div class="slider" id="slider">
          <div class="slider__section">
            <img src="imgSlide/img1.jpg" alt="" class="slider__img">
            <div class="slider__content">
              <a href="" class="btn-shop">Compra Ya!</a>
            </div>
          </div>
          <div class="slider__section">
            <img src="imgSlide/img2.jpg" alt="" class="slider__img">
            <div class="slider__content">
              <a href="" class="btn-shop">Compra Ya!</a>
            </div>
          </div>
          <div class="slider__section">
            <img src="imgSlide/img3.jpg" alt="" class="slider__img">
            <div class="slider__content">
              <a href="" class="btn-shop">Compra Ya!</a>
            </div>
          </div>
          <div class="slider__section">
            <img src="imgSlide/img4.jpg" alt="" class="slider__img">
            <div class="slider__content">
              <a href="" class="btn-shop">Compra Ya!</a>
            </div>
          </div>
          <div class="slider__section">
            <img src="imgSlide/img5.jpg" alt="" class="slider__img">
            <div class="slider__content">
              <a href="" class="btn-shop">Compra Ya!</a>
            </div>
          </div>
        </div>
        <div class="slider__btn slider__btn--right" id="btn-right">&#62;</div>
        <div class="slider__btn slider__btn--left" id="btn-left">&#60;</div>
      </div>
      <script src="js/slider.js"></script>
      <main class="main">
        <div class="container">
          <h2 class="main-title">Mira Todos Los Productos</h2>
          <section class="container-products">
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
              echo "Failed to connect to MySQL: " . $mysqli -> connect_error;
              die("Conexión fallida: " . mysqli_connect_error());
          }

          // Consultar productos
          $sql = "SELECT * FROM producto";
          $result = mysqli_query($conn, $sql);

          // Verificar consulta
          if (mysqli_num_rows($result) > 0) {
            while ($row = mysqli_fetch_assoc($result)) {
            // Decodificar imagen
            $nombre = $row["NOMBRE"];
            $precio = $row["PRECIO"];
            $imagen = $row["IMAGEN"];
            $cantidad = $row["CANT_DIS"];
            if ($cantidad > 0) {
            ?>
            <div class="product">
            <img src="<?php echo $imagen; ?>" alt="" class="product__img" type="image/jpeg">
            <div class="product__description">
            <h3 class="product__title"><?php echo $nombre; ?></h3>
            <span class="product__price">$<?php echo $precio; ?></span>
            </div>
            <a href="carrito.php?id=<?php echo $row["ID_PRODUCTO"]; ?>"><i class="product__icon fas fa-cart-plus"></i></a>
            </div>
            <?php
                           }
                       }
                   } else {
                       echo "No hay productos disponibles.";
                   }
                   // Cerrar conexión
                   mysqli_close($conn);
                   ?>
          </section>
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