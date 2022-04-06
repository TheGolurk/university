package database

import (
	"database/sql"
	"fmt"
	"log"
	"math/rand"
	"time"

	"github.com/bxcodec/faker/v3"
)

func FillEquipo(db *sql.DB, count int) {
	a, err := db.Begin()
	if err != nil {
		log.Fatal("Cannot begin the database, err", err)
	}

	defer func() {
		if err != nil {
			a.Rollback()
			return
		}

		err = a.Commit()
	}()

	rand.Seed(time.Now().UnixNano())
	query := BuildQueryV1(INSERT_EQUIPO, count)

	res, err := a.Exec(query)
	if err != nil {
		log.Panic("Error in query exec")
	}

	rows, _ := res.RowsAffected()
	if rows < 1 {
		log.Panic("Not rows affected")
	}

	log.Println("AGREGADO")
}

func FillPatrocinador(db *sql.DB, count int) {
	a, err := db.Begin()
	if err != nil {
		log.Fatal("Cannot begin the database, err", err)
	}

	defer func() {
		if err != nil {
			a.Rollback()
			return
		}

		err = a.Commit()
	}()

	rand.Seed(time.Now().UnixNano())
	query := BuildQueryV2(INSERT_PATROCINADOR, count)

	res, err := a.Exec(query)
	if err != nil {
		log.Panic("Error in query exec")
	}

	rows, _ := res.RowsAffected()
	if rows < 1 {
		log.Panic("Not rows affected")
	}

	log.Println("AGREGADO")
}

func FillEvento(db *sql.DB, count int) {
	a, err := db.Begin()
	if err != nil {
		log.Fatal("Cannot begin the database, err", err)
	}

	defer func() {
		if err != nil {
			a.Rollback()
			return
		}

		err = a.Commit()
	}()

	query := BuildQueryV3(INSERT_EVENTO, count)

	res, err := a.Exec(query)
	if err != nil {
		log.Panic("Error in query exec")
	}

	rows, _ := res.RowsAffected()
	if rows < 1 {
		log.Panic("Not rows affected")
	}

	log.Println("AGREGADO")
}

func FillDeporte(db *sql.DB, count int) {
	a, err := db.Begin()
	if err != nil {
		log.Fatal("Cannot begin the database, err", err)
	}

	defer func() {
		if err != nil {
			a.Rollback()
			return
		}

		err = a.Commit()
	}()

	rand.Seed(time.Now().UnixNano())
	query := BuildQueryV4(INSERT_DEPORTE, count)

	res, err := a.Exec(query)
	if err != nil {
		log.Panic("Error in query exec")
	}

	rows, _ := res.RowsAffected()
	if rows < 1 {
		log.Panic("Not rows affected")
	}

	log.Println("AGREGADO")
}

func FillE2(db *sql.DB, count int) {
	a, err := db.Begin()
	if err != nil {
		log.Fatal("Cannot begin the database, err", err)
	}

	defer func() {
		if err != nil {
			a.Rollback()
			return
		}

		err = a.Commit()
	}()

	rand.Seed(time.Now().UnixNano())
	query := BuildQueryV5(INSERT_E2, count)

	res, err := a.Exec(query)
	if err != nil {
		log.Panic("Error in query exec")
	}

	rows, _ := res.RowsAffected()
	if rows < 1 {
		log.Panic("Not rows affected")
	}

	log.Println("AGREGADO")
}

func FillA(db *sql.DB, count int) {
	a, err := db.Begin()
	if err != nil {
		log.Fatal("Cannot begin the database, err", err)
	}

	defer func() {
		if err != nil {
			a.Rollback()
			return
		}

		err = a.Commit()
	}()

	rand.Seed(time.Now().UnixNano())
	query := BuildQueryV6(INSERT_ATLETA, count)

	res, err := a.Exec(query)
	if err != nil {
		log.Panic("Error in query exec")
	}

	rows, _ := res.RowsAffected()
	if rows < 1 {
		log.Panic("Not rows affected")
	}

	log.Println("AGREGADO")
}

