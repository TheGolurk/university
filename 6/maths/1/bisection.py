import matplotlib.pyplot as plt
import numpy as np

# function es la funcion dada
def function(x):
    return pow(x,10)-1

def bisection(x0, x1, e):
    paso = 1
    paro = True
    x2Anterior = 0
    while paro:
        x2 = (x0 + x1)/2
        print('Iteration %d, x2 = %0.6f and f(x2) = %0.6f' % (paro, x2, function(x2)))

        evaluacionValor = function(x0) * function(x2)


        errorAproximado = 0
        # vemos si es menor al error
        if paso == 1:
            errorAproximado = 100
        else:
           # errorAproximado =  abs( ( (function(x2)-function(x0)) / function(x2) ) * 100 ) 
            errorAproximado =   (( x2-x2Anterior) / x2 ) * 100


        plt.plot(x2,errorAproximado, 'ro' )

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

def f(x):
    return x

x = np.arange(-100,100)
y = f(x)

#plt.plot( x, y, 'b' )

plt.axhline(0,color='black')
plt.axvline(0,color='black')

plt.minorticks_on()
plt.grid( True, 'minor', markevery=2, linestyle='--' )
plt.grid( True, 'major', markevery=10 )


if function(x0) * function(x1) > 0.0:
    print("no se puede con estos valores")
else:
    bisection(x0, x1, e)
    plt.show()