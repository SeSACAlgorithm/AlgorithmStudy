
def solution(clothes):
    answer = 1
    
    set = {}
    
    for _, c in clothes:
        if c in set:
            set[c] += 1
        else:
            set[c] = 1
            
    for c in set.values():
        answer *= (c + 1)
    
    return answer -1
