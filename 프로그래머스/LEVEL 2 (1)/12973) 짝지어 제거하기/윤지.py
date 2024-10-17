def solution(s):
    
    stk = []
    
    for i in s:
        if stk and stk[-1] == i:
            stk.pop()
        else:
            stk.append(i)
            
    if not stk:
        answer = 1
    else:
        answer = 0
    
    return answer
