###PROGRAMA 5.3
###Implementación de perceptron con regla de aprendizaje para las tablas de verdad NOT, OR y AND

###FUNCION OR

## 1.-INICIALIZAR PESOS(W) Y THETA
## 2.-EVALUAR LOS PATRONES DE ENTRADA
## 3.- PREGUNTAR SI Y != dx
## SI SE CUMPLE: Actualizar pesos y theta gradientes
## SI NO SE CUMPLE: No se hace nada
## REPETIR PASO 2, HASTA QUE CADA Y = dx



import random as rnd
import numpy as np

def iniParametros():
  valores =[-1, -0.5, 0, 0.5, 1]

  w1 = valores[rnd.randint(0,4)]
  w2 = valores[rnd.randint(0,4)]
  theta = valores[rnd.randint(0,4)]

  return w1,w2,theta

##funcion del escalon
def F_escalon(x):
  if x >0:
    return 1
  else: 
    return -1


if __name__ == '__main__':

  X = [[-1,-1],
       [-1,1],
       [1, -1],
       [1,1]]
  dx = [-1,1,1,1]

  w1, w2, theta = iniParametros()
  print(w1,w2,theta)

  ##inicializar un for para poder recorrer los 4 opciones
  for i in range(4):
    for k in range(1):
      #Evaluar función sigma o suma ponderada
      y = X[i][k]*w1+X[i][k+1]*w2
      x = y + theta
      y = F_escalon(x)
    
      if (y != dx[i]):
        while y != dx[i]:
          #calcular gradientes
          dw1 = dx[i] * X[i][k]
          #actualizar pesos , moviendo un eje
          w1=w1+dw1
          dw2 = dx[i]*X[i][k+1]
          w2=w2+dw2

          theta = theta +dx[i]
          y = (X[i][k] * w1 + X[i][k+1] * w2)
          x = y + theta
          y = F_escalon(x)


          #print(w1,w2,theta)

    print(y)

