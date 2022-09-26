import math

n = int(input())

if n > 100:
    quit()

b = [0] * n

for i in range(n):
    b[i] = int(input())

b.reverse()

for i in range(n):
    print(int(math.pow(b[i], 2)))