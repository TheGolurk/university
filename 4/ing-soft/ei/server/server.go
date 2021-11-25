package server

import (
	"errors"
	"github.com/labstack/echo/v4/middleware"
	"log"
	"net/http"
	"upemor.com/asistence/database"

	"github.com/labstack/echo/v4"
	"upemor.com/asistence/functions"
)

func StartServer() {
	e := echo.New()

	e.Use(middleware.Logger())
	e.Use(middleware.Recover())

	e.Use(middleware.CORSWithConfig(middleware.CORSConfig{
		AllowOrigins: []string{"*"},
		AllowMethods: []string{http.MethodGet, http.MethodHead, http.MethodPut, http.MethodPatch, http.MethodPost, http.MethodDelete},
	}))

	s := http.Server{
		Addr:    ":3000",
		Handler: e,
	}

	DB := database.GetDB()
	if DB == nil {
		log.Fatal("Cannot start DB")
		return
	}

	student := functions.Student{
		DB: database.GetDB(),
		Plate: "",
	}
	e.POST("student/assistance/:plate", student.PassAssistance, student.ValidateStudent)
	e.POST("student/:plate", student.Login)
	e.POST("student/add", student.Add)
	e.GET("students/assistance", student.GetStudentsAssistance)
	e.GET("students", student.GetStudents)
	e.GET("student", student.GetCurrent)

	if err := s.ListenAndServe(); !errors.Is(err, http.ErrServerClosed) {
		log.Fatal(err)
	}
}
