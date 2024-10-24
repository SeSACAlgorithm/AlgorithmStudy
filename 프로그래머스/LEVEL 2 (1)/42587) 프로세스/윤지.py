from collections import deque


def solution(priorities, location):
    answer = 0
    
    que = deque()
    for i in range(len(priorities)):
        que.append((priorities[i], i))
        
    while que:
        current = que.popleft()
        chk = False
        
        for q in que:
            if current[0] < q[0]:
                chk = True
                break
                
        if chk:
            que.append(current)
        else:
            answer += 1
            if current[1] == location:
                break
    
    
    return answer
