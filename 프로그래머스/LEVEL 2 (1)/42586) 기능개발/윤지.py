def solution(progresses, speeds):
    answer = []
    days = []
    
    for i in range(len(progresses)):
        remaining = 100 - progresses[i]
        day = (remaining + speeds[i] - 1) // speeds[i]  
        days.append(day)

    max_day = days[0]
    count = 1
    
    for i in range(1, len(progresses)):
        if days[i] <= max_day:
            count += 1
        else:
            answer.append(count)
            count = 1
            max_day = days[i]
    
    answer.append(count) 
    
    return answer
