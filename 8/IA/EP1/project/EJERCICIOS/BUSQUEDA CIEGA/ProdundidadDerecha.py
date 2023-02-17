#ALGORITMO DE BÚSQUEDA CIEGA: BÚSQUEDA EN PROFUNDIDAD POR DERECHA (BPderecha)

#CONSTRUCCIÓN DEL ÁRBOL N-ARIO ESTÁTICO


class arbol:
#CONSTRUCTOR 
  def __init__(self, valor):
    self.valor = valor
    self.hijos = []

#DEFINIR ÁRBOL N-ARIO
raiz = arbol(1)

#PRIMER NIVEL HIJOS DLE NODO RAÍZ
raiz.hijos.append(arbol(2)) #HIJO EN ÍNDICE 0......SUCESIVAMENTE 
raiz.hijos.append(arbol(3)) 
raiz.hijos.append(arbol(4)) 


#HIJOS DEL NODO 2(INDICE 0)
raiz.hijos[0].hijos.append(arbol(5))#INDICE 0-.....SUCESIVAMENTE
raiz.hijos[0].hijos.append(arbol(6))
raiz.hijos[0].hijos.append(arbol(7))

#HIJOS DEL NODO 4(INDICE 2)
raiz.hijos[2].hijos.append(arbol(8))#INDICE 0-.....SUCESIVAMENTE
raiz.hijos[2].hijos.append(arbol(9))


#HIJOS DEL NODO 5
raiz.hijos[0].hijos[0].hijos.append(arbol(10))

#HIJOS DEL NODO 7
raiz.hijos[0].hijos[2].hijos.append(arbol(11))
raiz.hijos[0].hijos[2].hijos.append(arbol(12))

#HIJOS DEL NODO 9
raiz.hijos[2].hijos[1].hijos.append(arbol(13))
raiz.hijos[2].hijos[1].hijos.append(arbol(14))

agenda =[]
agenda.append(raiz)
nodoBuscar = 7

while(agenda):
  nodo = agenda.pop()
  print("NODO VISITADO",nodo.valor)
  #si se encuentra se rompe el ciclo
  if (nodo.valor == nodoBuscar):
    break
  else:
    for i in reversed(nodo.hijos):
      agenda.append(i) #se agregan los sucesores

  #print(nodo.valor)
  

#NOTA, QUITAR EL REVERSED SI QUIERE RECORRER POR EL LADO CONTRARIO 