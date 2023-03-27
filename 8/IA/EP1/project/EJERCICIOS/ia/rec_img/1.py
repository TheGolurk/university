# Practica 1: mostrar imagen
import cv2

if __name__ == '__main__':
    imagen = cv2.imread("gato.jpg")
    cv2.imshow("imagen gato", imagen)

    cv2.waitKey(0)
    cv2.destroyAllWindows()
