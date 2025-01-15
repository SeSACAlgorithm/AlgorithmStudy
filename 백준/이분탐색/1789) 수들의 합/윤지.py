S = int(input())
tot = 0
answer = 0

for i in range(1, S+1):
    if tot + i <= S:
        tot += i
        answer = i
    else:
        break

print(answer)
