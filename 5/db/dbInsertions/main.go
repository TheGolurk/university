package main

import (
	"flag"
	"log"

	"github.com/thegolurk/dbInsertions/database"
)

func main() {
	var count int

	flag.IntVar(&count, "count", 0, "")
	flag.Parse()

	db, err := database.GetConnection()
	if err != nil {
		log.Fatal("Cannot open the database")
	}

	database.FillEquipo(db, count)
	database.FillDeporte(db, count)
	database.FillEvento(db, count)
	database.FillPatrocinador(db, count)

	database.FillE2(db, count)
	database.FillA(db, count)
	database.FillE3(db, count)
	database.FillRes(db, count)

}
