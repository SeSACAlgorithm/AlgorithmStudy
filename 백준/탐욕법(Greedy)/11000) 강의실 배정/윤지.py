import sys
import heapq

input = sys.stdin.read
data = input().splitlines()

N = int(data[0])

classes = []
heap = []

for i in range(1,N+1):
    S, T = map(int, data[i].split())
    classes.append((S, T))

classes.sort()

for S, T in classes:
    # 재사용
    if heap and heap[0] <= S:
        heapq.heappop(heap)

    # 끝나는 시간 추가
    heapq.heappush(heap, T)

print(len(heap))
