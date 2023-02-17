# Algoritmo de Busqueda Ciega: Busqueda en profundidad por derecha (BPder)

# Construccion del arbol n-ario estatico
class arbol:
    def __init__(self, valor, limite):
        self.valor = valor
        self.limite = limite
        self.hijos = []


# Definir arbol n-ario
raiz = arbol("Arab", 0)

# hijos del raiz
raiz.hijos.append(arbol("Timisura", 1))
raiz.hijos.append(arbol("Sibiu", 1))
raiz.hijos.append(arbol("Zerind", 1))

# hijos del nodo 2 (indice 0)
raiz.hijos[0].hijos.append(arbol("Lugoj", 2))

# hijos del nodo 3 (indice 1)
raiz.hijos[1].hijos.append(arbol("Rimnicu", 2))
raiz.hijos[1].hijos.append(arbol("Fagaras", 2))

# hijos del nodo 4 (indice 2)
raiz.hijos[2].hijos.append(arbol("Oradea", 2))

# hijos del nodo 5 (indice 0)
raiz.hijos[0].hijos[0].hijos.append(arbol("Mehadia", 3))

# hijos del nodo 6 (indice 0)
raiz.hijos[1].hijos[0].hijos.append(arbol("Craiova", 3))
raiz.hijos[1].hijos[0].hijos.append(arbol("Pitesti", 3))

# hijos del nodo 7 (indice 1)
raiz.hijos[1].hijos[1].hijos.append(arbol("Bucharest", 3))

# hijos del nodo 8 (indice 0)
raiz.hijos[2].hijos[0].hijos.append(arbol("Sibiu", 3))

# hijos del nodo 9 (indice 0)
raiz.hijos[0].hijos[0].hijos[0].hijos.append(arbol("Dobreta", 4))

# hijos del nodo 11 (indice 1)
raiz.hijos[1].hijos[0].hijos[1].hijos.append(arbol("Bucharest", 4))

# hijos del nodo 13 (indice 0)
raiz.hijos[2].hijos[0].hijos[0].hijos.append(arbol("Rimnicu", 4))
raiz.hijos[2].hijos[0].hijos[0].hijos.append(arbol("Fagaras", 4))

# hijos del nodo 14 (indice 0)
raiz.hijos[0].hijos[0].hijos[0].hijos[0].hijos.append(arbol("Craiova", 5))

agenda = [raiz]
nodoBuscar = input(("Ingresa el nombre del nodo a buscar:\n"))

print("====== SELECCIONAR METODO DE BUSQUEDA ======\n")
print(
    "ANCHURA POR DERRECHA (1)\nANCHURA POR IZQUIERDA (2)\n\nPROFUNDIDAD POR DERECHA (3)\nPROFUNDIDAD POR IZQUIERDA (4)\n\nPROFUNDIDAD LIMITADA POR IZQUIERDA (5)\nPROFUNDIDAD LIMITADA POR DERECHA (6)\n")

opcion = int(input("ingresar opcion: "))

if opcion == 1:  # BUSQUEDA EN ANCHURA POR DERECHA
    while agenda:
        nodo = agenda.pop(0)  # lo sacamos de la pila con pop (si se agrega el indice 0 se comportara como cola)
        print("nodo visitado", nodo.valor)
        if nodo.valor == nodoBuscar:  # identifica si es el nodo que buscamos, se acaba la busqueda
            break
        else:
            for i in reversed(
                    nodo.hijos):  # se hace la busqueda en profundidad por derecha (con "reversed" lo hace por la derecha)
                agenda.append(i)
elif opcion == 2:  # BUSQUEDA EN ANCHURA POR IZQUIERDA
    while agenda:
        nodo = agenda.pop(0)  # lo sacamos de la pila con pop (si se agrega el indice 0 se comportara como cola)
        print("nodo visitado", nodo.valor)
        if nodo.valor == nodoBuscar:  # identifica si es el nodo que buscamos, se acaba la busqueda
            break
        else:
            for i in (
                    nodo.hijos):  # se hace la busqueda en profundidad por izquierda (sin "reversed" lo hace por la izquierda)
                agenda.append(i)
elif opcion == 3:  # BUSQUEDA EN PROFUNDIDAD POR DERECHA
    while agenda:
        nodo = agenda.pop()  # lo sacamos de la pila con pop (si se agrega el indice 0 se comportara como cola)
        print("nodo visitado", nodo.valor)
        if nodo.valor == nodoBuscar:  # identifica si es el nodo que buscamos, se acaba la busqueda
            break
        else:
            for i in (
                    nodo.hijos):  # se hace la busqueda en profundidad por derecha (sin "reversed" lo hace por la derecha)
                agenda.append(i)
elif opcion == 4:  # BUSQUEDA EN PROFUNDIDAD POR IZQUIERDA
    while agenda:
        nodo = agenda.pop()  # lo sacamos de la pila con pop (si se agrega el indice 0 se comportara como cola)
        print("nodo visitado", nodo.valor)
        if nodo.valor == nodoBuscar:  # identifica si es el nodo que buscamos, se acaba la busqueda
            break
        else:
            for i in reversed(
                    nodo.hijos):  # se hace la busqueda en profundidad por izquierda (con "reversed" lo hace por la izquierda)
                agenda.append(i)
elif opcion == 5:  # BUSQUEDA EN PROFUNDIDAD LIMITADA POR DERECHA
    limite = int(input("Ingresar limite (limites permitidos 0-5): "))
    if limite <= 5:
        while agenda:
            nodo = agenda.pop()  # lo sacamos de la pila con pop (si se agrega el indice 0 se comportara como cola)
            print("nodo visitado:", nodo.valor)
            if nodo.valor == nodoBuscar:  # identifica si es el nodo que buscamos, se acaba la busqueda
                break
            else:
                if nodo.limite < limite:
                    for i in reversed(
                            nodo.hijos):  # se hace la busqueda en profundidad por derecha (con "reversed" lo hace por la derecha)
                        agenda.append(i)
    else:
        print("Error en el limite")
elif opcion == 6:  # BUSQUEDA EN PROFUNDIDAD LIMITADA POR IZQUIERDA
    limite = int(input("Ingresar limite (limites permitidos 0-5): "))
    if limite <= 5:
        while agenda:
            nodo = agenda.pop()  # lo sacamos de la pila con pop (si se agrega el indice 0 se comportara como cola)
            print("nodo visitado", nodo.valor)
            if nodo.valor == nodoBuscar:  # identifica si es el nodo que buscamos, se acaba la busqueda
                break
            else:
                if (nodo.limite < limite):
                    for i in (
                            nodo.hijos):  # se hace la busqueda en profundidad por izquierda (sin "reversed" lo hace por la izquierda)
                        agenda.append(i)
    else:
        print("Error en el limite")
elif opcion == 7:  # BUSQUEDA EN PROFUNDIDAD ITERATIVA POR IZQUIERDA
    limite = int(input("Ingresar limite (limites permitidos 0-5): "))
    if limite <= 5:
        while agenda:
            nodo = agenda.pop()  # lo sacamos de la pila con pop (si se agrega el indice 0 se comportara como cola)
            print("nodo visitado", nodo.valor)
            if nodo.valor == nodoBuscar:  # identifica si es el nodo que buscamos, se acaba la busqueda
                break
            else:
                if nodo.limite < limite:
                    for i in (
                            nodo.hijos):  # se hace la busqueda en profundidad por izquierda (sin "reversed" lo hace por la izquierda)
                        agenda.append(i)
    else:
        print("Error en el limite")
else:
    print("Error en la seleccion")
