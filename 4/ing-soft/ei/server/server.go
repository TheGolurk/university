package server

import (
	"errors"
	"log"
	"net/http"

	"github.com/labstack/echo/v4"
	"github.com/labstack/echo/v4/middleware"
	"upemor.com/asistence/functions"
)

func StartServer() {
	e := echo.New()

	s := http.Server{
		Addr:    "3000",
		Handler: e,
	}

	e.Use(middleware.BasicAuthWithConfig(middleware.BasicAuthConfig{
		Validator: functions.MiddlewareValidator,
	}))

	e.POST("student/:plate", functions.PassAsistence)

	if err := s.ListenAndServe(); !errors.Is(err, http.ErrServerClosed) {
		log.Fatal(err)
	}
}
