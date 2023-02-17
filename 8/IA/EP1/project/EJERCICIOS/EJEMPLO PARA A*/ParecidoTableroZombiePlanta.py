##EJEMPLO PARECIDO PARA HACER EL EJERCICIO DE LA PLANTA CON EL DE ZOMBIES DE LA EP1


import numpy as np
import math as mt


vertical = 2
horizontal=1

#Definición del tablero inicial
tablero = np.array([["l","l","o","l","l"],
                   ["l","l","l","obs","obs"],
                   ["l","obs","l","l","l"],
                   ["r","obs","l","i","l"],
                   ["l","l","l","l","l"]
                   ])

#uscar objetos en el tablero
def buscarObjeto(tablero,objeto):
    for i in range(5):
        for j in range(5):
            if tablero[i,j]==objeto:
                return i,j
            

def distanciaManhattan(f0,basura):
    DM = mt.fabs(f0[0]-basura[0])+ mt.fabs(f0[1]-basura[1])
    return DM
    

basura=np.array(buscarObjeto(tablero,"o"))
robot=np.array(buscarObjeto(tablero,"r"))
#print(basura)
#print(robot)
            
#calcular función de costo de los vecinos

# f0
f0 =[0,0]
f0_costo= 0

f0[0]=robot[0]-1
f0[1]=robot[1]

print("Vecino f0",f0)
print("Basura organica",basura)
DM = distanciaManhattan(f0,basura)

f0_costo = vertical + DM
print(f0_costo) 
