<?php include 'includes/header.php'  ?>
<form method="post" action="tienda.php">
    <h1>Venta de productos</h1>
    <label>Ingrese el nombre del articulo:
    <input type="text" name="txtart">
    </label>
    <label>Selecciona el codigo del articulo:
    <select name="opc">
        <option value= "1" >Codigo 1</option>
        <option value= "2" >Codigo 2</option>
    </select>
    </label>
    <label>Ingrese el precio del articulo:
    <input type="text" name="txtpre">
    </label>
    <br>
    <input type="submit" value="Asignar">
</form>
