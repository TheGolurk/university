"""
1: Generar población inicial
2: Calcular fitness
3: Ciclo reproductivo
3.1: Seleccion(seleccion por torneo)
3.2: Cruza
3.3: Muta
3.4: Evaluacion
"""
import numpy as np
import random as rnd
import math as mt

def generarPoblacion():
    poblacion = np.zeros((5,5))
    print(poblacion)
    for i in range(5):
        for j in range(5):
            x = -10+rnd.random()*20
            poblacion[i][j] = 1
    return poblacion

def fitness(poblacion):
    fitness = []
    for i in range(5):
        f = 0
        for j in range(4):
            f = f + 100 * (mt.pow(poblacion[i][j+1] - mt.pow(poblacion[i][j],2), 2)) + mt.pow(poblacion[i][j]-1, 2)
        fitness.append(f)
    return fitness

def seleccionTorneo():


if __name__ == "__main__":
    poblacion = generarPoblacion()
    fit = fitness(poblacion)
    seleccionTorneo(poblacion, fit)
