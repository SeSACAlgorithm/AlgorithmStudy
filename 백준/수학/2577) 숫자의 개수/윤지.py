A = int(input())
B = int(input())
C = int(input())

tmp = str(A * B * C)
arr = [0] * 10

for t in tmp:
    for a in range(len(arr)):
        if a == int(t):
            arr[a] += 1

for a in arr:
    print(a)

