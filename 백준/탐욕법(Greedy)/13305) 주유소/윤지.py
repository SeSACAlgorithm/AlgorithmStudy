N = int(input())  

road = list(map(int, input().split()))  
oil = list(map(int, input().split()))  

answer = 0
tmp = oil[0]

for i in range(N - 1):
    answer += tmp * road[i]
    tmp = min(tmp, oil[i + 1])

print(answer)
