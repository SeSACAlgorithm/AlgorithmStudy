N, M = map(int, input().split())
cards = list(map(int, input().split()))

max_sum = 0

for i in range(N):
    for j in range(i+1, N):
        for k in range(j+1, N):
            cur_sum = cards[i] + cards[j] + cards[k]
            if cur_sum <= M and cur_sum > max_sum:
                max_sum = cur_sum

print(max_sum)
