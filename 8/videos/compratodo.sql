-- phpMyAdmin SQL Dump
-- version 5.2.0
-- https://www.phpmyadmin.net/
--
-- Servidor: 127.0.0.1
-- Tiempo de generación: 26-02-2023 a las 21:17:42
-- Versión del servidor: 10.4.27-MariaDB
-- Versión de PHP: 8.2.0

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Base de datos: `compratodo`
--

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `compra`
--

CREATE TABLE `compra` (
  `ID_COMPRA` int(11) NOT NULL,
  `ID_PROD` int(11) NOT NULL,
  `ID_USUA` int(11) NOT NULL,
  `CANTIDAD` int(11) NOT NULL,
  `TOTAL` float NOT NULL,
  `FECHA` timestamp NOT NULL DEFAULT current_timestamp() ON UPDATE current_timestamp()
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Volcado de datos para la tabla `compra`
--

INSERT INTO `compra` (`ID_COMPRA`, `ID_PROD`, `ID_USUA`, `CANTIDAD`, `TOTAL`, `FECHA`) VALUES
(1, 3, 1, 1, 1500, '2023-02-16 01:21:04'),
(2, 3, 1, 1, 1500, '2023-02-16 01:22:05'),
(3, 3, 1, 2, 3000, '2023-02-16 01:30:35'),
(4, 3, 1, 2, 3000, '2023-02-16 01:31:30'),
(5, 3, 1, 4, 6000, '2023-02-16 01:33:18');

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `producto`
--

CREATE TABLE `producto` (
  `ID_PRODUCTO` int(11) NOT NULL,
  `NOMBRE` varchar(100) NOT NULL,
  `PRECIO` float NOT NULL,
  `CANT_DIS` int(11) NOT NULL,
  `IMAGEN` varchar(150) NOT NULL,
  `ID_USU` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Volcado de datos para la tabla `producto`
--

INSERT INTO `producto` (`ID_PRODUCTO`, `NOMBRE`, `PRECIO`, `CANT_DIS`, `IMAGEN`, `ID_USU`) VALUES
(1, 'Audifonos X34', 2550, 3, 'imgBasedeDatos/63e68cbad3866.jpeg', 1),
(2, 'Impresora Canon', 8550, 3, 'imgBasedeDatos/63eae08d6f9c4.jpeg', 1),
(3, 'Teclado Bluethoth', 1500, 5, 'imgBasedeDatos/63ed88698232a.jpeg', 2),
(4, 'Tablet Hyundai', 7000, 5, 'imgBasedeDatos/63eadd74ac0ba.jpeg', 2),
(5, 'Mochila PowerBank', 11500, 4, 'imgBasedeDatos/63e6931f24d24.jpeg', 3),
(6, 'Protector Tablet', 1200, 11, 'imgBasedeDatos/63e693441fe09.jpeg', 3);

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `usuarios`
--

CREATE TABLE `usuarios` (
  `ID_USUARIO` int(11) NOT NULL,
  `NOMBRE` varchar(100) NOT NULL,
  `APELLIDO` varchar(100) NOT NULL,
  `CORREO` varchar(200) NOT NULL,
  `PASS` varchar(100) NOT NULL,
  `DIRECCION` varchar(100) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Volcado de datos para la tabla `usuarios`
--

INSERT INTO `usuarios` (`ID_USUARIO`, `NOMBRE`, `APELLIDO`, `CORREO`, `PASS`, `DIRECCION`) VALUES
(1, 'Eduardo', 'Bustos Moran', 'bmeo191668@upemor.edu.mx', 'lolipop123', 'Cuautla Mor.  Col. Benito Juarez, Calle Ramon Corona #21'),
(2, 'Christian', 'Hernandez Najera', 'a@a.com', '123', 'Lagunilla'),
(3, 'Lorena', 'Valle Gonzalez', 'b@b.com', '123', 'Barona'),
(4, 'Axl Armando', 'Castrejon Ocampo', 'c@c.com', '123', 'Cuernavaca'),
(6, 'Christian', 'Bustos', 'd@d.com', '123', 'Cuautla Morelos, Benito Juarez');

--
-- Índices para tablas volcadas
--

--
-- Indices de la tabla `compra`
--
ALTER TABLE `compra`
  ADD PRIMARY KEY (`ID_COMPRA`),
  ADD KEY `ID_PROD` (`ID_PROD`),
  ADD KEY `ID_USUA` (`ID_USUA`);

--
-- Indices de la tabla `producto`
--
ALTER TABLE `producto`
  ADD PRIMARY KEY (`ID_PRODUCTO`);

--
-- Indices de la tabla `usuarios`
--
ALTER TABLE `usuarios`
  ADD PRIMARY KEY (`ID_USUARIO`);

--
-- AUTO_INCREMENT de las tablas volcadas
--

--
-- AUTO_INCREMENT de la tabla `compra`
--
ALTER TABLE `compra`
  MODIFY `ID_COMPRA` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=6;

--
-- AUTO_INCREMENT de la tabla `producto`
--
ALTER TABLE `producto`
  MODIFY `ID_PRODUCTO` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=12;

--
-- AUTO_INCREMENT de la tabla `usuarios`
--
ALTER TABLE `usuarios`
  MODIFY `ID_USUARIO` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=7;

--
-- Restricciones para tablas volcadas
--

--
-- Filtros para la tabla `compra`
--
ALTER TABLE `compra`
  ADD CONSTRAINT `compra_ibfk_1` FOREIGN KEY (`ID_PROD`) REFERENCES `producto` (`ID_PRODUCTO`),
  ADD CONSTRAINT `compra_ibfk_2` FOREIGN KEY (`ID_USUA`) REFERENCES `usuarios` (`ID_USUARIO`);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
