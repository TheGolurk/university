n = int(input())
count = 0

if n % 2 == 0:
    n /= 2
    count += 1
else:
    n += 1
    count += 1

digits = len(str(n))
if digits == 2:
    n /= 10
    count += 1
elif digits >= 3:
    n /= 100
    count += 1

if n % 3 == 0:
    n -= 1
    count += 1

print(n, count)
