def find(puz, x):
    """ Specifically used to find the position of the blank space """
    for i in range(0, len(puz)):
        for j in range(0, len(puz)):
            if puz[i][j] == x:
                return i, j

def copy(puz):
    """ Copy function to create a similar matrix of the given node"""
    temp = []
    for i in puz:
        t = []
        for j in i:
            t.append(j)
        temp.append(t)
    return temp

def shuffle(puz, x1, y1, x2, y2):
    """ Move the blank space in the given direction and if the position value are out
        of limits the return None"""
    if 0 <= x2 < len(puz) and 0 <= y2 < len(puz):
        temp_puz = []
        temp_puz = copy(puz)
        temp = temp_puz[x2][y2]
        temp_puz[x2][y2] = temp_puz[x1][y1]
        temp_puz[x1][y1] = temp
        return temp_puz
    else:
        return None

def generate_child(puz, level):
    """ Generate child nodes from the given node by moving the blank space
        either in the four directions {up,down,left,right} """
    x, y = find(puz, '_')
    """ val_list contains position values for moving the blank space in either of
        the 4 directions [up,down,left,right] respectively. """
    val_list = [[x, y - 1], [x, y + 1], [x - 1, y], [x + 1, y]]
    children = []
    for i in val_list:
        child = shuffle(puz, x, y, i[0], i[1])
        if child is not None:
            child_node = (child, level + 1, 0)
            children.append(child_node)
    return children

def f(start, goal):
    """ Heuristic Function to calculate hueristic value f(x) = h(x) + g(x) """
    return h(start, goal) + start[1]

def h(start, goal):
    """ Calculates the different between the given puzzles """
    temp = 0
    for i in range(0, len(goal)):
        for j in range(0, len(goal)):
            if start[i][j] != goal[i][j] and start[i][j] != '_':
                temp += 1
    return temp

def process():
    """ Accept Start and Goal Puzzle state"""
    print("Enter the start state matrix \n")
    start = accept()
    print("Enter the goal state matrix \n")
    goal = accept()
    start = (start, 0, 0)
    start = (start[0], start[1], f(start, goal))
    """ Put the start node in the open list"""
    open_list = [start]
    closed_list = []
    print("\n\n")
    while True:
        cur = open_list[0][1]
    print("")
    print(" | ")
    print(" | ")
    print(" \'/ \n")
    for i in cur[0]:
    for j in i:
    print(j, end=" ")
    print("")
    """ If the difference between current and goal node is 0 we have reached the goal node"""
    if (h(cur[0], goal) == 0):
        break
    for i in generate_child(cur):
        i_fval = f(i, goal)
        open_list.append([i_fval, i])
        closed_list.append(cur)
    del open_list[0]
    """ sort the opne list based on f value """
    open_list.sort(key=lambda x: x[0], reverse=False)

puz = Puzzle(3)
puz.process()
