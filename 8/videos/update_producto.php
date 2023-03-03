<?php
session_start();
  if (!isset($_SESSION['nombre'])) {
    header('Location: index.php');
  }
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

    $id = isset($_GET['id']) ? $_GET['id'] : "";

    if ($id != "") {
        // Recuperar los valores del producto
        $sql = "SELECT * FROM producto WHERE ID_PRODUCTO=" . $id;
        $result = mysqli_query($conn, $sql);

        if (mysqli_num_rows($result) > 0) {
            $row = mysqli_fetch_assoc($result);
            $nombre = $row['NOMBRE'];
            $precio = $row['PRECIO'];
            $cantidad = $row['CANT_DIS'];
            $imagen = $row['IMAGEN'];
        }
    }
?>
<!DOCTYPE html>
<html lang="en" >
<head>
  <meta charset="UTF-8">
  <title>Registro de Producto</title>
  <link rel='stylesheet' href='https://cdnjs.cloudflare.com/ajax/libs/twitter-bootstrap/4.5.0/css/bootstrap.min.css'>
  <link rel='stylesheet' href='https://unicons.iconscout.com/release/v2.1.9/css/unicons.css'><link rel="stylesheet" href="css/styleLogin.css">
  <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/6.2.1/css/all.min.css">
</head>
<body>
	<div class="section">
		<div class="container">
			<div class="row full-height justify-content-center">
				<div class="col-12 text-center align-self-center py-5">
					<div class="section pb-5 pt-5 pt-sm-2 text-center">
			          	<label for="reg-log"></label>
						<div class="card-3d-wrap mx-auto">
							<div class="card-3d-wrapper">
								<div class="card-front">
									<div class="center-wrap">
										<div class="section text-center">
                                        <form id="formP" action="actualizar_producto.php" method="POST" enctype="multipart/form-data">
                                            <h4 class="mb-4 pb-3">Actualizacion de Producto</h4>
                                            <div class="form-group">
                                                <input type="text" name="nombre" class="form-style" value="<?php echo $nombre; ?>" placeholder="Nombre" id="nombre" autocomplete="off">
                                                <i class="input-icon uil uil-shopping-bag"></i>
                                            </div>
                                            <div class="form-group mt-2">
                                                <input type="number" name="precio" class="form-style" value="<?php echo $precio; ?>" placeholder="Precio" id="precio" autocomplete="off">
                                                <i class="input-icon uil uil-bill"></i>
                                            </div>
                                            <div class="form-group mt-2">
                                                <input type="number" name="cantidad" class="form-style" value="<?php echo $cantidad; ?>" placeholder="Cantidad de Producto" id="cantidad" autocomplete="off">
                                                <i class="input-icon uil uil-circle-layer"></i>
                                            </div>
                                            <div class="form-group mt-2">
                                                <input type="file" name="imagen" class="form-style" id="imagen" accept="image/*" value="<?php echo $imagen; ?>">
                                                <i class="input-icon uil uil-bring-bottom"></i>
                                            </div>
                                            <a class="btn mt-4" id="btn-send" type="submit">Enviar</a>
                                            <p class="mb-0 mt-4 text-center"><a href="mis-productos.php" class="link">Regresar a Inicio</a></p>
                                            <input type="hidden" name="id" id="id" value="<?php echo $id; ?>">
                                        </form>
				      					</div>
			      					</div>
			      				</div>
			      			</div>
			      		</div>
			      	</div>
		      	</div>
	      	</div>
	    </div>
	</div>
	<script  src="js/scriptbtnUP.js"></script>
</body>
</html>
