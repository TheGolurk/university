<?php
session_start();
  if (isset($_SESSION['nombre'])) {
    header('Location: index.php');
  }
?>

<!DOCTYPE html>
<html lang="en" >
<head>
  <meta charset="UTF-8">
  <title>Login/Register</title>
  <link rel='stylesheet' href='https://cdnjs.cloudflare.com/ajax/libs/twitter-bootstrap/4.5.0/css/bootstrap.min.css'>
<link rel='stylesheet' href='https://unicons.iconscout.com/release/v2.1.9/css/unicons.css'><link rel="stylesheet" href="css/styleLogin.css">

</head>
<body>
	<div class="section">
		<div class="container">
			<div class="row full-height justify-content-center">
				<div class="col-12 text-center align-self-center py-5">
					<div class="section pb-5 pt-5 pt-sm-2 text-center">
						<h6 class="mb-0 pb-3"><span>Iniciar Sesion </span><span>Registrarse</span></h6>
			          	<input class="checkbox" type="checkbox" id="reg-log" name="reg-log"/>
			          	<label for="reg-log"></label>
						<div class="card-3d-wrap mx-auto">
							<div class="card-3d-wrapper">
								<div class="card-front">
									<div class="center-wrap">
										<div class="section text-center">
											<form id="formLogin" action="iniciar.php" method="POST">
												<h4 class="mb-4 pb-3">Iniciar Sesion</h4>
												<div class="form-group">
													<input type="email" name="logemail" class="form-style" placeholder="Correo Electronico" id="logemail" autocomplete="off">
													<i class="input-icon uil uil-at"></i>
												</div>	
												<div class="form-group mt-2">
													<input type="password" name="logpass" class="form-style" placeholder="Contraseña" id="logpass" autocomplete="off">
													<i class="input-icon uil uil-lock-alt"></i>
												</div>
												<a class="btn mt-4" id="btn2-send" type="submit">Enviar</a>
											</form>
											<p class="mb-0 mt-4 text-center"><a href="index.php" class="link">Regresar a Inicio</a></p>
				      					</div>
			      					</div>
			      				</div>
								<div class="card-back">
									<div class="center-wrap">
										<div class="section text-center">
											<form id="form2" action="registro.php" method="POST">
												<h4 class="mb-4 pb-3">Registro de Usuario</h4>
												<div class="form-group">
													<input type="text" name="logname" class="form-style" placeholder="Nombre" id="logname" autocomplete="off">
													<i class="input-icon uil uil-user"></i>
												</div>
												<div class="form-group mt-2">
													<input type="text" name="logape" class="form-style" placeholder="Apellido/s" id="logape" autocomplete="off">
													<i class="input-icon uil uil-user"></i>
												</div>	
												<div class="form-group mt-2">
													<input type="email" name="logemail" class="form-style" placeholder="Correo Electronico" id="logemail" autocomplete="off">
													<i class="input-icon uil uil-at"></i>
												</div>	
												<div class="form-group mt-2">
													<input type="password" name="logpass" class="form-style" placeholder="Contraseña" id="logpass" autocomplete="off">
													<i class="input-icon uil uil-lock-alt"></i>
												</div>
												<div class="form-group mt-2">
													<input type="text" name="logdir" class="form-style" placeholder="Direccion" id="logdir" autocomplete="off">
													<i class="input-icon uil uil-house-user"></i>
												</div>
												<a class="btn mt-4" id="btn-send" type="submit">Enviar</a>
												<p class="mb-0 mt-4 text-center"><a href="index.php" class="link">Regresar a Inicio</a></p>
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
  	<script  src="js/scriptLogin.js"></script>
  	<script  src="js/scriptbtn2.js"></script>
</body>
</html>
