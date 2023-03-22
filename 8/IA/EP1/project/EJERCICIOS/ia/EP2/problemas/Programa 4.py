###PROGRAMA 4
###Implementación de neurona de McCulloch-Pitts para la tabla de verdad NOT, OR y AND

##NOT
def neurona_NOT(x):
  #peso
  w = -1
  theta = -1

  #Regla de salida
  #Suma ponderada
  suma = x*w
  if suma>theta:
    return 1
  else:
    return 0

##OR
def neurona_OR(x1, x2):
  #pesos
  w1, w2 = 1,1 
  theta = 1

  #suma ponderada
  suma = x1*w1+x2*w2


  #Regla de salida
  if suma>theta:
    return 1
  else:
    return 0

##AND
def neurona_AND(x1, x2):
  #pesos
  w1, w2 = 1,1 
  theta = 1

  #suma ponderada
  suma = x1*w1+x2*w2


  #Regla de salida
  if suma>theta:
    return 1
  else:
    return 0



if __name__ == '__main__':
  print(neurona_NOT(1))
  print(neurona_OR(1,1))
  print(neurona_AND(1,1))
  
