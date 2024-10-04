def solution(n):
    answer = 0
    
    count_one_n = bin(n).count('1')
    next_number = n + 1
    
    while True:
        if bin(next_number).count('1') == count_one_n:
            return next_number
        next_number += 1
    
    answer = next_number
    return answer
