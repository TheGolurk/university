# Practica 8
import cv2

if __name__ == '__main__':
    imagen = cv2.imread("gato.jpg")
    imagen = cv2.cvtColor(imagen, cv2.COLOR_BGR2RGB)
    imagen = cv2.cvtColor(imagen, cv2.COLOR_BGR2XYZ)

    cv2.imshow("imagen gato", imagen)

    cv2.waitKey(0)
    cv2.destroyAllWindows()
