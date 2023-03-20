from keras.models import Sequential
from keras.layers.core import Dense
import numpy

entrada = numpy.array([0, 0],
                      [0, 1],
                      [1, 0],
                      [1, 1])

salida = numpy.array([[0],
                      [1],
                      [1],
                      [0]])

modelo = Sequential()

# Arquitecura red neuronal
# Definir entrada con primera capa oculta
modelo.add(Dense(8, input_dim=2,
                 kernel_initializer='uniform', activation='relu'))

modelo.add(Dense(8, kernel_initializer='uniform', activation='relu'))

# Capa de salida
modelo.add(Dense(1, activation='sigmoid'))

# Entrenar la red neuronal y establecer parametros de entrenamiento
modelo.compile(loss='mean_squared_error', optimizer='adam', metrics=['binary_accuracy'])

modelo.fit(entrada, salida, epochs=10)

score = modelo.evaluate(entrada, salida)

print(score[0])

out = modelo.predict(entrada).round()
print(out)
