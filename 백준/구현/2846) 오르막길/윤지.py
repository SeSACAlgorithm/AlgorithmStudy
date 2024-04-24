N = int(input())
arr = list(map(int, input().split()))

maxDiff = 0
tmpDiff = 0
start = arr[0]
for i in range(1, N):
    # 오르막길
    if arr[i] > start and arr[i] != arr[i-1]:
        tmpDiff += arr[i] - start
        #print(f"Diff : {tmpDiff}")
    # 내리막길
    else:
        tmpDiff = 0
        #print(f"Start : {start}")
    maxDiff = max(maxDiff, tmpDiff)
    start = arr[i]

print(maxDiff)


