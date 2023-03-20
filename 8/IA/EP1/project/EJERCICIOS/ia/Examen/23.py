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


def seleccion_por_torneo(poblacion, fitness, maximizar):
   
    nueva_poblacion = np.empty_like(poblacion)
    
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
    pobElitista = []
    # Obtener el índice de los mejores cinco individuos de acuerdo a su aptitud
    if maximizar:
        mejores_indices = np.argsort(fitness)[:5]
    else:
        mejores_indices = np.argsort(fitness)[:5]

    # Seleccionar los mejores cinco individuos y combinarlos con tres individuos aleatorios de los cinco
    pobElitista = poblacion[mejores_indices]
    for i in range(3):
        individuo_random = random.choice(mejores_indices)
        pobElitista = np.vstack((pobElitista, poblacion[individuo_random]))

    return pobElitista

   

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
    fitness = 0
    
    while(n_gen < generaciones ):
        poblacion = generarPoblacion()
        
        fitness = obtener_fitness(poblacion)
        #poblacion = seleccion_por_torneo(poblacion)
        #poblacion = cruza_puntos(poblacion)
        #poblacion = muta_aleatorio(poblacion)
        print("Población:")
        print(poblacion)
        print("---------------------------------------------------------")
        #print(seleccion_por_torneo(poblacion,fitness,True))
        #print("----------------------------------------------------------")
        print(elitismo(poblacion,fitness,True))