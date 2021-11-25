package server

import (
	"errors"
	"github.com/labstack/echo/v4/middleware"
	"log"
	"net/http"

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

	e.POST("student/assistance/:plate", functions.PassAsistence, functions.ValidateStudent)
	e.POST("student/:plate", functions.LoginStudent)
	e.GET("students/asistence", functions.GetStudentsAsistence)

	if err := s.ListenAndServe(); !errors.Is(err, http.ErrServerClosed) {
		log.Fatal(err)
	}
}
