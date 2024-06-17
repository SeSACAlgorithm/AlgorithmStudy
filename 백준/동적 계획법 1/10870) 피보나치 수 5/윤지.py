number = int(input())

arr = [0, 1]
for i in range(0, number+1):
    if i > 1:
        arr.append(arr[i-1] + arr[i-2])

print(arr[number])
