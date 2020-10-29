package main

import (
	"fmt"
	"log"
	"net/http"
)

func main() {
	fmt.Println("vim-go")

	log.Fatal(http.ListenAndServe(":3000", nil))
}
