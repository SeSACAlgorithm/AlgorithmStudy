from itertools import permutations

def solution(k, dungeons):
    answer = 0
    
    for p in permutations(dungeons):
        remains = k
        cnt = 0

        for min_f, use_f in p:
            if remains >= min_f:  
                remains -= use_f  
                cnt += 1
            else:
                break  

        answer = max(answer, cnt)
    
    return answer
