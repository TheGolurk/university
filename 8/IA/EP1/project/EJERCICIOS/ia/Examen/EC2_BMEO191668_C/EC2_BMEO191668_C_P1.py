#Algoritmo genetico para la funcion de Schaffer

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
    pob = [[-10 + rnd.random() * 20 for _ in range(8)] for _ in range(10)]
    return pob

def fitness(pob):
    fit = []
    for ind in pob:
        f = 0
        for i in range(len(ind) - 1):
            x1, x2 = ind[i], ind[i + 1]
            f += (math.pow(math.sin(math.pow(x1, 2) - math.pow(x2, 2)), 2) - 0.5) / math.pow(1 + 0.001 * (math.pow(x1, 2) + math.pow(x2, 2)), 2)
        fit.append(f)
    return fit

def probSeleccion(fitness):
    pSelec = []
    suma = 0
    for i in fitness:
        suma+= 1-i

    for j in fitness:
        pSelec.append((1-j) / suma)

    sumaCom = sum(pSelec)
    print(sumaCom)

    return pSelec

def selectRuleta(pSelec, pob):
    pobSelec = []
    for i in pob:
        x = rnd.random()

        if x >= 0 and x <= pSelec[0]:
            pobSelec.append(pob[0])
        elif x >= pSelec[0] and x <= pSelec[0] + pSelec[1]:
            pobSelec.append(pob[1])
        elif x >= pSelec[0] + pSelec[1] and x <= pSelec[0] + pSelec[1] + pSelec[2]:
            pobSelec.append(pob[2])
        elif x >= pSelec[0] + pSelec[1] + pSelec[2] and x <= pSelec[0] + pSelec[1] + pSelec[2] + pSelec[3]:
            pobSelec.append(pob[3])
        elif x >= pSelec[0] + pSelec[1] + pSelec[2] + pSelec[3] and x <= pSelec[0] + pSelec[1] + pSelec[2] + pSelec[3] + pSelec[4]:
            pobSelec.append(pob[4])
        elif x >= pSelec[0] + pSelec[1] + pSelec[2] + pSelec[3] + pSelec[4] and x <= pSelec[0] + pSelec[1] + pSelec[2] + pSelec[3] + pSelec[4] + pSelec[5]:
            pobSelec.append(pob[5])
        elif x >= pSelec[0] + pSelec[1] + pSelec[2] + pSelec[3] + pSelec[4] + pSelec[5] and x <= pSelec[0] + pSelec[1] + pSelec[2] + pSelec[3] + pSelec[4] + pSelec[5] + pSelec[6]:
            pobSelec.append(pob[6])
        else:
            pobSelec.append(pob[7])

    return pobSelec

def Cruza(pob):
    pobCruz = []
    pCruza = 0.7

    for i in range(5):
        x = rnd.random()
        ind1, ind2 = 0,0
        while(ind1 == ind2):
            ind1 = rnd.randint(0,9)
            ind2 = rnd.randint(0,9)
        if (x < pCruza):
            ptoCruza1 = 3
            ptoCruza2 = 6
            pobCruz.append(np.concatenate((pob[ind1][0:ptoCruza1], pob[ind2][ptoCruza1:ptoCruza2], pob[ind1][ptoCruza2:8]), axis=0))
            pobCruz.append(np.concatenate((pob[ind2][0:ptoCruza1], pob[ind1][ptoCruza1:ptoCruza2], pob[ind2][ptoCruza2:8]), axis=0))
        else:
            pobCruz.append(pob[ind1])
            pobCruz.append(pob[ind2])
    return pobCruz

def Muta(pobCruz):
    pobMut = []
    pMuta = 0.1
    for ind in pobCruz:
        x = rnd.random()
        if x < pMuta:
            indice = rnd.sample(range(ind.shape[0]), 3)
            indMuta = ind.copy()
            indMuta[indice] += np.random.rand(3)
            pobMut.append(indMuta)
        else:
            pobMut.append(ind)
    return pobMut

if __name__ == '__main__':
    # función principal
    pob = generarPoblacion()
    print("Poblacion Inicial ", pob)
    NG=200
    i=0
    while(i<NG):
        fit_vals = fitness(pob)
        pSelec = probSeleccion(fit_vals)
        pob=selectRuleta(pSelec, pob)
        pob=Cruza(pob)
        print("Poblacion Cruzada", pob)
        pob=Muta(pob)
        print("Poblacion Mutada", pob)
        i+=1