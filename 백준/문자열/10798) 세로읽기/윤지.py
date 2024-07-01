arr = [list(input()) for _ in range(5)]

result = []

for i in range(15):
    for j in range(5):
        if i < len(arr[j]):
            result.append(arr[j][i])

print(''.join(result))
