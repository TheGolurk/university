import math
import numpy as np
import random as rnd


def primera_poblacion():
    poblacion = np.zeros((10, 8))
    for i in range(10):
        for j in range(8):
            primera_posicion = -10 + rnd.random() * 20
            poblacion[i][j] = primera_posicion
    return poblacion


def fitness(poblacion):
    fitness_list = []
    for ind in poblacion:
        f = sum((math.sin(x1 ** 2 - x2 ** 2) ** 2 - 0.5) / (1 + 0.001 * (x1 ** 2 + x2 ** 2)) ** 2
                for x1, x2 in zip(ind[:-1], ind[1:]))
        fitness_list.append(f)
    return fitness_list


def probSeleccion(fitness):
    total_fitness = sum(fitness)
    prob_seleccion = [(total_fitness - f) / total_fitness for f in fitness]
    suma_total_probabilidades = sum(prob_seleccion)
    print(suma_total_probabilidades)
    return prob_seleccion


def selectRuleta(poblacion_seleccionada, pob):
    return pob


def cruzar_poblacion(pob):
    pob_cruz = []
    for i in range(5):
        pos1, pos2 = rnd.choice(range(10))
        if rnd.random() < 0.7:
            primer_punto = rnd.randint(0,3)
            segundo_punto = rnd.randint(4,5)
            pob_cruz.append(np.concatenate((pob[pos1][:primer_punto], pob[pos2][primer_punto:segundo_punto], pob[pos1][segundo_punto:])))
            pob_cruz.append(np.concatenate((pob[pos2][:primer_punto], pob[pos1][primer_punto:segundo_punto], pob[pos2][segundo_punto:])))
        else:
            pob_cruz.append(pob[pos1])
            pob_cruz.append(pob[pos2])
    return pob_cruz


def mutar_pob(pob):
    return pob


if __name__ == '__main__':
    pob = primera_poblacion()
    i = 0
    for i in range(200):
        fitness_poblacion = fitness(pob)
        poblacion_seleccionada = probSeleccion(fitness_poblacion)
        pob = selectRuleta(poblacion_seleccionada, pob)
        pob = cruzar_poblacion(pob)
        print("cruzar", pob)
        pob = mutar_pob(pob)
        print("mutar", pob)
