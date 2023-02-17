#Algoritmo de búsqueda ciega: Búsqueda en profundidad por derecha (BPder)

#Contrucción del árbol n-ario estático

class arbol:
    def __init__(self,valor):
        self.valor = valor
        self.hijos = []


#Definir árbol n-ario
#Nodo raiz
raiz = arbol('A')

#Hijos del nodo raiz
#Se agregaran hijos al nodo
raiz.hijos.append(arbol('B')) #Hijo en índice 0
raiz.hijos.append(arbol('C')) #Hijo en índice 1
raiz.hijos.append(arbol('D')) #Hijo en índice 2

#agregar hijos del nodo 2 (indice 0)
raiz.hijos[0].hijos.append(arbol('E')) #Hijo del nodo 2, índice 0
raiz.hijos[0].hijos.append(arbol('F')) #Hijo del nodo 2, índice 1



#Agregar hijos del nodo 3 (indice 1)
raiz.hijos[1].hijos.append(arbol('I')) #Hijo del nodo 3, índice 0
raiz.hijos[1].hijos.append(arbol('J')) #Hijo del nodo 3, índice 1

#agregar hijos del nodo 4 (indice 2)
raiz.hijos[2].hijos.append(arbol('G')) #Hijo del nodo 4, índice 0
raiz.hijos[2].hijos.append(arbol('H')) #Hijo del nodo 4, índice 1

#agregar hijos del nodo 5 (indice 0)
raiz.hijos[0].hijos[0].hijos.append(arbol('I')) #Hijo del nodo 5, índice 0
raiz.hijos[0].hijos[0].hijos.append(arbol('J'))

#agregar hijos del nodo 6 (indice 1)
raiz.hijos[0].hijos[1].hijos.append(arbol('K'))
raiz.hijos[0].hijos[1].hijos.append(arbol('L'))

#agregar hijos del nodo 9 (indice 0)
raiz.hijos[2].hijos[0].hijos.append(arbol('M'))

#agregar hijos del nodo 10 (indice 1)
raiz.hijos[2].hijos[1].hijos.append(arbol('L'))



agenda=[]
agenda.append(raiz)
nodoBuscar = 'J'
while(agenda):
    nodo = agenda.pop(0)#Se sacan
    print("Nodo visitado",nodo.valor)
    if (nodo.valor == nodoBuscar):
        break
    else:
#al poner reversed se cambiara de lado e ira a la izquierda
      for i in (nodo.hijos):
        agenda.append(i)

    print(nodo.valor)