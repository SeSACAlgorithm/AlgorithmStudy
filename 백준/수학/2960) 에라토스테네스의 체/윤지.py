N, K = map(int, input().split())

arr = [False] * (N+1)
chk = 0
for i in range(2, N+1):
    if not arr[i]:
        for j in range(i, N+1, i):
            if not arr[j]:
                arr[j] = True
                chk += 1
                if chk == K:
                    print(j)
