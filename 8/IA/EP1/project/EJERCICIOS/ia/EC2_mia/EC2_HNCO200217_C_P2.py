import math
import random
import numpy as np


def generarPoblacion():
    poblacion = np.zeros((8, 6))
    for i in range(8):
        for j in range(6):
            primera_posicion = -5 + random.random() * 10
            poblacion[i][j] = primera_posicion
    return poblacion


def seleccion_torneo(poblacion, fitness):
    nueva_poblacion = []
    for i in range(len(poblacion)):
        pos1, pos2 = random.sample(range(len(poblacion)), 2)
        if fitness[pos1] > fitness[pos2]:
            nueva_poblacion.append(poblacion[pos1])
        else:
            nueva_poblacion.append(poblacion[pos2])
    return np.array(nueva_poblacion)


def fitness_independiente(v):
    f = 0
    longitud_max = len(v) - 1
    for i in range(longitud_max):
        f += 1 / 2 * (math.pow(i, 4) - 16 * math.pow(i, 2) + 5 * i) + (
                math.pow(i + 1, 4) - 16 * math.pow(i + 1, 2) + 5 * i + 2)
    return f


def seleccion_elitista(poblacion):
    poblacion_ordenada = sorted(poblacion, key=fitness_independiente)
    mejores_cinco = poblacion_ordenada[:5]
    poblacion_elitista = mejores_cinco.copy()
    for i in range(3):
        individuos_elegidos = random.sample(mejores_cinco, k=2)
        hijo_elitista = max(individuos_elegidos, key=fitness_independiente)
        poblacion_elitista.append(hijo_elitista)
    return poblacion_elitista


def cruza_puntos(poblacion):
    poblacion_nueva_cruzada = []

    for i in range(4):
        padre1 = random.randint(0, 7)
        padre2 = random.randint(0, 7)
        padre3 = random.randint(0, 7)

        primera_posicion = random.randint(1, 3)
        # - 2 para que sea menor y siempre intente buscar uno mayor a la primera posicion
        segunda_posicion = -2
        while segunda_posicion <= primera_posicion:
            segunda_posicion = random.randint(0, 7)

        if random.random() < 0.8:
            hijo = np.concatenate((np.array(poblacion[padre1][0:primera_posicion]), np.array(
                poblacion[padre2][primera_posicion:segunda_posicion]),
                                                           np.array(poblacion[padre1][segunda_posicion:6])))
            poblacion_nueva_cruzada.append(hijo)
            hijo = np.concatenate((np.array(poblacion[padre1][0:primera_posicion]), np.array(
                poblacion[padre3][primera_posicion:segunda_posicion]),
                                                           np.array(poblacion[padre1][segunda_posicion:6])))
            poblacion_nueva_cruzada.append(hijo)
        else:
            # Duda mandada por gmail, se deben mandar los 3 padres?
            poblacion_nueva_cruzada.append(poblacion[padre1])
            poblacion_nueva_cruzada.append(poblacion[padre2])

    return poblacion_nueva_cruzada


def muta_aleatorio(poblacion):
    return poblacion


def obtner_fitness_arr_prob(poblacion):
    fitness = []
    for i in range(8):
        for j in range(6):
            fitness.append(
                1 / 2 * (math.pow(poblacion[i][j], 4) - 16 * (math.pow(poblacion[i][j], 2)) + 5 * (poblacion[i][j]))
            )

    return sum(fitness) / len(fitness), fitness


if __name__ == '__main__':
    fitness_limite = 0.5
    fitness_general = 0

    for i in range(200):
        if fitness_general > fitness_limite:
            break

        poblacion = generarPoblacion()
        fitness_general, fitness = obtner_fitness_arr_prob(poblacion)

        if random.random() > 0.45:
            poblacion = seleccion_torneo(poblacion, fitness)
        else:
            poblacion = seleccion_elitista(poblacion)

        poblacion = cruza_puntos(poblacion)
        poblacion = muta_aleatorio(poblacion)

        print("fitness y numero de generacion", fitness_general, i)
        print(poblacion)
