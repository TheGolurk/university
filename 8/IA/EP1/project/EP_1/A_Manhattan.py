def leer_matriz(msg: str):
    print(msg)
    matriz = []
    num_flg = [0] * 9

    for r in range(3):
        cur_row = []
        line = input().strip().split()
        for c in range(3):
            v = line[c]
            num = 0
            if '0' < v < '9':
                num = int(v)
            cur_row.append(num)
            if num_flg[num] == 1:
                return None
            num_flg[num] = 1
        matriz.append(cur_row)
    return matriz


def encontrar_pos(matriz, num):
    for r in range(3):
        for c in range(3):
            if matriz[r][c] == num:
                return r, c


def calcular_distancia(matriz_actual, matriz_meta):
    dis = 0
    for i in range(1, 9):
        r1, c1 = encontrar_pos(matriz_actual, i)
        r2, c2 = encontrar_pos(matriz_meta, i)
        dis += abs(r1 - r2) + abs(c1 - c2)
    return dis


def mostrar_matriz(matriz):
    for r in range(3):
        for c in range(3):
            if matriz[r][c] == 0:
                print('_', end=' ')
            else:
                print(matriz[r][c], end=' ')
        print()
    print()


def main():
    matriz_actual = leer_matriz('Ingresa la matriz inicial:')
    if matriz_actual is None:
        print('Matriz invalida')
        return
    print()
    matriz_meta = leer_matriz('Ingresa la matriz destino:')
    if matriz_meta is None:
        print('Matriz invalida')
        return
    print()
    print('==========================')

    wx = [0, 1, 0, -1]
    wy = [1, 0, -1, 0]
    actualizado = True
    num_paso = 0
    while actualizado:
        num_paso += 1
        print("Movimiento ", num_paso, ':')
        print()
        mostrar_matriz(matriz_actual)

        actualizado = False
        r0, c0 = encontrar_pos(matriz_actual, 0)
        distancia_actual = calcular_distancia(matriz_actual, matriz_meta)
        for i in range(4):
            r1 = r0 + wy[i]
            c1 = c0 + wx[i]
            if r1 >= 0 and r1 < 3 and c1 >= 0 and c1 < 3:
                matriz_actual[r1][c1], matriz_actual[r0][c0] = matriz_actual[r0][c0], matriz_actual[r1][c1]
                next_dis = calcular_distancia(matriz_actual, matriz_meta)
                if next_dis < distancia_actual:
                    actualizado = True
                    break
                else:
                    matriz_actual[r1][c1], matriz_actual[r0][c0] = matriz_actual[r0][c0], matriz_actual[r1][c1]


if __name__ == '__main__':
    main()
