from collections import deque
from pprint import pprint

def box_chk(i, j, check):
    # 박스 체크용 배열 초기화
    box_arr = []
    for x in range(i, i+3):
        for y in range(j, j+3):
            box_arr.append(numbers[x][y])
            box_arr.sort()
            if x == i+2 and y == j+2 and box_arr != ans:
                check = False
                break
        if check == False:
            break

    return check

T = int(input())
ans = [1, 2, 3, 4, 5, 6, 7, 8, 9]
ans.sort()

for t in range(T):
    numbers = [list(map(int, input().split())) for _ in range(9)]
    check = True
    
    # 행 검증
    for i in range(9):
        # 행 배열 초기화
        row_arr = []
        for j in range(9):
            row_arr.append(numbers[i][j])
            row_arr.sort()
        
            if j == 8 and row_arr != ans:
                check = False
                break
        if check == False:
            break

    # 열 검증
    if check :
        col_arr = []
        for i in range(0, 9):
            col_arr = []
            for j in range(0, 9):
                col_arr.append(numbers[j][i])
                col_arr.sort()
                if j == 8 and col_arr != ans:
                    check = False
                    break
            if check == False:
                break

    # 박스 검증
    if check:
        for i in range(0,9,3):
            for j in range(0, 9, 3):
                if check :
                    check = box_chk( i, j, check)

    if check:
        answer = 1
    else:
        answer = 0

    print(f"#{t+1} {answer}")
