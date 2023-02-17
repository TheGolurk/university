#Algoritmo de búsqueda ciega: Búsqueda en profundidad por derecha (BPder)

#Contrucción del árbol n-ario estático

class arbol:
    def __init__(self,valor):
        self.valor = valor
        self.hijos = []


#Definir árbol n-ario
#Nodo raiz
raiz = arbol(1)

#Hijos del nodo raiz
#Se agregaran hijos al nodo
raiz.hijos.append(arbol(2)) #Hijo en índice 0
raiz.hijos.append(arbol(3)) #Hijo en índice 1
raiz.hijos.append(arbol(4)) #Hijo en índice 2

#agregar hijos del nodo 2 (indice 0)
raiz.hijos[0].hijos.append(arbol(5)) #Hijo del nodo 2, índice 0
raiz.hijos[0].hijos.append(arbol(6)) #Hijo del nodo 2, índice 1
raiz.hijos[0].hijos.append(arbol(7)) #Hijo del nodo 2, índice 2


#Agregar hijos del nodo 4 (indice 2)
raiz.hijos[2].hijos.append(arbol(8)) #Hijo del nodo 4, índice 0
raiz.hijos[2].hijos.append(arbol(9)) #Hijo del nodo 4, índice 1

#agregar hijos del nodo 5 (indice 0)
raiz.hijos[0].hijos[0].hijos.append(arbol(10)) #Hijo del nodo 5, índice 0


#agregar hijos del nodo 7 (indice 2)
raiz.hijos[0].hijos[2].hijos.append(arbol(11))
raiz.hijos[0].hijos[2].hijos.append(arbol(12))

#agregar hijos del nodo 9
raiz.hijos[2].hijos[1].hijos.append(arbol(13))
raiz.hijos[2].hijos[1].hijos.append(arbol(14))



agenda=[]
agenda.append(raiz)
nodoBuscar = 7
while(agenda):
    nodo = agenda.pop()#Se sacan
    print("Nodo visitado",nodo.valor)
    if (nodo.valor == nodoBuscar):
        break
    else:
#al poner reversed se cambiara de lado e ira a la izquierda
      for i in reversed(nodo.hijos):
        agenda.append(i)

    print(nodo.valor)