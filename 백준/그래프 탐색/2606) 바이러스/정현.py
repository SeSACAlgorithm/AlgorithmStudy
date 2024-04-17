from collections import deque

V = int(input())
E = int(input())

# 빈 판 만들기
adj = [[] for _ in range(V+1)]

# 간선정보 입력받기
for _ in range(E):
    s, e = map(int, input().split())
    adj[s].append(e)
    adj[e].append(s)

# BFS
# 세팅
queue =deque([1])
visited = set()

# while 반복문
while queue:
    # 방문
    cur = queue.popleft()
    visited.add(cur)

    # 탐색
    for nxt in adj[cur]:
        if nxt in visited:
            continue
        queue.append(nxt) # 방문예정지에 내가 방금 탐색한 곳 넣어줘


print(len(visited) -1)

