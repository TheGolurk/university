package config

type Confing struct {
	DB
}

type DB struct {
	HOST     string `env:"HOST"`
	PORT     int    `env:"PORT"`
	USER     string `env:"USER"`
	PASSWORD string `env:"PASSWORD"`
	DB       string `env:"DB"`
}
