height = []
for i in range(9):
    height.append(int(input()))

for j in range(9):
    a = height[j]
    for k in range(j+1, 9):
        b = height[k]
        if sum(height)-a-b == 100:
            height.remove(a)
            height.remove(b)
            break
    if sum(height)==100:
        break

height.sort()

for n in height:
    print(n)