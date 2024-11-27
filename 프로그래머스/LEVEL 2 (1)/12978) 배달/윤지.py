from collections import deque

def solution(N, road, K):
    answer = 0

    graph = {i: [] for i in range(1, N + 1)}
    for a, b, c in road:
        graph[a].append((b, c))
        graph[b].append((a, c))
    
    # 최단 시간 초기화
    arr = [float('inf')] * (N + 1)
    arr[1] = 0
    que = deque([(1, 0)])
    
    while que:
        #방문
        cur_loc, cur_time = que.popleft()
        
        #탐색
        for nxt, time in graph[cur_loc]:
            tmp_time = cur_time + time
            
            if tmp_time < arr[nxt]:
                arr[nxt] = tmp_time
                que.append((nxt, tmp_time))
                
    for i in arr:
        if i <= K:
            answer += 1
    
    return answer
