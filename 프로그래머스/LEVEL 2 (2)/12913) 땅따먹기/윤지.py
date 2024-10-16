def solution(land):
    answer = 0

    tmp = land[0][:]
    
    for i in range(1, len(land)):
        current_tmp = [0] * 4  

        current_tmp[0] = land[i][0] + max(tmp[1], tmp[2], tmp[3])
        current_tmp[1] = land[i][1] + max(tmp[0], tmp[2], tmp[3])
        current_tmp[2] = land[i][2] + max(tmp[0], tmp[1], tmp[3])
        current_tmp[3] = land[i][3] + max(tmp[0], tmp[1], tmp[2])

        tmp = current_tmp[:]
    
    answer = max(tmp)
    return answer
