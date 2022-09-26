import sys

a,b,c = map(int,sys.stdin.readline().split())

sum = a+b
res = a-b
div = a/b
mul = a*b

finalRes = "D:"

if sum == c:
    finalRes = "+"
if res == c:
    finalRes = "-"
if div == c:
    finalRes = "/"
if mul == c:
    finalRes = "*"

print(finalRes)