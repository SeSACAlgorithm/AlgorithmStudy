N = int(input())

for M in range(1, N + 1):
    tmp = M + sum(map(int, str(M)))
    if tmp == N:
        print(M)
        break

    if M == N:
        print(0)
