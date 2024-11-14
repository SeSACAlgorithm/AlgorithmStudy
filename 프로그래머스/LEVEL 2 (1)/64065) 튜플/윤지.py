def solution(s):
    answer = []
    
    s = s[2:-2]
    s = s.split("},{")
    
    arr = []
    
    for s_a in s:
        cur_set = set()
        for a in s_a.split(','):
            cur_set.add(int(a))
        arr.append(cur_set)
        
    arr.sort(key = len)
    
    for a  in arr:
        answer.append((a - set(answer)).pop())
    
    return answer
