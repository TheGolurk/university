###PROGRAMA 5.2
###Implementación de perceptron con regla de aprendizaje para las tablas de verdad NOT, OR y AND

###FUNCIÓN NOT

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
  theta = valores[rnd.randint(0,4)]

  return w1,theta

##funcion del escalon
def F_escalon(x):
  if x >0:
    return 1
  else: 
    return -1


if __name__ == '__main__':

  X  = [-1, 1]
  dx = [1, -1]
  w1, theta = iniParametros()
  

  ##inicializar un for para poder recorrer los 4 opciones
  for i in range(2):
      #Evaluar función sigma o suma ponderada
      y = X[i] * w1
      x = y + theta
      y = F_escalon(x)
  
      if (y != dx[i]):
        while y != dx[i]:
          #calcular gradientes
          dw1 = dx[i] * X[i]
          #actualizar pesos ,moviendo un eje
          w1 += dw1
          theta += dx[i]
          y = X[i] * w1
          x = y + theta
          y = F_escalon(x)

      print(y)