<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link href="css/estilos.css" rel="stylesheet" type="text/css">
    <link href="css/normalize.css" rel="stylesheet" type="text/css">
    <title>Aplicativo de converciones</title>
</head>
<body>
    <section class="questions container">
            <h2 class="subtitle">Que deseas Calcular</h2>

            <section class="questions__container">
                <article class="questions__padding">
                    <div class="questions__answer">
                        <h3 class="questions__title">dólares a pesos
                        </h3>
                            <form method='post' action='dolares.php'>
                                dolares: <input type="text" name="txtdolares" >
                                <br><br>
                                <input type="submit" value="Calcular">
                            </form>
                            <br>
                    </div>
                </article>

                <article class="questions__padding">
                    <div class="questions__answer">
                        <h3 class="questions__title">pesos a dolares
                        </h3>
                            <form method='post' action='peso.php'>
                                pesos: <input type="text" name="txtpesos" >
                                <br><br>
                                <input type="submit" value="Calcular">
                            </form>
                            <br>
                    </div>
                </article>

                <article class="questions__padding">
                    <div class="questions__answer">
                        <h3 class="questions__title">metros a centimetros
                        </h3>
                            <form method='post' action='metros.php'>
                                metros: <input type="text" name="txtmetros" >
                                <br><br>
                                <input type="submit" value="Calcular">
                            </form>
                            <br>
                    </div>
                </article>

                <article class="questions__padding">
                    <div class="questions__answer">
                        <h3 class="questions__title">centimetros a pulgadas
                        </h3>
                            <form method='post' action='centimetros.php'>
                                centrimetros: <input type="text" name="txtcentimetros" >
                                <br><br>
                                <input type="submit" value="Calcular">
                            </form>
                            <br>
                    </div>
                </article>

                <article class="questions__padding">
                    <div class="questions__answer">
                        <h3 class="questions__title">metros a yardas
                        </h3>
                            <form method='post' action='metrosyar.php'>
                                metros: <input type="text" name="txtmetros" >
                                <br><br>
                                <input type="submit" value="Calcular">
                            </form>
                            <br>
                    </div>
                </article>

                <article class="questions__padding">
                    <div class="questions__answer">
                        <h3 class="questions__title">yardas a metros
                        </h3>
                            <form method='post' action='yardas.php'>
                                yardas: <input type="text" name="txtyardas" >
                                <br><br>
                                <input type="submit" value="Calcular">
                            </form>
                            <br>
                    </div>
                </article>
                <article class="questions__padding">
                    <div class="questions__answer">
                        <h3 class="questions__title">litros a galones
                        </h3>
                            <form method='post' action='litros.php'>
                                litros: <input type="text" name="txtlitros" >
                                <br><br>
                                <input type="submit" value="Calcular">
                            </form>
                            <br>
                    </div>
                </article>

                <article class="questions__padding">
                    <div class="questions__answer">
                        <h3 class="questions__title">kilometros a pies, millas, metros, centimetros
                        </h3>
                            <form method='post' action='kilometros.php'>
                                Kilometros: <input type="text" name="txtkilometros" >
                                <br><br>
                                <input type="submit" value="Calcular">
                            </form>
                            <br>
                    </div>
                </article>

                <article class="questions__padding">
                    <div class="questions__answer">
                        <h3 class="questions__title">año de nacimiento a edad
                        </h3>
                            <form method='post' action='anio.php'>
                                Año de nacimiento: <input type="text" name="txtaño" >
                                <br><br>
                                <input type="submit" value="Calcular">
                            </form>
                            <br>
                    </div>
                </article>

                <article class="questions__padding">
                    <div class="questions__answer">
                        <h3 class="questions__title">edad a año de nacimiento
                        </h3>
                            <form method='post' action='edad.php'>
                                edad: <input type="text" name="txtedad" >
                                <br><br>
                                <input type="submit" value="Calcular">
                            </form>
                            <br>
                    </div>
                </article>
            </section>
            <script src="./js/questions.js"></script>
</body>
</html>