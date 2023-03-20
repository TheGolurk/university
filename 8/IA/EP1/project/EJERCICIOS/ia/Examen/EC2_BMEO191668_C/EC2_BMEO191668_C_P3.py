import numpy as np
import random as rnd

def iniParametros():
    w1 = rnd.randrange(-1,1)
    w2 = rnd.randrange(-1,1)
    theta = rnd.randrange(-1,1)
    return w1, w2, theta

def F_escalona(x):
    if x > 0:
        return 1
    else:
        return -1


if __name__ == "__main__":
    X = [[1, 3], [1, 5], [2, 6], [3, 6], [1, 0], [1, 1], [4, 1], [5, 1]]
    dx = [-1,-1,-1,-1,1,1,1,1]

    w1, w2, theta = iniParametros()

    print("Busqueda En Patron De Entrada")
    valores_y = []
    error = True
    while error:
        error = False
        for i in range(len(X)):
            x = X[i][0] * w1 + X[i][1] * w2
            x = x + theta
            y = F_escalona(x)
            if y != dx[i]:
                dw1 = dx[i] * X[i][0]
                w1 = w1 + dw1
                dw2 = dx[i] * X[i][1]
                w2 = w2 + dw2
                theta = theta + dx[i]
                error = True
            else:
                valores_y.append(y)
                valores_y = valores_y[-8:]

        if not error:
            break

    print("Valores correctos de y:", valores_y)
    print("Valor de dx:", dx)
    print("Busqueda Completa")