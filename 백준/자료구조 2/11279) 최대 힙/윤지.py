from pprint import pprint
import sys
input = sys.stdin.readline
import heapq

N = int(input())
heap = []

for _ in range(N):
    cmd = -int(input())

    if not cmd:
        if not heap:
            print(0)
        else:
            print(-heapq.heappop(heap))

    if cmd:
        heapq.heappush(heap, cmd)
