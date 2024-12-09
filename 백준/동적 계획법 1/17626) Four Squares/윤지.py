import math

def four_squares(n):
    # 제곱수
    if int(math.sqrt(n))**2 == n:
        return 1

    # 두 제곱수
    for i in range(1, int(math.sqrt(n)) + 1):
        if int(math.sqrt(n - i**2))**2 == n - i**2:
            return 2

    # 세 제곱수
    for i in range(1, int(math.sqrt(n)) + 1):
        for j in range(1, int(math.sqrt(n - i**2)) + 1):
            if int(math.sqrt(n - i**2 - j**2))**2 == n - i**2 - j**2:
                return 3

    # 네 제곱수
    return 4

n = int(input())
print(four_squares(n))
