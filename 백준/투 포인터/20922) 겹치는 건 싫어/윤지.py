N, K = map(int, input().split())

Nums = list(map(int, input().split()))

# 빈도 수
dict = {}

front, answer = 0, 0

for end in range(N):
    # 빈도 수
    num = Nums[end]
    dict[num] = dict.get(num, 0) + 1
    #print(dict)

    # k 조건 만족
    while dict[num] > K:
        dict[Nums[front]] -= 1
        if dict[Nums[front]] == 0:
            del dict[Nums[front]]
        front += 1

    #print(Nums[front:end+1])
    answer = max(answer, end-front+1)


print(answer)
