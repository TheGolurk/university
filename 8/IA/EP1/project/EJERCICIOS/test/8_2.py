# Node:
data = []
level = 0
fval = 0


def generate_child(self):
    """ Generate child nodes from the given node by moving the blank space
        either in the four directions {up,down,left,right} """
    x, y = self.find(self.data, '_')
    """ val_list contains position values for moving the blank space in either of
        the 4 directions [up,down,left,right] respectively. """
    val_list = [[x, y - 1], [x, y + 1], [x - 1, y], [x + 1, y]]
    children = []
    for i in val_list:
        child = self.shuffle(self.data, x, y, i[0], i[1])
        if child is not None:
            child_node = Node(child, self.level + 1, 0)
            children.append(child_node)
    return children


def shuffle(self, puz, x1, y1, x2, y2):
    """ Move the blank space in the given direction and if the position value are out
        of limits the return None"""
    if 0 <= x2 < len(self.data) and 0 <= y2 < len(self.data):
        temp_puz = []
        temp_puz = self.copy(puz)
        temp = temp_puz[x2][y2]
        temp_puz[x2][y2] = temp_puz[x1][y1]
        temp_puz[x1][y1] = temp
        return temp_puz
    else:
        return None


def copy(self, root):
    """ Copy function to create a similar matrix of the given node"""
    temp = []
    for i in root:
        t = []
        for j in i:
            t.append(j)
        temp.append(t)
    return temp


def find(self, puz, x):
    """ Specifically used to find the position of the blank space """
    for i in range(0, len(self.data)):
        for j in range(0, len(self.data)):
            if puz[i][j] == x:
                return i, j


# Puzzle
size = 0
open = []
closed = []

def obtener_matriz():
    matriz = []
    for i in range(0, 3):
        temp = input().split(" ")
        matriz.append(temp)
    return matriz


def distancia(inicio_m, meta_m):
    temp = 0
    for i in range(0, 3):
        for j in range(0, 3):
            if inicio_m[i][j] != meta_m[i][j] and inicio_m[i][j] != '_':
                temp += 1
    return temp + inicio_m.level


print("Ingresa la primera matriz \n")
inicio = obtener_matriz()
print("Ingres la matriz destino \n")
meta = obtener_matriz()

valor_distancia = distancia(inicio.data, meta)
