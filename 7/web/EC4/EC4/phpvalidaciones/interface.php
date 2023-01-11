<?php include 'includes/header.php'  ?>
<form method="post" action="respuesta.php">
<label> Nombre:
<input type="text" name="nombre">
</label>
<br>
<label> Apellido Parterno:
<input type="text" name="app">
</label>
<br>
<label> Apellido Marterno:
<input type="text" name="apm">
</label>
<hr>
<label> ITI
<input type="checkbox" name="carrera[]" value="ITI">
</label>
<label> IET
<input type="checkbox" name="carrera[]" value="IET">
</label>
<label> IBT
<input type="checkbox" name="carrera[]" value="IBT">
</label>
<hr>
<select name="area">
<option value="1">Programación Web</option>
<option value="2">Dómotica</option>
<option value="3">Base de datos</option>
<option value="4">Control</option>
</select>
<hr>
<label> PRESENCIAL:
<input type="radio" name="opciones[]" value="presencial">
</label>
<label>ON LINE:
<input type="radio" name="opciones[]" value="online">
</label>
<hr>
<label>Comentarios:<br>
<textarea name="mensaje" rows="8" cols="40"></textarea>
</label>
<br>
<input type="submit" value="ENVIAR">

</form>