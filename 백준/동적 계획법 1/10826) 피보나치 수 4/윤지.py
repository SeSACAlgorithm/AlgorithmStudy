number = int(input())

arr = [0, 1]

for i in range(2, number+1):
    arr.append(arr[i-2] + arr[i-1])

print(arr[number])