func FillE3(db *sql.DB, count int) {
	a, err := db.Begin()
	if err != nil {
		log.Fatal("Cannot begin the database, err", err)
	}

	defer func() {
		if err != nil {
			a.Rollback()
			return
		}

		err = a.Commit()
	}()

	rand.Seed(time.Now().UnixNano())
	query := BuildQueryV7(INSERT_E3, count)

	res, err := a.Exec(query)
	if err != nil {
		log.Panic("Error in query exec")
	}

	rows, _ := res.RowsAffected()
	if rows < 1 {
		log.Panic("Not rows affected")
	}

	log.Println("AGREGADO")
}

func FillRes(db *sql.DB, count int) {
	a, err := db.Begin()
	if err != nil {
		log.Fatal("Cannot begin the database, err", err)
	}

	defer func() {
		if err != nil {
			a.Rollback()
			return
		}

		err = a.Commit()
	}()

	rand.Seed(time.Now().UnixNano())
	query := BuildQueryV8(INSERT_RES, count)

	res, err := a.Exec(query)
	if err != nil {
		log.Panic("Error in query exec")
	}

	rows, _ := res.RowsAffected()
	if rows < 1 {
		log.Panic("Not rows affected")
	}

	log.Println("AGREGADO")
}

func BuildQueryV1(statement string, count int) string {
	for i := 0; i <= count; i++ {
		values := fmt.Sprintf(` ('%v', %v ,'%v')`, faker.Word(), rand.Int(), faker.Name())
		if i < count {
			values += ","
		} else {
			values += ";"
		}

		statement += values
	}

	return statement
}

func BuildQueryV2(statement string, count int) string {
	patrocinador_tam := []string{
		"chico",
		"mediano",
		"grande",
		"completo",
	}

	for i := 0; i <= count; i++ {

		values := fmt.Sprintf(`('%v', '%v' ,'%v')`, faker.Word(), faker.Word(), patrocinador_tam[rand.Intn(3-0)+0])
		if i < count {
			values += ","
		} else {
			values += ";"
		}

		statement += values
	}

	return statement
}

func BuildQueryV3(statement string, count int) string {
	for i := 0; i <= count; i++ {

		values := fmt.Sprintf(` ('%v', '%v' ,'%v')`, faker.Word(), faker.Date(), faker.Word())
		if i < count {
			values += ","
		} else {
			values += ";"
		}

		statement += values
	}

	return statement
}

func BuildQueryV4(statement string, count int) string {
	deportes := []string{
		"futbol",
		"voleybol",
		"natacion",
		"gimnasia",
		"automovilismo",
		"basquetbol",
		"americano",
		"baseball",
	}

	for i := 0; i <= count; i++ {

		values := fmt.Sprintf(` ('%v', '%v' ,'%v')`, deportes[rand.Intn(8-0)+0], "aire libre", "terrestre")
		if i < count {
			values += ","
		} else {
			values += ";"
		}

		statement += values
	}

	return statement
}

func BuildQueryV5(statement string, count int) string {

	for i := 0; i <= count; i++ {

		values := fmt.Sprintf(` (%v, %v, '%v', %v)`, rand.Intn(50-1)+1, rand.Intn(50-1)+1, faker.Date(), rand.Intn(10000-0)+0)
		if i < count {
			values += ","
		} else {
			values += ";"
		}

		statement += values
	}

	return statement
}

func BuildQueryV6(statement string, count int) string {
	for i := 0; i <= count; i++ {
		values := fmt.Sprintf(` ('%v', %v, %v, %v)`, faker.Name(), rand.Intn(50-1)+1, rand.Intn(10000-0)+0, rand.Intn(50-1)+1)
		if i < count {
			values += ","
		} else {
			values += ";"
		}

		statement += values
	}

	return statement
}

func BuildQueryV7(statement string, count int) string {
	for i := 0; i <= count; i++ {

		values := fmt.Sprintf(` (%v, %v, '%v', '%v')`, rand.Intn(50-1)+1, rand.Intn(50-1)+1, faker.Date(), faker.Word())
		if i < count {
			values += ","
		} else {
			values += ";"
		}

		statement += values
	}

	return statement
}

func BuildQueryV8(statement string, count int) string {
	for i := 0; i <= count; i++ {
		values := fmt.Sprintf(` (%v, '%v', '%v', %v, %v)`, rand.Intn(100-0)+0, rand.Intn(50-1)+1, faker.Date(), rand.Intn(50-1)+1, rand.Intn(50-1)+1)
		if i < count {
			values += ","
		} else {
			values += ";"
		}

		statement += values
	}

	return statement
}
