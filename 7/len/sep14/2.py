n = int(input())

Celsius = (n - 32) * 5/9

friacaliente = 0

if Celsius <= 36:
    friacaliente = 0
elif Celsius > 36:
    friacaliente = 1

print("{} {}".format(int(Celsius), friacaliente))