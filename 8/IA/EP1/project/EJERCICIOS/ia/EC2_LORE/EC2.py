import math
import numpy as np
import random as rnd
import random


def fitness(x):
    fit = 0
    for i in range(len(x) - 1):
        fit += 1 / 2 * (math.pow(i, 4) - 16 * math.pow(i, 2) + 5 * i) + (math.pow(i + 1, 4) - 16 * math.pow(i + 1, 2) + 5 * i + 1)
    return fit

def generarpoblacion():
    poblacion = []
    for i in range(8):
        individuo = []
        for j in range(6):
            x = -5 + random.random() * 10
            individuo.append(x)
        poblacion.append(individuo)
    return poblacion


def fitness_poblacion(poblacion):
    fit_arr = []
    for i in poblacion:
        fit_arr.append(fitness(i))
    return sum(fit_arr) / len(fit_arr)


def seleccionar_poblacion_torneo(poblacion):
    torneo = rnd.sample(poblacion, 2)
    return poblacion


def seleccionar_poblacion_elitismo(poblacion):
    return sorted(poblacion, key=fitness)


def cruzar_poblacion(pob):
    cruzada = []
    # 4 * 2 = 8
    for _ in range(4):
        pos1 = rnd.randint(0, 7)
        pos2 = rnd.randint(0, 7)
        pos3 = rnd.randint(0, 7)
        if rnd.random() < 0.8:
            posicion_1 = rnd.randint(0, 5)
            posicion_2 = rnd.randint(0, 5)

            p1 = pob[pos1][0:posicion_1]
            p2 = pob[pos2][posicion_1:posicion_2]
            p3 = pob[pos1][posicion_2:8]
            # Se deben juntar los arreglos en uno solo
            nuevo = np.concatenate((p1, p2, p3))
            cruzada.append(nuevo)

            p1 = pob[pos1][0:posicion_1]
            p2 = pob[pos3][posicion_1:posicion_2]
            p3 = pob[pos1][posicion_2:8]
            nuevo = np.concatenate((p1, p2, p3))
            cruzada.append(nuevo)
        else:
            cruzada.append(pob[pos1])
            cruzada.append(pob[pos3])
    return cruzada


def mutar_poblacion(poblacion):
    for i in range(len(poblacion)):
        if rnd.random() < 0.2:
            posicion = rnd.randint(0, 5)
    return poblacion


if __name__ == '__main__':
    pob = generarpoblacion()
    print("Poblacion Inicial ", pob)
    i = 0
    for i in range(200):
        val_fit = fitness_poblacion(pob)
        if val_fit > 0.5:
            if rnd.random() < 0.45:
                seleccionar_poblacion_elitismo(pob)
            else:
                seleccionar_poblacion_torneo(pob)

            print("Poblacion Seleccionada", pob)
            pob = cruzar_poblacion(pob)
            print("Poblacion cruzar_poblacionda", pob)
            pob = mutar_poblacion(pob)
            print("Poblacion mutar_poblacionda", pob)
