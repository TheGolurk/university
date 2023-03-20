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


def torneo(poblacion, fitness):
    pobTorneo = []

    for i in range(8):
        ind1, ind2 = 0, 0
        while ind1 == ind2:
            ind1 = rnd.randint(0, 5) # 8
            ind2 = rnd.randint(0, 5) # 6
            # poblacion[ind1][ind2]
            # poblacion[ind1][ind2]
            # hacer lo demas

        if (fitness[ind1] < fitness[ind2]):
            pobTorneo.append(poblacion[ind1])
        else:
            pobTorneo.append(poblacion[ind2])
    return pobTorneo


def elitismo(poblacion, fitness, maximizar):
    # Ordenar los fitness
    fitness_ordenado = sorted(fitness, reverse=maximizar)
    # Seleccionar los mejores cinco individuos
    mejores_cinco = poblacion[fitness.index(fitness_ordenado[0]), :]
    for i in range(1, 5):
        mejores_cinco = np.vstack((mejores_cinco, poblacion[fitness.index(fitness_ordenado[i]), :]))
    # Completar la población de 8 con tres individuos aleatorios de los cinco seleccionados
    poblacion_elitista = mejores_cinco
    for i in range(3):
        poblacion_elitista = np.vstack((poblacion_elitista, mejores_cinco[rnd.randint(0, 4), :]))
    return poblacion_elitista


def cruza_puntos(poblacion):
    x, x1 = 0, 0
    ptoCruza = 0.8
    pobcruza=[]

    for i in range(4):
        padre1 =  random.randint(0, 7)
        padre2 =  random.randint(0, 7)
        padre3 =  random.randint(0, 7)
    
        #Aleatorio punto de cruza
        y=rnd.randint()
        # Punto inicial
        x = random.randint(1, 3)
        # Punto final, debe ser mayor al punto inicial
        x1 = -1
        while x1 <= x:
            x1 = random.randint(0, 7)
    
        if y<ptoCruza:
            # una vez teniendo los dos puntos realizamos la cruza
            hijo_real_1 = np.concatenate((np.array(poblacion[padre1][0:x]), np.array(poblacion[padre2][x:x1]), np.array(poblacion[padre1][x1:6])))
            hijo_real_2 = np.concatenate((np.array(poblacion[padre1][0:x]), np.array(poblacion[padre3][x:x1]), np.array(poblacion[padre1][x1:6])))
            pobcruza.append(hijo_real_1)
            pobcruza.append(hijo_real_2)
        else:
            pobcruza.append(poblacion[padre1])
            pobcruza.append(poblacion[padre2])
    return pobcruza


def muta_aleatorio(poblacion):
    pobMuta=[]
    ptomuta=0.2
    puntomuta=rnd.randint(0,5)
    for i in range(8):
        x = rnd.random()
        if (x<ptomuta):
            d=cll.deque(poblacion[i])
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

def probSeleccion(fitness):
  pSeleccion=[]
  suma = sum(fitness)
  for i in fitness:
    pSeleccion.append(i/suma)
  return pSeleccion

if __name__ == '__main__':
    generaciones = 200
    fitlim = 0.5
    n_gen = 1
    fitness = 0

    print("hola")
    while (n_gen < generaciones):
        poblacion = generarPoblacion()
        # fitness = obtener_fitness(poblacion)
        # poblacion = torneo(poblacion, fitness)
        #poblacion = elitismo(poblacion, fitness, True)
        # poblacion = cruza_puntos(poblacion)
        print(cruza_puntos(poblacion))
        print(muta_aleatorio(poblacion))
        n_gen += 1
