def solution(n):
    answer = ''
    
    while n > 0:
        remainder = n % 3
        if remainder == 0:
            answer = '4' + answer
            n = n // 3 - 1
        else:
            answer = str(remainder) + answer
            n //= 3
    
    return answer
