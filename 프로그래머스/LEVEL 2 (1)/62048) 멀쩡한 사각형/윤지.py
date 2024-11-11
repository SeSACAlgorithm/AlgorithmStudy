import math

def solution(w,h):
    answer = 1
    gcd = math.gcd(w, h)
    
    # 사용 가능한 정사각형의 개수 계산
    answer = w * h - (w + h - gcd)

    return answer
