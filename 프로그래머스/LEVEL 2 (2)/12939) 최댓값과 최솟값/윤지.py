def solution(s):
    answer = ''
    
    arr = list(map(int, s.split()))
    
    min_num, max_num = arr[0], arr[0]
    for num in arr:
        min_num = min(min_num, num)
        max_num = max(max_num, num)
        
    answer = str(min_num) + ' ' + str(max_num)
    return answer
