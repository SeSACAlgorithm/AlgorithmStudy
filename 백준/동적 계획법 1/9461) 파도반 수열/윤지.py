T = int(input())

for i in range(T):
    N = int(input())

    arr = [0, 1, 1]

    for j in range(N):
        nxt = arr[j] + arr[j + 1]
        arr.append(nxt)

    print(arr[N])


