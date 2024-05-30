line = int(input())

Axis = []
for i in range(0, line):
    x, y = map(int, input().split())

    Axis.append((x, y))

sortedAxis = sorted(Axis)

#print(sortedAxis)

for dot in sortedAxis:
    print(*dot)
