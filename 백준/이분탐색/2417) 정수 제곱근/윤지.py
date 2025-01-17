import math

n = int(input())
a = math.isqrt(n)

if a ** 2 != n:
    a += 1

print(int(a))
