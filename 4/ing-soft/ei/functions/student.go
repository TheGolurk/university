package functions

import (
	"context"
	"database/sql"
	"errors"
	"fmt"
	"github.com/labstack/echo/v4"
	"github.com/labstack/gommon/log"
	"net/http"
	"time"
	"upemor.com/asistence/models"
)

type Student struct {
	DB *sql.DB
	Plate string
}

type StudentsFunctions interface {
	Login(c echo.Context) error
	PassAssistance(c echo.Context) error
	ValidateStudent(next echo.HandlerFunc) echo.HandlerFunc
	GetStudentsAssistance(c echo.Context) error
	existPlate(plate string) (exist bool)
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

func (s *Student) PassAssistance(c echo.Context) error {
	if s.Plate == "" {
		return c.String(http.StatusBadRequest, "no plate provided")
	}

	currentTimestamp := time.Now().Format("2006-01-02")
	st := models.Student{}
	err := s.DB.QueryRow(`SELECT Matricula FROM ASISTENCIA_ALUMNO WHERE Fecha = $1 AND
                                              Matricula = $2 LIMIT 1`, currentTimestamp, s.Plate).Scan(&st.Matricula)

	if !errors.Is(sql.ErrNoRows, err) {
		return c.String(http.StatusOK, "assistance already taken")
	}

	ctx := context.Background()
	tx, err := s.DB.BeginTx(ctx, &sql.TxOptions{Isolation: sql.LevelSerializable})
	if err != nil {
		return c.String(http.StatusInternalServerError, "an error occurred")
	}

	res, err := tx.ExecContext(ctx, `INSERT INTO ASISTENCIA_ALUMNO (Fecha, Matricula) 
		VALUES (current_timestamp, $1)`, s.Plate)
	if err != nil {
		if rollbackErr := tx.Rollback(); rollbackErr != nil {
			log.Fatalf("insert failed: %v, unable to back: %v", err, rollbackErr)
		}
		return c.String(http.StatusInternalServerError, fmt.Sprintf("an error occurred %v", err))
	}

	rows, err := res.RowsAffected()
	if err != nil {
		return c.String(http.StatusInternalServerError, fmt.Sprintf("an error occurred %v", err))
	}
	if rows < 1 {
		return c.String(http.StatusInternalServerError, "not inserter")
	}

	if err := tx.Commit(); err != nil {
		log.Fatal(err)
		return c.String(http.StatusInternalServerError, "an error occurred when commit")
	}

	return c.String(http.StatusOK, "assistance taken")
}

func (s *Student) ValidateStudent(next echo.HandlerFunc) echo.HandlerFunc {
	return func(c echo.Context) error {
		cookie, err := c.Cookie("matricula")
		if err != nil {
			return err
		}

		log.Info("Trying pass assistance with ", cookie.Value)
		if !s.existPlate(cookie.Value) {
			return c.String(http.StatusInternalServerError, "Plate doesn't exist")
		}

		s.Plate =  cookie.Value
		return next(c)
	}
}

func (s Student) GetStudentsAssistance(c echo.Context) error {
	return c.String(http.StatusOK, "")
}

func (s Student) existPlate(plate string) (exist bool) {
	// https://pkg.go.dev/database/sql#example-Tx.Rollback

	student := models.Student{}
	err := s.DB.QueryRow(`SELECT Nombre FROM ALUMNO WHERE Matricula = $1 LIMIT 1`, plate).Scan(&student.Nombre)

	return !errors.Is(sql.ErrNoRows, err)
}
