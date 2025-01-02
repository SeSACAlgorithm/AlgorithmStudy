n = int(input())
x = list(map(int, input().split()))

tot_sum = sum(x)
answer = 0

for i in range(n):
    tot_sum -= x[i]
    answer += x[i] * tot_sum

print(answer)
