N = int(input())
for i in range(N):
    ans = list(input())
    score = 0
    total_score = 0
    for j in ans:
        if j == 'O':
            score += 1
            total_score += score
        else:
            score = 0
    print(total_score)

