def solution(s):
    answer = len(s)
    
    if len(s) == 1:
        answer = 1
        
    for i in range(1, len(s) // 2 + 1):
        sentences = ""
        cnt = 1
        tmp = s[:i]
        
        for j in range(i, len(s), i):
            cur = s[j:j+i]
            if cur == tmp:
                cnt += 1
            else:
                if cnt > 1:
                    sentences += str(cnt) + tmp
                else:
                    sentences += tmp
                
                tmp = cur
                cnt = 1
        if cnt > 1:
            sentences += str(cnt) + tmp
        else:
            sentences += tmp
        
        answer = min(answer, len(sentences))
    
    return answer
