import sys 
n = int(sys.stdin.readline())
res = 1

for i in range(1,n+1):
    res *= i

print(res)