import heapq

N = int(input())

heap_arr = []

for _ in range(N):
    row = list(map(int, input().split()))
    for num in row:
        heapq.heappush(heap_arr, num)
        if len(heap_arr) > N:
            heapq.heappop(heap_arr)

print(heap_arr[0])
