import math

M = int(input())
N = int(input())
answer = []

for i in range(M, N+1):
    if i == 1:
        continue
    chk = True
    for a in range(2, int(math.sqrt(i)) + 1):
        if i % a == 0:
            chk = False
            break
    if chk:
        answer.append(i)

if len(answer) == 0:
    print(-1)
else:
    print(sum(answer))
    print(min(answer))





