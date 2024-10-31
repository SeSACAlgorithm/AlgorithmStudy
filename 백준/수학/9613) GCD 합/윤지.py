import math
from itertools import combinations

n = int(input())

for _ in range(n):
    arr = list(map(int, input().split()))

    n = arr[0]
    numbers = arr[1:]

    answer = 0
    for a, b in combinations(numbers, 2):
        answer += math.gcd(a, b)

    print(answer)
