#!/bin/bash

START_TIME=$(date +%s)

go run main.go es en prueba

END_TIME=$(date +%s)
echo "It took $(($END_TIME - $START_TIME)) Seconds to translate..."
