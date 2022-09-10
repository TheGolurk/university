package main

import (
	"database/sql"
	"fmt"
	"log"
	"net/http"

	"github.com/labstack/echo/v4"

	_ "github.com/go-sql-driver/mysql"
)

const (
	username = "root"
	password = "root"
	hostname = "172.23.23.116:3306"
	dbname   = "EIDB"
)

func dsn() string {
	return fmt.Sprintf("%s:%s@tcp(%s)/%s", username, password, hostname, dbname)
}

type M struct {
	Message string `json:"message"`
}
type Produ struct {
	Nombre    string
	Precio    float64
	Descuento float64
}

type Emple struct {
	Nombre    string
	Apellido  string
	Direccion string
}

type Produ2 struct {
	Nombre   string
	Marca    string
	Cantidad int
}
type Prove struct {
	Nombre string
	Estado string
	Muni   string
}

type Sucu struct {
	Nombre string
	Estado string
}

type Cate struct {
	Nombre   string
	CAntidad int
}

type Clie struct {
	Nombre string
	APe    string
}

func main() {
	db, err := sql.Open("mysql", dsn())
	if err != nil {
		log.Fatal(err)
	}

	e := echo.New()

	e.GET("/compra", func(c echo.Context) error {
		rows, err := db.Query("SELECT NOMBRE_PRODUCTO, PRECIO, DESCUENTO FROM COMPRA;\n")
		if err != nil {
			return c.JSON(http.StatusInternalServerError, M{Message: "error de servidor"})
		}

		produs := []Produ{}
		defer rows.Close()
		for rows.Next() {
			prod := Produ{}
			if err = rows.Scan(&prod.Nombre, &prod.Precio, &prod.Descuento); err == nil {
				produs = append(produs, prod)
			}

		}

		return c.JSON(http.StatusOK, produs)
	})

	e.GET("/empleado", func(c echo.Context) error {
		rows, err := db.Query("SELECT NOMBRE, APELLIDO, DIRECCION FROM EMPLEADO;\n")
		if err != nil {
			return c.JSON(http.StatusInternalServerError, M{Message: "error de servidor"})
		}

		produs := []Emple{}
		defer rows.Close()
		for rows.Next() {
			prod := Emple{}
			if err = rows.Scan(&prod.Nombre, &prod.Apellido, &prod.Direccion); err == nil {
				produs = append(produs, prod)
			}

		}

		return c.JSON(http.StatusOK, produs)
	})

	e.GET("/producto", func(c echo.Context) error {
		rows, err := db.Query("SELECT NOMBRE, MARCA, CANTIDAD FROM PRODUCTO;\n")
		if err != nil {
			return c.JSON(http.StatusInternalServerError, M{Message: "error de servidor"})
		}

		produs := []Produ2{}
		defer rows.Close()
		for rows.Next() {
			prod := Produ2{}
			if err = rows.Scan(&prod.Nombre, &prod.Marca, &prod.Cantidad); err == nil {
				produs = append(produs, prod)
			}

		}

		return c.JSON(http.StatusOK, produs)
	})
	e.GET("/proveedor", func(c echo.Context) error {
		rows, err := db.Query("SELECT NOMBRE, ESTADO, MUNICIPIO FROM PROVEEDOR;\n")
		if err != nil {
			return c.JSON(http.StatusInternalServerError, M{Message: "error de servidor"})
		}

		produs := []Prove{}
		defer rows.Close()
		for rows.Next() {
			prod := Prove{}
			if err = rows.Scan(&prod.Nombre, &prod.Estado, &prod.Muni); err == nil {
				produs = append(produs, prod)
			}

		}

		return c.JSON(http.StatusOK, produs)
	})
	e.GET("/sucursal", func(c echo.Context) error {
		rows, err := db.Query("SELECT NOMBRE, ESTADO FROM SUCURSAL;\n")
		if err != nil {
			return c.JSON(http.StatusInternalServerError, M{Message: "error de servidor"})
		}

		produs := []Sucu{}
		defer rows.Close()
		for rows.Next() {
			prod := Sucu{}
			if err = rows.Scan(&prod.Nombre, &prod.Estado); err == nil {
				produs = append(produs, prod)
			}

		}

		return c.JSON(http.StatusOK, produs)
	})
	e.GET("/categoria", func(c echo.Context) error {
		rows, err := db.Query("SELECT NOMBRE, CANTIDAD FROM CATEGORIA;\n")
		if err != nil {
			return c.JSON(http.StatusInternalServerError, M{Message: "error de servidor"})
		}

		produs := []Cate{}
		defer rows.Close()
		for rows.Next() {
			prod := Cate{}
			if err = rows.Scan(&prod.Nombre, &prod.CAntidad); err == nil {
				produs = append(produs, prod)
			}

		}

		return c.JSON(http.StatusOK, produs)
	})
	e.GET("/cliente", func(c echo.Context) error {
		rows, err := db.Query("SELECT NOMBRE, APELLIDO FROM CLIENTE;\n")
		if err != nil {
			return c.JSON(http.StatusInternalServerError, M{Message: "error de servidor"})
		}

		produs := []Clie{}
		defer rows.Close()
		for rows.Next() {
			prod := Clie{}
			if err = rows.Scan(&prod.Nombre, &prod.APe); err == nil {
				produs = append(produs, prod)
			}

		}

		return c.JSON(http.StatusOK, produs)
	})

	e.Logger.Fatal(e.Start(":8080"))
}
