#ACTIVIDAD DE CLASE
#BUSQUEDA PROFUNDIDAD Y ANCHURA

class arbol:
#CONSTRUCTOR 
  def __init__(self, valor):
    self.valor = valor
    self.hijos = []

#DEFINIR ÁRBOL N-ARIO
raiz = arbol("A")

#PRIMER NIVEL HIJOS DEL NODO RAÍZ A
raiz.hijos.append(arbol("B")) #HIJO EN ÍNDICE 0......SUCESIVAMENTE 
raiz.hijos.append(arbol("C")) 
raiz.hijos.append(arbol("D")) 


#HIJOS DEL NODO B(INDICE 0)
raiz.hijos[0].hijos.append(arbol("E"))#INDICE 0-.....SUCESIVAMENTE
raiz.hijos[0].hijos.append(arbol("F"))


#HIJOS DEL NODO C(INDICE 0)
raiz.hijos[1].hijos.append(arbol("I"))#INDICE 0-.....SUCESIVAMENTE
raiz.hijos[1].hijos.append(arbol("J"))

#HIJOS DEL NODO D(INDICE 2)
raiz.hijos[2].hijos.append(arbol("G"))#INDICE 0-.....SUCESIVAMENTE
raiz.hijos[2].hijos.append(arbol("H"))




#HIJOS DEL NODO E
raiz.hijos[0].hijos[0].hijos.append(arbol("I"))
raiz.hijos[0].hijos[0].hijos.append(arbol("J"))


#HIJOS DEL NODO F
raiz.hijos[0].hijos[1].hijos.append(arbol("K"))
raiz.hijos[0].hijos[1].hijos.append(arbol("L"))



#HIJOS DEL NODO G
raiz.hijos[2].hijos[0].hijos.append(arbol("M"))


#HIJOS DEL NODO H
raiz.hijos[2].hijos[0].hijos.append(arbol("L"))



agenda =[]
agenda.append(raiz)
nodoBuscar = "J"

while(agenda):
  nodo = agenda.pop()
  print("NODO VISITADO",nodo.valor)
  #si se encuentra se rompe el ciclo
  if (nodo.valor == nodoBuscar):
    break
  else:
    for i in reversed(nodo.hijos):
      agenda.append(i) #se agregan los sucesores