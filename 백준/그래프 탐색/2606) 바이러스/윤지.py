from pprint import pprint
from collections import deque

# BFS
# 1. 세팅
# 2. WHILE 반복문
#   방문, 탐색
V = int(input())
E = int(input())

queue = deque([1])
visited = set()

# # 인접 리스트 풀이
# adj2 = [[] for _ in range(V+1)]
# # 간선 정보 입력
# for _ in range(E):
#     s, e = map(int, input().split())
#     adj2[s].append(e)
#     adj2[e].append(s)
#
# while queue:
#     # 방문
#     cur = queue.popleft()
#     visited.add(cur)
#
#     # 복잡한 문제는 여기서 후처리하기도 함
#     # 탐색
#     for nxt in adj2[cur]:
#         if nxt in visited:
#             continue
#         queue.append(nxt)
#
# pprint(len(visited)-1)

# 인접 행렬 풀이
# 간선 정보 입력하기
# 빈 판 만들기
adj = [[0]*(V+1) for _ in range(V+1)]

# 인접 행렬
for _ in range(E):
   s, e = map(int, input().split())
   adj[s][e] = 1
   adj[e][s] = 1

while queue:
    cur = queue.popleft()
    visited.add(cur)

    # 그래프 전체 돌면서 값이 1 이면 해당 행렬의 열 값 queue 에 담음
    for i in range(1, V+1):
        if adj[cur][i] == 1:
            if i in visited:
                continue
            queue.append(i)

pprint(len(visited)-1)

