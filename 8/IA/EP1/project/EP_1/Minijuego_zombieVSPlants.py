import random


def crear_matriz():
    planta = [(random.randint(0, 4), 0)]
    zombie = [(random.randint(0, 4), 4)]
    return planta, zombie


def calcular_distancia(planta, zombie):
    zoom_n = len(zombie)
    zoom_flg = [0] * zoom_n

    dis = 0
    for p in planta:
        r = p[0]
        c = p[1]
        zoom_id = -1
        distancia_minima = -1
        for j in range(zoom_n):
            if zoom_flg[j]:
                continue
            r1 = zombie[j][0]
            c1 = zombie[j][1]
            distancia_actual = abs(r1 - r) + abs(c1 - c)
            if distancia_minima == -1 or distancia_minima > distancia_actual:
                distancia_minima = distancia_actual
                zoom_id = j
        if distancia_minima == -1:
            dis += 100
        else:
            dis += distancia_minima
            zoom_flg[zoom_id] = 1

    return dis


def imprimir_matriz(planta, zombie):
    # 0 - Vacio 1 - planta 2 - zombie
    matriz = []
    for r in range(5):
        cur_row = ['_'] * 5
        matriz.append(cur_row)
    for p in planta:
        matriz[p[0]][p[1]] = 'P'
    for z in zombie:
        matriz[z[0]][z[1]] = 'Z'

    for r in range(5):
        for c in range(5):
            print(matriz[r][c], end='')
        print()
    print()


def esValido(zombie):
    for zoom in zombie:
        if zoom[0] < 0 or zoom[0] > 4 or zoom[1] < 0 or zoom[1] > 4:
            return False
    zoom_n = len(zombie)
    for i in range(zoom_n):
        for j in range(i + 1, zoom_n):
            if zombie[i] == zombie[j]:
                return False

    return True


def main():
    planta, zombie = crear_matriz()
    distancia_actual = calcular_distancia(planta, zombie)

    wx = [0, 1, -1, 0]
    wy = [1, 0, 0, -1]

    T = 0
    while distancia_actual > 0:
        T += 1
        print("\nPaso = ", T, ":")
        imprimir_matriz(planta, zombie)

        zoom_n = len(zombie)
        total_plan = 4 ** zoom_n
        for i in range(total_plan):
            p = i
            next_zoom_list = []
            for j in range(zoom_n):
                d = p % 4
                p //= 4
                r = zombie[j][0] + wy[d]
                c = zombie[j][1] + wx[d]
                next_zoom_list.append((r, c))

            if esValido(next_zoom_list):
                distancia_sig = calcular_distancia(planta, next_zoom_list)
                if distancia_sig < distancia_actual:
                    distancia_actual = distancia_sig
                    zombie.clear()
                    for zoom in next_zoom_list:
                        zombie.append(zoom)
                        plant_n = len(planta)
                        for j in range(plant_n):
                            if planta[j] == zoom:
                                planta.pop(j)
                                break
                    break

    T += 1
    print("\nPaso = ", T, ":")
    imprimir_matriz(planta, zombie)


if __name__ == '__main__':
    main()
