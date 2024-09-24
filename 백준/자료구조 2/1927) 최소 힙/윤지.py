import heapq
import sys

input = sys.stdin.read
data = input().split()
N = int(data[0])

min_heap = []
result = []

for i in range(1, N + 1):
    x = int(data[i])

    if x == 0:
        if len(min_heap) == 0:
            result.append(0)
        else:
            result.append(heapq.heappop(min_heap))
    else:
        heapq.heappush(min_heap, x)

sys.stdout.write("\n".join(map(str, result)) + "\n")
