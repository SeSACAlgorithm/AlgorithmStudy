N = int(input())

drinks = list(map(int, input().split()))
drinks.sort(reverse=True)

answer = drinks[0]
for i in range(1,N):
    answer += drinks[i] / 2
print(answer)
