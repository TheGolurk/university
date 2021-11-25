package functions

import "github.com/labstack/echo/v4"

func PassAsistence(c echo.Context) error {
	return nil
}

func MiddlewareValidator(name, plate string, c echo.Context) (bool, error) {
	cookie, err := c.Cookie("matricula")
	if err != nil {
		return false, err
	}

	if existPlate(cookie.Value) {
		return true, nil
	}

	return false, nil
}

func existPlate(plate string) (exist bool) {

	return
}
