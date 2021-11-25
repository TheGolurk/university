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

	s := http.Server{
		Addr:    ":3000",
		Handler: e,
	}

	student := functions.Student{
		DB: database.GetDB(),
	}
	e.POST("student/assistance/:plate", student.PassAssistance, student.ValidateStudent)
	e.POST("student/:plate", student.Login)
	e.GET("students/assistance", student.GetStudentsAssistance)

	if err := s.ListenAndServe(); !errors.Is(err, http.ErrServerClosed) {
		log.Fatal(err)
	}
}
