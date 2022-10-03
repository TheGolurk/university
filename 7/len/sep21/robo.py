import math
import sys

a,b = map(int,sys.stdin.readline().split())
b = b - 1

a = a / 2
res = a
if res % 2 != 0:
    res = math.ceil(res)
    a = math.ceil(a)-1


banda_tam = a / b
if isinstance(banda_tam, float) and a % b != 0:
    tmp = banda_tam - math.floor(banda_tam)
    res += math.ceil(tmp * b)

print("{}".format(math.ceil(res)))