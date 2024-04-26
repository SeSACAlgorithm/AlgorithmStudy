dx = [1, 0, -1]
dy = [0, 1, -1]

def solution(n):
    answer = []
    
    # 삼각형모양 달팽이집 생성
    tmp_arr = []
    for i in range(1, n + 1):
        row = [0] * i
        tmp_arr.append(row)

    num = 1
    tmp_arr[0][0] = num
    x, y, d = 0, 0, 0

    # 달팽이집 값 넣기
    while num < n*n / 2 + n / 2 :
        nx, ny = x + dx[d%3], y + dy[d%3]
        # 값 넣을 수 있으면 값 넣기
        if (0 <= nx < n and 0 <= ny < len(tmp_arr[nx])) and tmp_arr[nx][ny] == 0:
            num += 1
            tmp_arr[nx][ny] = num
            x, y = nx, ny
        else:
            d += 1


    for i in tmp_arr:
        for j in i:
            answer.append(j)
    
    return answer
