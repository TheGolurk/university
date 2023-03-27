# Practica 8
import cv2

if __name__ == '__main__':
    imagen = cv2.imread("gato.jpg")
    imagen = cv2.cvtColor(imagen, cv2.COLOR_BGR2GRAY)
    sobelx = cv2.Sobel(imagen, cv2.CV_64F, dx=1, dy=0,ksize=5)
    sobely = cv2.Sobel(imagen, cv2.CV_64F, dx=0, dy=1,ksize=5)
    sobelxy = cv2.Sobel(imagen, cv2.CV_64F, dx=1, dy=1,ksize=5)


    cv2.imshow("imagen gato", sobelx)
    cv2.imshow("imagen gato1", sobely)
    cv2.imshow("imagen gato2", sobelxy)



    cv2.waitKey(0)
    cv2.destroyAllWindows()