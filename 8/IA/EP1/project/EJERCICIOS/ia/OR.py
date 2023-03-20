import random


def initParam():
    val = [-1, -0.5, 0, 0.5, 1]
    weights1 = val[random.randint(0, 4)]
    weights2 = val[random.randint(0, 4)]
    theta = val[random.randint(0, 4)]

    return weights1, weights2, theta


def escalon(x):
    if x > 0:
        return 1
    else:
        return -1


if __name__ == '__main__':
    w1, w2, theta = initParam()
    X = [[-1, -1],
         [-1, 1],
         [1, -1],
         [1, 1]]
    dx = [-1, 1, 1, 1]

    for i in range(4):
        for j in range(1):

            # evular funcion sigma
            y = (X[i][j] * w1 + X[i][j+1] * w2)
            x = y + theta
            y = escalon(x)

            if y != dx[i]:
                while y != dx[i]:
                    dw1 = dx[i] * X[i][j] #calcular gradiente
                    w1 += dw1  # actualizar pesos
                    dw2 = dx[i]*X[i][j+1]
                    w2 += dw2
                    theta += dx[i]
                    y = (X[i][j] * w1 + X[i][j + 1] * w2)
                    x = y + theta
                    y = escalon(x)

            print(y)

