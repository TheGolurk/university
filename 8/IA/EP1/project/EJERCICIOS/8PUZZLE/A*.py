import numpy as np
#Inicializar arreglos
meta=[[1,2,3],[8,0,4],[7,6,5]]
inicial = np.empty((3,3))

#Solucion inicial
def impresion_inicial():
    print("Solucion Inicial")
    for j in range(0,3):
        for i in range(0,3):
            print(f"Valor [{j}][{i}]:{inicial[j][i]}")

def impresion_final():
    #Solucion Final
    print("Solucion Final")
    for j in range(0,3):
        for i in range(0,3):
            print(f"Valor [{j}][{i}]:{meta[j][i]}")

def vaciado():
    print("Solucion Inicial:")
    impresion_inicial()
    for j in range(0,3):
        for i in range(0,3):
            inicial[j][i]=None
    impresion_inicial()

#Pedir datos al usuario
def datos():
    val=True
    num=2
    vaciado()
    while val:
        try:#tolerancia a errores de usuario
            for i in range(0,3):#recorrer todos los lugares 
                for j in range(0,3):
                    num=int(input(f"Inserta el numero de la posicion: [{i}][{j}]: "))
                    while valid(num)==1: 
                        num=int(input(f"Inserta el numero de la posicion: [{i}][{j}]: "))
                        if valid(num)==1:
                            print("No se aceptan numeros repetidos, vuelve a intentarlo")
                        elif valid(num)==2:
                            print("No se aceptan valoresfuera del rango (0-8), vuelve a intentarlo")
                        else:
                            pass
                    inicial[i][j]=num
            val=False
        except Exception as e:
            print(f"ERROR de tipo ({e}), volviendo a intentar...")
            print("Matriz inicial: ")
            impresion_inicial()
            vaciado()
            val=True


#Valida los datos del usuario
def valid(num1):
    if (num1>=0 and num1<9):
        for i in range(0,3):
            for j in range(0,3):
                if num1==inicial[i][j]:
                    return 1
        return 0
    else:
        return 2
    
#Calculo de manhattan
def manhattan(x1, y1, x2, y2):
    return abs(x1 - x2) + abs(y1 - y2)    

#Validacion de posiciones
def val_pos():
    for j in range(0,3):
        for i in range(0,3):
           if inicial[j][i]==meta[j][i]:
               pass
           else:
               correcion() 

#Correccion de posiciones
def correcion():
    iauxi=0#variables auxiliares
    iauxj=0
    fauxi=0
    fauxj=0
    valaux=0
    for i in range(0,3):#recorrido para verificar valores
        for j in range(0,3):
            if inicial[i][j]==meta[i][j]:#si son correctos deja el valor predefinido de la solucion
                print(f"Posicion correcta: [{i}][{j}]: {inicial[i][j]}")
            else:#sino realiza la operacion de intercambio
                valaux=inicial[i][j]#recopilamos el valor inicial junto a sus coordenadas
                iaxui=i
                iauxj=j
                for l in range(0,3):#realizamos otro recorrido para verificar la casilla faltante
                    for k in range(0,3):
                        if meta[l][k]==valaux:#una vez encontrado el valor y la posicion correcta la guardamos
                            fauxi=l
                            fauxj=k
                            print(f"Valor encontrado en casilla [{l}][{k}]: {meta[l][k]}")
                            print(f"Valor manhattan: {manhattan(iauxj, iauxi, fauxj, fauxi)}")
                            inicial[iaxui][iauxj]=inicial[fauxi][fauxj]#Intercambiamos posicion
                            inicial[fauxi][fauxj]=valaux
                            impresion_inicial()
                            val_pos()

datos()
correcion()
print("Comparacion Inicial")
impresion_inicial()
print("Comparacion final")
impresion_final()


