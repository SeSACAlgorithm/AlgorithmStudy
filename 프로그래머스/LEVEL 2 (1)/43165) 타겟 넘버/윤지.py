from collections import deque 

def solution(numbers, target):
    answer = 0
    que = deque([(0,0)])
    
    while que:
        index, cur_sum = que.popleft()
        
        if index == len(numbers):
            if cur_sum == target:
                answer += 1
        else:
            que.append((index + 1, cur_sum + numbers[index]))
            que.append((index + 1, cur_sum - numbers[index]))
                
    
    return answer
