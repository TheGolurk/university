import matplotlib.pyplot as plt
import numpy as np

# function es la funcion dada
def function(x):
    return pow(x,10)-1

def falsaP(x0, x1, e):
    paso = 1
    paro = True
    x2Anterior = 0
    while paro:
        sup = function(x1) * (x0 - x1) 
        inf = function(x0) - function(x1)
        x2 = x1 - ( sup  /  inf )
        
        evaluacionValor = function(x0) * function(x2)

        errorAproximado = 0
        # vemos si es menor al error
        if paso == 1:
            errorAproximado = 100
        else:
           # errorAproximado =  abs( ( (function(x2)-function(x0)) / function(x2) ) * 100 ) 
            errorAproximado =   (( x2-x2Anterior) / x2 ) * 100

        print("{:<10} {:<10.2f} {:<10.2f} {:<10.2f} {:<10.2f}".format(paso,x0, x1, x2, errorAproximado))

        plt.plot(x2,errorAproximado, 'bo' )

        paso += 1

        if evaluacionValor < 0:
            x1 = x2
        elif evaluacionValor > 0:
            x0 = x2
        elif evaluacionValor == 0:
            return

        x2Anterior = x2

        paro = errorAproximado > e

x0 = 0
x1 = 1.3
e = 5.0

x = np.arange(-75,75)
y = function(x)

plt.plot( x, y, 'b' )

plt.axhline(0,color='black')
plt.axvline(0,color='black')

plt.minorticks_on()
plt.grid( True, 'minor', markevery=2, linestyle='--' )
plt.grid( True, 'major', markevery=10 )

if function(x0) * function(x1) > 0.0:
    print("no se puede con estos valores")
else:
    print ("{:<10} {:<10} {:<10} {:<10} {:<10} ".format('Iteracion','xl', 'xu', 'xr', 'Ea'))
    falsaP(x0, x1, e)
    plt.show()