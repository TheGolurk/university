package database

import (
	"database/sql"
	"fmt"
	"github.com/caarlos0/env/v6"
	_ "github.com/lib/pq"
	"upemor.com/asistence/config"
)

func GetDB() *sql.DB {
	cfg := config.Confing{}
	if err := env.Parse(&cfg); err != nil {
		return nil
	}

	conn := fmt.Sprintf("host=%s port=%d dbname=%s user=%s password='%s' sslmode=disable",
		cfg.HOST, cfg.PORT, cfg.DBNAME, cfg.USER, cfg.PASSWORD)

	db, err := sql.Open("postgres", conn)
	if err != nil {
		return nil
	}
	if err = db.Ping(); err != nil {
		return nil
	}

	return db
}
