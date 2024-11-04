import heapq
import sys

input = sys.stdin.read
data = input().split()
N = int(data[0])

heap = []
arr = []
for i in range(1,N+1):
    tmp = int(data[i])

    if tmp != 0:
        heapq.heappush(heap, (abs(tmp), tmp))
    else:
        if heap:
            arr.append(heapq.heappop(heap)[1])
        else:
            arr.append(0)


for a in arr:
    print(a)






