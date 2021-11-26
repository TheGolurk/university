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
	Add(c echo.Context) error
	GetStudents(c echo.Context) error
	GetCurrent(c echo.Context) error
}

func (s Student) Login(c echo.Context) error {
	plate := c.Param("plate")
	if plate == "" {
		return c.String(http.StatusBadRequest, "Missing plate")
	}

	if !s.existPlate(plate) {
		return c.NoContent(http.StatusNotFound)
	}

	cookie := new(http.Cookie)
	cookie.Name = "matricula"
	cookie.Value = plate
	cookie.Expires = time.Now().Add(24 * time.Hour)
	c.SetCookie(cookie)
	return c.JSON(http.StatusOK, plate)
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
		return c.String(http.StatusInternalServerError, "not inserted")
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

func (s Student) Add(c echo.Context) error {
	student := models.Student{}

	err := c.Bind(&student)
	if err != nil {
		return c.String(http.StatusBadRequest, "no student provided")
	}

	ctx := context.Background()
	tx, err := s.DB.BeginTx(ctx, &sql.TxOptions{Isolation: sql.LevelSerializable})
	if err != nil {
		return c.String(http.StatusInternalServerError, "an error occurred")
	}

	res, err := tx.ExecContext(ctx, `INSERT INTO ALUMNO (Nombre, Matricula, Carrera, Edad) 
										VALUES ($1, $2, $3, $4)`,
										student.Nombre, student.Matricula, student.Carrera, student.Edad)
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
		return c.String(http.StatusInternalServerError, "not inserted")
	}

	if err := tx.Commit(); err != nil {
		log.Fatal(err)
		return c.String(http.StatusInternalServerError, "an error occurred when commit")
	}

	return c.String(http.StatusOK, "added student")
}

func (s *Student) GetCurrent(c echo.Context) error {
	student := models.Student{}

	cookie, err := c.Cookie("matricula")
	if err != nil {
		return c.String(http.StatusBadRequest, fmt.Sprintf("%v", err))
	}

	plate := cookie.Value
	err = s.DB.QueryRow(`SELECT * FROM ALUMNO WHERE Matricula = $1 LIMIT 1`, plate).
		Scan(&student.ID, &student.Nombre, &student.Matricula, &student.Carrera, &student.Edad)

	if errors.Is(sql.ErrNoRows, err) {
		return c.NoContent(http.StatusNotFound)
	}

	fmt.Println(student)
	return c.JSON(http.StatusOK, student)
}

func (s Student) GetStudents(c echo.Context) error {
	students := make([]models.Student,0)
	student := models.Student{}

	rows, err := s.DB.Query(`SELECT * FROM ALUMNO`)

	if err != nil {
		return c.String(http.StatusInternalServerError, fmt.Sprintf("an error occurred %v", err))
	}

	for rows.Next() {
		if err = rows.Scan(&student.ID, &student.Nombre, &student.Matricula, &student.Carrera, &student.Edad); err != nil {
			return c.String(http.StatusInternalServerError, fmt.Sprintf("scanner error %v", err))
		}

		students = append(students, student)
	}

	return c.JSON(http.StatusOK, students)
}

func (s Student) GetStudentsAssistance(c echo.Context) error {
	students := make([]models.StudentsAssistance,0)
	student := models.StudentsAssistance{}

	rows, err := s.DB.Query(`SELECT Nombre, Carrera, AA.Matricula, 
       Fecha FROM ALUMNO JOIN ASISTENCIA_ALUMNO AA on ALUMNO.Matricula = AA.Matricula`)

	if err != nil {
		return c.String(http.StatusInternalServerError, fmt.Sprintf("an error occurred %v", err))
	}

	for rows.Next() {
		if err = rows.Scan(&student.Nombre, &student.Carrera, &student.Matricula, &student.Fecha); err != nil {
			return c.String(http.StatusInternalServerError, fmt.Sprintf("scanner error %v", err))
		}

		students = append(students, student)
	}

	return c.JSON(http.StatusOK, students)
}

func (s Student) existPlate(plate string) (exist bool) {
	student := models.Student{}
	err := s.DB.QueryRow(`SELECT Nombre FROM ALUMNO WHERE Matricula = $1 LIMIT 1`, plate).Scan(&student.Nombre)

	return !errors.Is(sql.ErrNoRows, err)
}
