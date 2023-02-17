import numpy as np

def imprimir (matriz):
    for i in matriz:
        print(f"Valor: {i}")
        
def h_biencolocado(fx, s_meta):
    contador=0
    for i in range(3):
        for j in range(3):
            if fx[i][j]==s_meta[i][j]:
                contador+=1
    return contador

def h_biencolocado(fx, s_meta):
    contador=0
    for i in range(3):
        for j in range(3):
            if fx[i][j]==s_meta[i][j]:
                contador+=1
    return contador

s_actual=[[1,6,7], [2,5,8], [0,3,4]]

s_meta=[[1,6,7],[2,5,8],[3,4,0]]

#Definir vecinos
f0=np.zeros((3,3))
f1=np.zeros((3,3))
f2=np.zeros((3,3))
f3=np.zeros((3,3))

imprimir(s_actual)


if(s_actual[2][0]==0):
    #Generar dos vecinos
    f0=np.copy(s_actual)
    f1=np.copy(s_actual)
    temp=s_actual[1][0]
    f0[1][0]=f0[2][0]
    f0[2][0]=temp
    imprimir(f0)
    temp=s_actual[1][0]
    f1[1][0]=f1[2][0]
    f1[2][0]=temp
    imprimir(f1)

print(h_biencolocado)