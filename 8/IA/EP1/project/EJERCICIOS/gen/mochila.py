import random

obj_price = {
    0: 4,
    1: 2,
    2: 10,
    3: 1,
    4: 2
}

obj_weight = {
    0: 12,
    1: 1,
    2: 4,
    3: 1,
    4: 2
}


def initPob():
    pob = []
    for i in range(6):
        ind = []
        for j in range(5):
            if random.random() <= 0.5:
                ind.append(1)
            else:
                ind.append(0)
        pob.append(ind)

    return pob


def calcPes(pob):
    pesos = []
    for i in range(6):
        sums = 0
        for index, value in enumerate(pob[i]):
            if value == 1:
                sums += obj_price[index]
        pesos.append(sums)

    return pesos


def calcPS(pob):
    fit = []
    sum_tot = sum(pob)
    for i in range(6):
        res = pob[i] / sum_tot
        fit.append(res)

    return fit


def calcWeight(ind):
    weight = 0
    for index, value in enumerate(ind):
        if value == 1:
            weight += obj_weight[index]

    return weight


def selRul(pob):
    max_weight = 15
    ind_select = []
    for i in range(6):
        if calcWeight(pob[i]) < max_weight:
            ind_select.append(pob[i])

    return ind_select


if __name__ == '__main__':
    pob = initPob()
    pes = calcPes(pob)
    calcPs = calcPS(pes)
    nuevaPob = selRul(pob)
