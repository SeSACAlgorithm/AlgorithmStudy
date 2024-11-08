T = int(input())

arr_0 = [0] * 41
arr_1 = [0] * 41

arr_0[0] = 1
arr_0[1] = 0
arr_1[0] = 0
arr_1[1] = 1

for i in range(2, 41):
    arr_0[i] = arr_0[i - 1] + arr_0[i - 2]
    arr_1[i] = arr_1[i - 1] + arr_1[i - 2]

for _ in range(T):
    N = int(input())
    print(arr_0[N], arr_1[N])

