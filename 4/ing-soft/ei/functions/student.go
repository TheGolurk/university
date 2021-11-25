package functions

import (
	"github.com/labstack/echo/v4"
	"github.com/labstack/gommon/log"
	"net/http"
	"time"
)

func LoginStudent(c echo.Context) error {
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

func PassAsistence(c echo.Context) error {
	return nil
}

func ValidateStudent(next echo.HandlerFunc) echo.HandlerFunc {
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

func GetStudentsAsistence(c echo.Context) error {
	return c.String(http.StatusOK, "")
}

func existPlate(plate string) (exist bool) {
	exist = true
	return
}
