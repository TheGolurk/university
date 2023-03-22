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
    X = [[1, 3],
         [1, 5],
         [2, 6],
         [3, 6],
         [1, 0],
         [1, 1],
         [4, 1],
         [5, 1]]
    dx = [-1, -1, -1, -1, 1, 1, 1, 1]

    for i in range(8):
        y = (X[i][0] * w1 + X[i][0 + 1] * w2)
        x = y + theta
        y = escalon(x)

        while y != dx[i]:
            dw1 = dx[i] * X[i][0]
            w1 += dw1
            dw2 = dx[i] * X[i][0 + 1]
            w2 += dw2
            theta += dx[i]
            y = (X[i][0] * w1 + X[i][0 + 1] * w2)
            x = y + theta
            y = escalon(x)

        print(y)
