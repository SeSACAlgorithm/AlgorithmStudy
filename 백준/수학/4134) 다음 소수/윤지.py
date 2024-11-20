import math

def prime(number):
    if number < 2:
        return False
    for i in range(2, int(math.sqrt(number)) + 1):
        if number % i == 0:
            return False
    return True

t = int(input())

answers = []

for _ in range(t):
    n = int(input())

    while not prime(n):
        n += 1
    answers.append(n)

for answer in answers:
    print(answer)
