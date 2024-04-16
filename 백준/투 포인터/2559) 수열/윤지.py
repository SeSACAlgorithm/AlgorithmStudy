N, K = map(int,input().split())
arr = list(map(int, input().split()))

sumNum = sum(arr[:K])
maxNum = sumNum

for j in range(K, N):
    sumNum = sumNum - arr[j-K] + arr[j]
    maxNum = max(sumNum, maxNum)

print(maxNum)
