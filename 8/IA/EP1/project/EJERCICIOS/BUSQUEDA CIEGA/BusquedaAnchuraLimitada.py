#ALGORITMO DE BÚSQUEDA ANCHURA: BÚSQUEDA ANCHURA LIMITADA (BPL)

#NODO =12 , LIMITE =2  LADO:IZQUIERDO

class arbol:
  def __init__(self, valor,limite):
    self.valor = valor
    self.limite = limite
    self.hijos = []

#DEFINIR ÁRBOL N-ARIO
raiz = arbol(1,0)

#PRIMER NIVEL HIJOS DLE NODO RAÍZ
raiz.hijos.append(arbol(2,1)) #HIJO EN ÍNDICE 0......SUCESIVAMENTE 
raiz.hijos.append(arbol(3,1)) 
raiz.hijos.append(arbol(4,1)) 



####LIMITE 2
#HIJOS DEL NODO 2(INDICE 0)
raiz.hijos[0].hijos.append(arbol(5,2))#INDICE 0-.....SUCESIVAMENTE
raiz.hijos[0].hijos.append(arbol(6,2))
raiz.hijos[0].hijos.append(arbol(7,2))

#HIJOS DEL NODO 4(INDICE 2)
raiz.hijos[2].hijos.append(arbol(8,2))#INDICE 0-.....SUCESIVAMENTE
raiz.hijos[2].hijos.append(arbol(9,2))




####LIMITE 3
#HIJOS DEL NODO 5
raiz.hijos[0].hijos[0].hijos.append(arbol(10,3))

#HIJOS DEL NODO 7
raiz.hijos[0].hijos[2].hijos.append(arbol(11,3))
raiz.hijos[0].hijos[2].hijos.append(arbol(12,3))

#HIJOS DEL NODO 9
raiz.hijos[2].hijos[1].hijos.append(arbol(13,3))
raiz.hijos[2].hijos[1].hijos.append(arbol(14,3))


agenda =[]
agenda.append(raiz)
nodoBuscar = 12
limite = 2
#limiteExp = 2


#BUSQUEDA PROFUNDA LIMITADA
while(agenda):
  nodo = agenda.pop()
  print("NODO VISITADO",nodo.valor)
  if (nodo.limite == limite):
    #if (nodo.valor == nodoBuscar):
      break
  else:
    #if (nodo.limite <limiteExp):
    for i in reversed(nodo.hijos):
      agenda.append(i) #se agregan los sucesores

  #print(nodo.valor)