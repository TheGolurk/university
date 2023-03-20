import random as rnd
import random
import math
import numpy as np

def generarPoblacion():
  poblacion= np.zeros((8,6))
  for i in range(8):
      for j in range(6):
        x=-5+rnd.random()*10
        poblacion[i][j]=x
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
    pobcruza=[]
    for i in range(8):
        for j in range(6):
            # Punto inicial
            x=random.randint(0,3)

            # Punto final, debe ser mayor al punto inicial
            x1 = -1
            while x1 < x:
                x1=random.randint(0,7)

            #una vez teniendo los dos puntos realizamos la cruza
            pobcruza[i][x]=poblacion[i][x]

    return pobcruza


def muta_aleatorio(poblacion):
    return []

def obtener_fitness(poblacion):
    fitness = []
    for i in range(8):  # el recorrido de los individuos
        f = 0
        for j in range(6):  # recorrido de genes
            f = 1 / 2 * (mt.pow(poblacion[i][j], 4) - 16 * (mt.pow(poblacion[i][j], 2)) + 5 * (poblacion[i][j]))
            fitness.append(f)

    return fitness

if __name__ == '__main__':
    generaciones = 200
    fitlim = 0.5
    n_gen = 1
    fitness = 1
    
    while(generaciones < n_gen  or fitness < fitlim):
        poblacion = generarPoblacion()
        
        fitness = obtener_fitness(poblacion)
        poblacion = seleccion_por_torneo(poblacion)
        poblacion = cruza_puntos(poblacion)
        poblacion = muta_aleatorio(poblacion)
        print(poblacion)
        n_gen += 1
    