import random as rnd


def generarPoblacion():
  poblacion= np.zeros((8,6))
  for i in range(8):
      for j in range(6):
        x=-5+rnd.random()*10
        poblacion[i][j]=x
  return poblacion


def torneo(poblacion,fitness):
    pobTorneo = []
    
    for i in range(8):
        ind1,ind2 = 0,0
        while(ind1==ind2):
            ind1 = 

    
    return []


def cruza_puntos(poblacion):
    random.randint()
    
    return cruza


def muta_aleatorio(poblacion):
    return []

def obtener_fitness():
    return 0

if __name__ == '__main__':
    generaciones = 200
    fitlim = 0.5
    n_gen = 1
    fitness = 1

    while(generaciones < n_gen  or fitness < fitlim):
        poblacion = initPob()
        fitness = obtener_fitness(poblacion)
        poblacion = torneo(poblacion)
        poblacion = cruza_puntos(poblacion)
        poblacion = muta_aleatorio(poblacion)
        n_gen += 1
    