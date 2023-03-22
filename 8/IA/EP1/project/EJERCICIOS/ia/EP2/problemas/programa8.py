import numpy as np
from keras.models import Sequential
from keras.layers.core import Dense
import numpy

entrada = numpy.array([[0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                        0, 1, 1, 1, 0, 0, 1, 1, 1, 0,
                        1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                        1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                        0, 1, 1, 1, 0, 0, 1, 1, 1, 0,
                        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                        0, 0, 0, 0, 0, 0, 0, 0, 0, 0],  # 0,0
                       [0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                        0, 0, 1, 1, 1, 1, 1, 1, 0, 0,
                        0, 0, 1, 1, 1, 1, 1, 1, 1, 0,
                        1, 1, 1, 1, 1, 0, 0, 0, 1, 0,
                        0, 0, 1, 1, 1, 0, 0, 0, 1, 1,
                        1, 1, 1, 1, 1, 0, 0, 0, 1, 0,
                        0, 0, 1, 1, 1, 1, 1, 1, 1, 0,
                        0, 0, 1, 1, 1, 1, 1, 1, 0, 0,
                        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                        ],  # [0,1]
                       [0, 1, 1, 1, 1, 1, 1, 1, 1, 0,
                        0, 0, 1, 1, 1, 1, 1, 1, 0, 0,
                        0, 0, 1, 1, 1, 1, 1, 1, 0, 0,
                        0, 0, 0, 1, 1, 1, 1, 0, 0, 0,
                        0, 0, 0, 0, 1, 1, 0, 0, 0, 0,
                        0, 0, 0, 0, 1, 1, 0, 0, 0, 0,
                        0, 0, 0, 0, 1, 1, 0, 0, 0, 0,
                        0, 0, 0, 0, 1, 1, 0, 0, 0, 0,
                        0, 0, 0, 0, 1, 1, 0, 0, 0, 0,
                        0, 0, 0, 1, 1, 1, 1, 0, 0, 0,
                        ]]  # [1,1]
                      )


def predict_image(modelo, image):
    out = modelo.predict(image).round().astype(int)

    for i in range(out.shape[0]):
        if out[i][0] == 0 and out[i][1] == 0:
            print("Lentes")
        elif out[i][0] == 0 and out[i][1] == 1:
            print("Cohete")
        elif out[i][0] == 1 and out[i][1] == 1:
            print("Copa")
        else:
            print("No reconocido")


if __name__ == '__main__':
    salida = numpy.array([[0, 0],
                          [0, 1],
                          [1, 1]])

    modelo = Sequential()

    modelo.add(Dense(8, input_dim=100,
                     kernel_initializer='uniform', activation='relu'))

    modelo.add(Dense(8, kernel_initializer='uniform', activation='relu'))

    # Capa de salida
    modelo.add(Dense(2, activation='sigmoid'))

    # Entrenar la red neuronal y establecer parametros de entrenamiento
    modelo.compile(loss='mean_squared_error', optimizer='adam', metrics=['binary_accuracy'])

    modelo.fit(entrada, salida, epochs=160)

    score = modelo.evaluate(entrada, salida)

    print(score[0])

    # Copa
    copa = np.array([[0, 1, 1, 1, 1, 1, 1, 1, 1, 0,
                      0, 0, 1, 1, 1, 1, 1, 1, 0, 0,
                      0, 0, 1, 1, 1, 1, 1, 1, 0, 0,
                      0, 0, 0, 1, 1, 1, 1, 0, 0, 0,
                      0, 0, 0, 0, 1, 1, 0, 0, 0, 0,
                      0, 0, 0, 0, 1, 1, 0, 0, 0, 0,
                      0, 0, 0, 0, 1, 1, 0, 0, 0, 0,
                      0, 0, 0, 0, 1, 1, 0, 0, 0, 0,
                      0, 0, 0, 0, 1, 1, 0, 0, 0, 0,
                      0, 0, 0, 1, 1, 1, 1, 0, 0, 0,
                      ]])

    # lentes
    lentes = np.array([[0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                        0, 1, 1, 1, 0, 0, 1, 1, 1, 0,
                        1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                        1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                        0, 1, 1, 1, 0, 0, 1, 1, 1, 0,
                        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                        0, 0, 0, 0, 0, 0, 0, 0, 0, 0
                        ]])

    # Cohete
    cohete = np.array([[0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                        0, 0, 1, 1, 1, 1, 1, 1, 0, 0,
                        0, 0, 1, 1, 1, 1, 1, 1, 1, 0,
                        1, 1, 1, 1, 1, 0, 0, 0, 1, 0,
                        0, 0, 1, 1, 1, 0, 0, 0, 1, 1,
                        1, 1, 1, 1, 1, 0, 0, 0, 1, 0,
                        0, 0, 1, 1, 1, 1, 1, 1, 1, 0,
                        0, 0, 1, 1, 1, 1, 1, 1, 0, 0,
                        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                        ]])

    predict_image(modelo, lentes)
    predict_image(modelo, cohete)
    predict_image(modelo, copa)
