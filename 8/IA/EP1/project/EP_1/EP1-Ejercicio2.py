# Algoritmo de Busqueda Ciega: Busqueda en profundidad por derecha (BPder)

# Construccion del arbol n-ario estatico
class arbol:
    def __init__(self, valor, limite):
        self.valor = valor
        self.limite = limite
        self.hijos = []


# Definir arbol n-ario
raiz = arbol("A,B,C", 0)

# hijos del raiz
raiz.hijos.append(arbol("BA,C", 1))
raiz.hijos.append(arbol("CA,B", 1))
raiz.hijos.append(arbol("AB,C", 1))
raiz.hijos.append(arbol("CB,A", 1))
raiz.hijos.append(arbol("AC,B", 1))
raiz.hijos.append(arbol("BC,A", 1))

# hijos del nodo 2 (indice 0)
raiz.hijos[0].hijos.append(arbol("CBA", 2))
raiz.hijos[1].hijos.append(arbol("BCA", 2))
raiz.hijos[2].hijos.append(arbol("CAB", 2))
raiz.hijos[3].hijos.append(arbol("ACB", 2))
raiz.hijos[4].hijos.append(arbol("BAC", 2))
raiz.hijos[5].hijos.append(arbol("ABC", 2))

agenda = [raiz]
nodoBuscar = input(("Ingresa el nombre del nodo a buscar:\n"))

print("====== SELECCIONAR METODO DE BUSQUEDA ======\n")
print(
    "ANCHURA POR DERRECHA (1)\nANCHURA POR IZQUIERDA (2)\n\nPROFUNDIDAD POR DERECHA (3)\nPROFUNDIDAD POR IZQUIERDA (4)\n\nANCHURA LIMITADA POR DERECHA (5)\nANCHURA LIMITADA POR IZQUIERDA (6)\n")

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
elif opcion == 5:  # BUSQUEDA EN ANCHURA LIMITADA POR DERECHA
    limite = int(input("Ingresar limite (limites permitidos 0-2): "))
    if limite <= 5:
        while agenda:
            nodo = agenda.pop(0)  # lo sacamos de la pila con pop (si se agrega el indice 0 se comportara como cola)
            print("nodo visitado:", nodo.valor)
            if nodo.valor == nodoBuscar:  # identifica si es el nodo que buscamos, se acaba la busqueda
                break
            else:
                if nodo.limite < limite:
                    for i in reversed(nodo.hijos):  # se hace la busqueda en profundidad por derecha (con "reversed" lo hace por la derecha)
                        agenda.append(i)
    else:
        print("Error en el limite")
elif opcion == 6:  # BUSQUEDA EN ANCHURA LIMITADA POR IZQUIERDA
    limite = int(input("Ingresar limite (limites permitidos 0-2): "))
    if limite <= 5:
        while agenda:
            nodo = agenda.pop(0)  # lo sacamos de la pila con pop (si se agrega el indice 0 se comportara como cola)
            print("nodo visitado", nodo.valor)
            if nodo.valor == nodoBuscar:  # identifica si es el nodo que buscamos, se acaba la busqueda
                break
            else:
                if nodo.limite < limite:
                    for i in nodo.hijos:  # se hace la busqueda en profundidad por izquierda (sin "reversed" lo hace por la izquierda)
                        agenda.append(i)
    else:
        print("Error en el limite")
else:
    print("Error en la seleccion")
