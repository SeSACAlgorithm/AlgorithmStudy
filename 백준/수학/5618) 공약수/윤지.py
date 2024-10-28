import math

n = int(input())

# 최대공약수
if n == 2:
    a, b = map(int, input().split())
    tmp = math.gcd(a, b)
else:
    a, b, c = map(int, input().split())
    tmp = math.gcd(math.gcd(a, b), c)

arr = []
for i in range(1, int(math.sqrt(tmp)) + 1):
    if tmp % i == 0:
        arr.append(i)
        if i != tmp // i:
            arr.append(tmp//i)

arr.sort()
for a in arr:
    print(a)
