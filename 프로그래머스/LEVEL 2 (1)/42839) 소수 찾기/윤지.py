from itertools import permutations

def solution(numbers):
    answer = 0
    
    arr = set()  
    
    # 조합 생성
    for i in range(1, len(numbers) + 1):
        for perm in permutations(numbers, i):
            num = int("".join(perm))  
            arr.add(num)
    
    # 소수 개수 세기
    answer = 0
    for a in arr:
        if a < 2:
            continue
        for i in range(2, int(a**0.5) + 1):
            if a % i == 0:
                break
        else:
            answer += 1
    
    return answer
