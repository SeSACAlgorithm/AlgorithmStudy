from math import gcd

N = int(input())
A = list(map(int, input().split()))
X = int(input())

total = 0
count = 0

for num in A:
    if gcd(num, X) == 1:
        total += num
        count += 1

print(total / count)
