from functools import cmp_to_key

def compare(x, y):
        # x + y > y + x -> x먼저
        if x + y > y + x:
            return -1  # x먼저
        elif x + y < y + x:
            return 1  # y먼저
        else:
            return 0  # 동일하다면 순서 상관 없음

def solution(numbers):
    
    numbers = list(map(str, numbers))
    
    # 커스텀 함수 설정
    numbers.sort(key=cmp_to_key(compare))
    largest_number = ''.join(numbers)
    
    answer = str(int(largest_number))
    return answer
    
