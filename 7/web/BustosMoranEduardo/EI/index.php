<?php include 'includes/header.php';?>
<?php

session_start();
error_reporting(0);

$validar = $_SESSION['usuario'];

if( $validar == null || $validar = ''){

    header("Location: login.php");
    die();
    
    

}



?>
<!DOCTYPE html>
<html lang="es-MX">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Registros</title>

	<link rel="stylesheet" href="./css/es.css">
    <link rel="stylesheet" href="./css/styles.css">
</head>

<body id="page-top">


<form  action="validar.php" method="POST">
    <div id="login" >
        <br>
        <br>
        <h3 class="text-center">Registro de nuevo usuario</h3>
        <div class="form_container">
            <label for="nombre" class="formulario_label">Nombre *</label>
            <input type="text"  id="usuario" name="usuario" class="formulario_input" required>
        </div>
        <div class="form_container">
            <label for="password" class="formulario_label">Contraseña:</label><br>
            <input type="password" name="contrasena" id="contrasena" class="formulario_input" required>
        </div>  

    <div class="form_container">
        <label for="rol" class="formulario_label">Rol de usuario *</label>
        <input type="number"  id="rol" name="rol" class="formulario_input" placeholder="Escribe el rol, 1 admin, 2 usuario.." min="1" max="2">
    </div>
    <br>
    <div class="mb-3">
        <input type="submit" value="Guardar"class="btn btn-success" 
            name="registrar">
        <a href="Servicios.php" class="btn btn-danger">Cancelar</a>
    </div>  
    </div>
</form>
</body>
</html>