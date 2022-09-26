import sys

n = int(input())

b = []
c = []

b = sys.stdin.readline().split()
c = sys.stdin.readline().split()
bb = [eval(i) for i in b]
cc = [eval(i) for i in c]

for i in range(len(bb)):
    print(bb[i] + cc[i], end =" ")
