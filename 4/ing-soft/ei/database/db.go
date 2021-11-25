package database

import (
	"database/sql"
	"fmt"
	"github.com/caarlos0/env/v6"
	"upemor.com/asistence/config"
)

func GetDB() *sql.DB {
	cfg := config.Confing{}
	if err := env.Parse(&cfg); err != nil {
		return nil
	}

	conn := fmt.Sprintf("host=%s port=%d dbname=%s user=%s password='%s' sslmode=require",
		cfg.HOST, cfg.PORT, cfg.DB, cfg.USER, cfg.PASSWORD)

	db, err := sql.Open("postgres", conn)
	if err != nil {
		return nil
	}
	if err = db.Ping(); err != nil {
		return nil
	}

	return db
}
