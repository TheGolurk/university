n = int(input())

b = [0] * n
positions = []
lastRes = 0

for i in range(len(b)):
    b[i] = int(input())
    if b[i] % 3 == 0 and b[i] != 0:
        lastRes += 1
        positions.append(i + 1)

if lastRes > 0:
    print(lastRes)
    for i in range(len(positions)):
        print(positions[i], end =" ")
else:
    print("no hay triples")