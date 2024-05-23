def solution(s):
    answer = []
    cnt = 0
    zeros_cnt = 0
    
    while s != "1":
        cnt += 1
        zeros_cnt += s.count("0")
        s = s.replace("0", "")
        
        # python 이진법 변환 함수 : bin()
        s = bin(len(s))[2:]
    
    answer.append(cnt)
    answer.append(zeros_cnt)
    
    return answer
