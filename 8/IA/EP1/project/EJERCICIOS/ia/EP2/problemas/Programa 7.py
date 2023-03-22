###PROGRAMA 7

###PERCEPTRON MULTICAPA PARA FIGURAS GEOMETRICAS
##CUADRADO Y TRIANGULO


from keras.models import Sequential
from keras.layers.core import Dense
import numpy as np

#PATRONES DE ENTRADA
entrada = np.array([[1,1,1,1,1,1,
                    1,0,0,0,0,1, 
                    1,0,0,0,0,1, 
                    1,0,0,0,0,1,
                    1,0,0,0,0,1,
                    1,1,1,1,1,1],  #0,0
                    [0,0,0,0,0,0,
                     0,0,1,1,0,0,
                     0,1,0,0,1,0,
                     1,1,1,1,1,1,
                     0,0,0,0,0,0,
                     0,0,0,0,0,0]]) #1,1

#SALIDA
salida = np.array([[0,0],
                   [1,1]])

modelo = Sequential()

#DEFINIR LA ARQUITECTURA DE LA FUCKING RED NEURONAL

#DEFINIR ENTRADA CON PRIMERA CAPA OCULTA
modelo.add(Dense(8,input_dim=36,kernel_initializer='uniform',activation='relu'))

modelo.add(Dense(8,kernel_initializer='uniform',activation='relu'))

#CAPA DE SALIDA
modelo.add(Dense(2,activation='sigmoid'))


#ENTRENAR LA RED NEURONAL Y ESTABLECER PARAMETROS DE ENTRENAMIENTO
modelo.compile(loss='mean_squared_error',optimizer='adam',metrics=['binary_accuracy'])

modelo.fit(entrada,salida,epochs=30)

score =modelo.evaluate(entrada,salida)

print(score[0])

test = np.array([[1,1,1,1,1,1,
                  1,0,0,0,0,1, 
                  1,0,0,0,0,1, 
                  1,0,0,0,0,1,
                  1,0,0,0,0,1,
                  1,1,1,1,1,1]])

out = modelo.predict(test).round()
print(out)


if (out[0][0] ==0 and out[0][1]==0):
  print("CUADRADO")
else:
  print("TRIÁNGULO")



