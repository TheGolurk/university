n = int(input())

count = 0

def numero_primo(numero):
    if numero == 0 or numero == 1 or numero == 4:
        return False
    for x in range(2, int(numero/2)):
        if numero % x == 0:
            return False
    return True

for i in range(n):
    if numero_primo(i):
        count = count + 1
    else:
        continue

if count == 0:
    print("No existen numeros primos en la cantidad ingresada.")
else:
    print(count)