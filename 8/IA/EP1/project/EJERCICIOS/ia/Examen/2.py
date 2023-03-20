import random as rnd
import random
import math as mt
import numpy as np

def generarPoblacion():
  poblacion= np.zeros((8,6))
  for i in range(8):
      for j in range(6):
        x=-5+rnd.random()*10
        poblacion[i][j]=x
  return poblacion


def torneo(poblacion,fitness):
    pobTorneo = []
    
    for i in range(8):
        ind1,ind2 = 0,0
        while ind1==ind2:
            ind1 = rnd.randint(0,5)
            ind2 = rnd.randint(0,5)
            
        if (fitness[ind1]<fitness[ind2]):
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
    pobcruza=[]
    x,x1=0,0

    x=random.randint(0,7)
    padre1 = poblacion[x]
    x=random.randint(0,7)
    padre2 = poblacion[x]
    x=random.randint(0,7)
    padre3 = poblacion[x]
    
    for i in range(8):
        
        for j in range(6):
            # Punto inicial
            x=random.randint(0,3)
            # Punto final, debe ser mayor al punto inicial
            x1 = -1
            while x1 < x:
                x1=random.randint(0,7)
                

            #una vez teniendo los dos puntos realizamos la cruza
            

    return pobcruza


def muta_aleatorio(poblacion):
    return []

def obtener_fitness(poblacion):
    fitness=[]
    for i in range(8): #el recorrido de los individuos
        f=0
        for j in range(6): #recorrido de genes
            f = 1/2((mt.pow(poblacion[i][j]),4)-16*(mt.pow(poblacion[i][j]),2)+5*(poblacion[i][j]))
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
        poblacion = torneo(poblacion)
        poblacion = cruza_puntos(poblacion)
        poblacion = muta_aleatorio(poblacion)
        n_gen += 1
    