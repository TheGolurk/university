import math
import random as rnd
import random
import math as mt
import numpy as np
import collections as cll


def generarPoblacion():
    poblacion = np.zeros((8, 6))
    for i in range(8):
        for j in range(6):
            x = -5 + rnd.random() * 10
            poblacion[i][j] = x
    return poblacion


def seleccion_por_torneo(poblacion, fitness, maximizar):
    # Crear una matriz vacía para la nueva población
    nueva_poblacion = np.empty_like(poblacion)
    # Seleccionar dos individuos aleatorios y elegir el mejor
    for i in range(poblacion.shape[0]):
        ind1, ind2 = np.random.choice(poblacion.shape[0], 2, replace=False)
        if maximizar:
            if fitness[ind1] > fitness[ind2]:
                nueva_poblacion[i, :] = poblacion[ind1, :]
            else:
                nueva_poblacion[i, :] = poblacion[ind2, :]
        else:
            if fitness[ind1] < fitness[ind2]:
                nueva_poblacion[i, :] = poblacion[ind1, :]
            else:
                nueva_poblacion[i, :] = poblacion[ind2, :]
    return nueva_poblacion


def f_fitness(v):
    f = 0
    longitud_max = len(v) - 1
    for i in range(longitud_max):
        f += 1 / 2 * (math.pow(i, 4) - 16 * math.pow(i, 2) + 5 * i) + (
                    math.pow(i + 1, 4) - 16 * math.pow(i + 1, 2) + 5 * i + 2)
    return f


def elitismo(poblacion, fitness, maximizar):
    # Ordenar los fitness
    fitness_ordenado = sorted(poblacion, key=f_fitness, reverse=maximizar)
    # Seleccionar los mejores cinco individuos
    mejores_cinco = fitness_ordenado[:5]
    # Completar la población de 8 con tres individuos aleatorios de los cinco seleccionados
    poblacion_elitista = mejores_cinco
    for i in range(3):
        poblacion_elitista = np.vstack((poblacion_elitista, mejores_cinco[rnd.randint(0, 4):]))
    return poblacion_elitista


def cruza_puntos(poblacion):
    x, x1 = 0, 0
    ptoCruza = 0.8
    pobcruza = []

    for i in range(4):
        padre1 = random.randint(0, 7)
        padre2 = random.randint(0, 7)
        padre3 = random.randint(0, 7)

        # Aleatorio punto de cruza
        y = rnd.random()
        # Punto inicial
        x = random.randint(1, 3)
        # Punto final, debe ser mayor al punto inicial
        x1 = -1
        while x1 <= x:
            x1 = random.randint(0, 7)

        if y < ptoCruza:
            # una vez teniendo los dos puntos realizamos la cruza
            hijo_real_1 = np.concatenate((np.array(poblacion[padre1][0:x]), np.array(poblacion[padre2][x:x1]),
                                          np.array(poblacion[padre1][x1:6])))
            hijo_real_2 = np.concatenate((np.array(poblacion[padre1][0:x]), np.array(poblacion[padre3][x:x1]),
                                          np.array(poblacion[padre1][x1:6])))
            pobcruza.append(hijo_real_1)
            pobcruza.append(hijo_real_2)
        else:
            pobcruza.append(poblacion[padre1])
            pobcruza.append(poblacion[padre2])
    return pobcruza


def muta_aleatorio(poblacion):
    pobMuta = []
    ptomuta = 0.2
    puntomuta = rnd.randint(0, 5)
    for i in range(8):
        x = rnd.random()
        if (x < ptomuta):
            d = cll.deque(poblacion[i])
            d.rotate(3)
            pobMuta.append(d)
        else:
            pobMuta.append(poblacion[i])
    return pobMuta


def obtener_fitness(poblacion):
    fitness = []
    for i in range(8):  # el recorrido de los individuos
        f = 0
        for j in range(6):  # recorrido de genes
            f = 1 / 2 * (mt.pow(poblacion[i][j], 4) - 16 * (mt.pow(poblacion[i][j], 2)) + 5 * (poblacion[i][j]))
            fitness.append(f)

    return fitness


def probFitness(poblacion):
    fitness = []
    for i in range(8):  # el recorrido de los individuos
        f = 0
        for j in range(6):  # recorrido de genes
            f = 1 / 2 * (mt.pow(poblacion[i][j], 4) - 16 * (mt.pow(poblacion[i][j], 2)) + 5 * (poblacion[i][j]))
            fitness.append(f)

    return sum(fitness) / len(fitness)


if __name__ == '__main__':
    generaciones = 200
    fitlim = 0.5
    n_gen = 1
    probfitness = 0

    while generaciones < n_gen or probfitness < fitlim:
        poblacion = generarPoblacion()
        probfitness = probFitness(poblacion)
        fitness = obtener_fitness(poblacion)

        if rnd.random() > 0.45:
            poblacion = seleccion_por_torneo(poblacion, fitness, True)
        else:
            poblacion = elitismo(poblacion, fitness, True)

        poblacion = cruza_puntos(poblacion)
        poblacion = muta_aleatorio(poblacion)

        print("generacion n=", n_gen)
        print("fitness f=", fitness)
        n_gen += 1
