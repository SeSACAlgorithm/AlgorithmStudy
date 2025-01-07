from collections import deque

N, M = map(int, input().split())
idx = list(map(int, input().split()))
queue = deque(list(i+1 for i in range(N)))

cnt = 0

for i in idx:
    while True:
        if queue[0] == i:
            queue.popleft()
            break
        else:
            if queue.index(i) < len(queue)/2:
                while queue[0] != i:
                    queue.append(queue.popleft())
                    cnt += 1
            else:
                while queue[0] != i:
                    queue.appendleft(queue.pop())
                    cnt += 1

print(cnt)
