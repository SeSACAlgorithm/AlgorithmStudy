T = int(input())

for i in range(T):
    n = int(input())

    arr = [1, 2, 4]

    for j in range(2, n):
        nxt = arr[j-2] + arr[j-1] + arr[j]
        arr.append(nxt)

    print(arr[n-1])
