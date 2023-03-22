import math
import random as rnd
import numpy as np


##PASO 1
def primeraPoblacion():
    columna = []
    for _ in range(10):
        fila = []
        for _ in range(8):
            x = -10 + rnd.random() * 20
            fila.append(x)
        columna.append(fila)

    return columna


##PASO 2
def calc_Fitness(pob):
    fitness_suma = []
    for ind in pob:
        f = 0
        for i, _ in enumerate(ind):
            f += (math.pow(math.sin(math.pow(i, 2) - math.pow(i + 1, 2)), 2) - 0.5) / math.pow(1 + 0.001 * (math.pow(i, 2) + math.pow(i + 1, 2)), 2)
        fitness_suma.append(f)

    return fitness_suma


##PASO 3.1
def probSeleccion(calc_Fitness):
    prob_Seleccion = []
    suma = 0
    for i in calc_Fitness:
        suma += 1 - i

    for k in calc_Fitness:
        prob_Seleccion.append((1 - k) / suma)

    sumTot = sum(prob_Seleccion)
    print(sumTot)

    return prob_Seleccion


def selectRuleta(pob):
    fit_vals = calc_Fitness(pob)
    prob_Seleccion = probSeleccion(fit_vals)

    pobSelec = []
    for i in pob:
        x = rnd.random()

        if x >= 0 and x <= prob_Seleccion[0]:
            pobSelec.append(pob[0])
        elif x >= prob_Seleccion[0] and x <= prob_Seleccion[0] + prob_Seleccion[1]:
            pobSelec.append(pob[1])
        elif x >= prob_Seleccion[0] + prob_Seleccion[1] and x <= prob_Seleccion[0] + prob_Seleccion[1] + prob_Seleccion[
            2]:
            pobSelec.append(pob[2])
        elif x >= prob_Seleccion[0] + prob_Seleccion[1] + prob_Seleccion[2] and x <= prob_Seleccion[0] + prob_Seleccion[
            1] + prob_Seleccion[2] + prob_Seleccion[3]:
            pobSelec.append(pob[3])
        elif x >= prob_Seleccion[0] + prob_Seleccion[1] + prob_Seleccion[2] + prob_Seleccion[3] and x <= prob_Seleccion[
            0] + prob_Seleccion[1] + prob_Seleccion[2] + prob_Seleccion[3] + prob_Seleccion[4]:
            pobSelec.append(pob[4])
        elif x >= prob_Seleccion[0] + prob_Seleccion[1] + prob_Seleccion[2] + prob_Seleccion[3] + prob_Seleccion[
            4] and x <= prob_Seleccion[0] + prob_Seleccion[1] + prob_Seleccion[2] + prob_Seleccion[3] + prob_Seleccion[
            4] + prob_Seleccion[5]:
            pobSelec.append(pob[5])
        elif x >= prob_Seleccion[0] + prob_Seleccion[1] + prob_Seleccion[2] + prob_Seleccion[3] + prob_Seleccion[4] + \
                prob_Seleccion[5] and x <= prob_Seleccion[0] + prob_Seleccion[1] + prob_Seleccion[2] + prob_Seleccion[
            3] + prob_Seleccion[4] + prob_Seleccion[5] + prob_Seleccion[6]:
            pobSelec.append(pob[6])
        else:
            pobSelec.append(pob[7])

    return pobSelec


##PASO 3.2
def cruzar_poblacion(pob):
    cruzada = []

    for i in range(5):
        x = rnd.random()
        posicion1 = rnd.randint(0, 9)
        posicion2 = rnd.randint(0, 9)
        if x < 0.7:
            primerpunto = rnd.randint(0, 2)
            segundopunto = rnd.randint(4, 6)
            pos1 = pob[posicion1][0:primerpunto]
            pos2 = pob[posicion2][primerpunto:segundopunto]
            pos3 = pob[posicion1][segundopunto:8]
            nuevo_ind = np.concatenate((pos1, pos2, pos3))
            cruzada.append(nuevo_ind)

            pos1 = pob[posicion2][0:primerpunto]
            pos2 = pob[posicion1][primerpunto:segundopunto]
            pos3 = pob[posicion2][segundopunto:8]
            nuevo_ind_2 = np.concatenate((pos1, pos2, pos3))
            cruzada.append(nuevo_ind_2)
        else:
            cruzada.append(pob[posicion1])
            cruzada.append(pob[posicion2])
    return cruzada


##PASO 3.3
def mutar_poblacion(cruzada, prob_mutacion=0.1):
    mutada = []
    for ind in cruzada:
        if np.random.rand() < prob_mutacion:
            ind_mutado = np.copy(ind)
            indices = np.random.choice(ind.shape[0], size=3, replace=False)
            ind_mutado[indices] += np.random.rand(3)
            mutada.append(ind_mutado)
        else:
            mutada.append(ind)
    return mutada


if __name__ == '__main__':
    pob = primeraPoblacion()
    for i in range(200):
        print("generacion numero ", i)
        pob = selectRuleta(pob)
        print("ruleta ", pob)
        pob = cruzar_poblacion(pob)
        print("cruzada ", pob)
        pob = mutar_poblacion(pob)
        print("mutacion", pob)
