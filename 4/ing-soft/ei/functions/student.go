package functions

import (
	"database/sql"
	"github.com/labstack/echo/v4"
	"github.com/labstack/gommon/log"
	"net/http"
	"time"
)

type Student struct {
	DB *sql.DB
}

type StudentsFunctions interface {
	Login(c echo.Context) error
	PassAssistance(c echo.Context) error
	ValidateStudent(next echo.HandlerFunc) echo.HandlerFunc
	GetStudentsAssistance(c echo.Context) error
}

func (s Student) Login(c echo.Context) error {
	plate := c.Param("plate")
	if plate == "" {
		return c.String(http.StatusBadRequest, "Missing plate")
	}

	cookie := new(http.Cookie)
	cookie.Name = "matricula"
	cookie.Value = plate
	cookie.Expires = time.Now().Add(24 * time.Hour)
	c.SetCookie(cookie)
	return c.String(http.StatusOK, "Ok")
}

func (s Student) PassAssistance(c echo.Context) error {
	return nil
}

func (s Student) ValidateStudent(next echo.HandlerFunc) echo.HandlerFunc {
	return func(c echo.Context) error {
		cookie, err := c.Cookie("matricula")
		if err != nil {
			return err
		}

		log.Info("Trying pass assistance with ", cookie.Value)
		if !existPlate(cookie.Value) {
			return c.String(http.StatusInternalServerError, "Plate doesn't exist")
		}

		return next(c)
	}
}

func (s Student) GetStudentsAssistance(c echo.Context) error {
	return c.String(http.StatusOK, "")
}

func existPlate(plate string) (exist bool) {
	exist = true
	return
}
