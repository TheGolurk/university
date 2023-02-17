import heapq

# Función para calcular la heurística de piezas bien colocadas
def h1(state, goal_state):
    count = 0
    for i in range(9):
        if state[i] != goal_state[i] and state[i] != 0:
            count += 1
    return count

# Función para mover las piezas en un estado
def move(state, direction):
    # Encontrar la posición de la pieza vacía
    index = state.index(0)

    if direction == "left":
        if index not in [0, 3, 6]:
            new_state = state[:]
            new_state[index], new_state[index - 1] = new_state[index - 1], new_state[index]
            return new_state
        else:
            return None
    elif direction == "right":
        if index not in [2, 5, 8]:
            new_state = state[:]
            new_state[index], new_state[index + 1] = new_state[index + 1], new_state[index]
            return new_state
        else:
            return None
    elif direction == "up":
        if index not in [0, 1, 2]:
            new_state = state[:]
            new_state[index], new_state[index - 3] = new_state[index - 3], new_state[index]
            return new_state
        else:
            return None
    elif direction == "down":
        if index not in [6, 7, 8]:
            new_state = state[:]
            new_state[index], new_state[index + 3] = new_state[index + 3], new_state[index]
            return new_state
        else:
            return None

# Función para resolver el problema del 8-puzzle utilizando A*
def solve_puzzle(start, goal, h):
    heap = []
    heapq.heappush(heap, (h(start, goal), 0, start))
    visited = set()
    moves = []

    while heap:
        node = heapq.heappop(heap)
        g = node[1]
        state = node[2]

        if state == goal:
            return moves

        if tuple(state) in visited:
            continue

        visited.add(tuple(state))

        for direction in ["left", "right", "up", "down"]:
            child = move(state, direction)
            if child:
                moves.append(direction)
                heapq.heappush(heap, (g + 1 + h(child, goal), g + 1, child))

    return None

# Estado inicial y objetivo
start = [2, 8, 3, 1, 0, 4, 7, 6, 5]

goal = [1, 2, 3, 8, 0, 4, 7, 6, 5]
#Llamar a la función para resolver el 8-puzzle

moves = solve_puzzle(start, goal, h1)
#Imprimir la mejor solución aceptada en cada iteración

if moves:
    print("Mejor solución aceptada en cada iteración: " + str(moves))
else:
    print("No se pudo encontrar una solución")