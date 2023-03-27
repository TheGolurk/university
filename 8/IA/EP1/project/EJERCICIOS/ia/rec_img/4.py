# Practica 4: desenfoque gaussiano
import cv2

if __name__ == '__main__':
    imagen = cv2.imread("gato.jpg")
    imagen = cv2.medianBlur(imagen,  5)
    cv2.imshow("imagen gato", imagen)

    cv2.waitKey(0)
    cv2.destroyAllWindows()
