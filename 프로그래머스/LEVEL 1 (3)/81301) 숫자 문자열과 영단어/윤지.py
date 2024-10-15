def solution(s):
    answer = 0
    
    arr = {'zero' : 0, 'one' : 1, 'two' : 2, 'three' :3, 'four' : 4, 'five' : 5, 'six' : 6, 'seven' : 7, 'eight' : 8, 'nine' : 9}
    
    tmp = ''
    
    for i in s:
        if i.isdigit():
            answer = answer * 10 + int(i)
        else:
            tmp += i
            if tmp in arr:  
                answer = answer * 10 + arr[tmp]  
                tmp = ''  
    
    return answer
