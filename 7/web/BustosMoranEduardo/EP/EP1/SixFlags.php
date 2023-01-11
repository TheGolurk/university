<?php include 'includes/header.php'  ?>
<!-- CSS only -->
<link href="https://cdn.jsdelivr.net/npm/bootstrap@5.2.2/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-Zenh87qX5JnK2Jl0vWa8Ck2rdkQ2Bzep5IDxbcnCeuOxjzrPF/et3URy9Bv1WTRi" crossorigin="anonymous">
<!-- JavaScript Bundle with Popper -->
<script src="https://cdn.jsdelivr.net/npm/bootstrap@5.2.2/dist/js/bootstrap.bundle.min.js" integrity="sha384-OERcA2EqjJCMA+/3y+gxIOqMEjwtxJY7qPCqsdltbNJuaOe923+mo//f6V8Qbsw3" crossorigin="anonymous"></script>
    <form method="POST" action="Boletos.php">
    <fieldset class="form-group">
        <div class="form-group">
        <legend class="col-form-label-lg">Entradas: $775 pesos</legend> 
            <label>Total de Boletos</label>
            <input type="number" id="boletos" name="boletos" min="0" class="form-control" aria-describedby="BoletosAyuda" placeholder="Coloque la cantidad de boletos">
            <small id="BoletosAyuda" class="form-text text-muted">Recuerda comprobar si es correcta la cantidad</small>
        </div>
        <br>
        <div class="form-group">
            <label for="exampleFormControlSelect1">Tipo de tarjeta:</label>
            <select class="form-control" name="descuento" id="descuento">
                <option value="1">PLATA</option>
                <option value="2">DORADA</option>
                <option value="3">PLATINO</option>
            </select>

        </div>
        <br>
        <div>
            <button type="submit" class="btn btn-primary" value="Enviar">Comprar</button>
        </div>
    </fieldset>
    </form>
</body>
</html>
<?php include 'includes/footer.php'  ?>