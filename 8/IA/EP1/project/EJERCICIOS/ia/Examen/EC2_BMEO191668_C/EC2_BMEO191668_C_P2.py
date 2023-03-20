#Algoritmo genetico para la funcion de Styblinski-Tang

"""
Paso 1: Generar Poblacion inicial
Paso 2: Calcular Fitness
Paso 3: Ciclo reproductiva
Paso 3.1: Seleccion(seleccion por torneo)
Paso 3.2: Cruza
Paso 3.3: Muta
Paso 3.4: Evaluación
"""
import math
import numpy as np
import random as rnd

def generarPoblacion():
    pob = [[-10 + rnd.random() * 20 for _ in range(6)] for _ in range(8)]
    return pob

def fitness(ind):
    f = 0
    for i in range(len(ind) - 1):
        x1, x2 = ind[i], ind[i + 1]
        f += 1/2 *(math.pow(x1, 4) - 16 * math.pow(x1, 2) + 5 * x1) + (math.pow(x2, 4) - 16 * math.pow(x2, 2) + 5 * x2)
    return f

def fitness_poblacion(poblacion):
    fit = []
    for ind in poblacion:
        f = fitness(ind)
        fit.append(f)
    suma = sum(fit)
    promedio = suma / len(fit)
    return promedio

def seleccion_torneo(poblacion, tamano_torneo=2):
    seleccionados = []
    while len(seleccionados) < len(poblacion):
        torneo = rnd.sample(poblacion, tamano_torneo)
        mejor_individuo = min(torneo, key=fitness)
        seleccionados.append(mejor_individuo)
    return seleccionados

def seleccion_elitismo(poblacion):
    poblacion_ordenada = sorted(poblacion, key=fitness)
    mejores = poblacion_ordenada[:5]
    seleccion_aleatoria = rnd.sample(mejores, 3)
    seleccion_final = mejores + seleccion_aleatoria
    return seleccion_final

def seleccion(poblacion):
    if rnd.random() < 0.45:
        print("Elitismo")
        return seleccion_elitismo(poblacion)
    else:
        print("Torneo")
        return seleccion_torneo(poblacion)

def Cruza(pob):
    pobCruz = []
    pCruza = 0.8
    for i in range(4):
        x = rnd.random()
        ind1, ind2, ind3 = 0,0,0
        while(ind1 == ind2 or ind2 == ind3 or ind3 == ind1):
            ind1 = rnd.randint(0,7)
            ind2 = rnd.randint(0,7)
            ind3 = rnd.randint(0,7)
        if (x < pCruza):
            ptoCruza1 = rnd.randint(0,5)
            ptoCruza2 = rnd.randint(0,5)
            pobCruz.append(np.concatenate((pob[ind1][0:ptoCruza1], pob[ind2][ptoCruza1:ptoCruza2], pob[ind1][ptoCruza2:8]), axis=0))
            pobCruz.append(np.concatenate((pob[ind1][0:ptoCruza1], pob[ind3][ptoCruza1:ptoCruza2], pob[ind1][ptoCruza2:8]), axis=0))
        else:
            pobCruz.append(pob[ind1])
            pobCruz.append(pob[ind3])
    return pobCruz

def Muta(poblacion):
    pMut = 0.2
    for i in range(len(poblacion)):
        if rnd.random() < pMut:
            puntoMut = rnd.randint(0, 5)
            poblacion[i][puntoMut] = poblacion[i][(puntoMut + 3) % 6]
    return poblacion

if __name__ == '__main__':
    # función principal
    pob = generarPoblacion()
    print("Poblacion Inicial ", pob)
    NG=200
    i=0
    while(i<NG):
        val_fit = fitness_poblacion(pob)
        if val_fit > 0.5:
            pob= seleccion(pob)
            print("Poblacion Seleccionada", pob)
            pob=Cruza(pob)
            print("Poblacion Cruzada", pob)
            pob=Muta(pob)
            print("Poblacion Mutada", pob)
            i+=1
        else:
            i = 200