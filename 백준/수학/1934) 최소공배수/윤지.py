import math

T = int(input())
ans = []

for _ in range(T):
    A, B = map(int, input().split())

    lcm = A * B // math.gcd(A, B)
    ans.append(lcm)

for i in ans:
    print(i)
