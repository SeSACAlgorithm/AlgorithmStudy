from collections import deque
from pprint import pprint

N = int(input())

# 사각형의 한 변 길이 -> 4씩 증가하는 등차수열임
length = 4*N - 3
arr = [[' ']*length for _ in range(length)]

# 사각형 그리기
for i in range(length):
    for j in range(length):
        #가장 큰 사각형 그리기
        if i == 0 or j == 0 or i == length - 1 or j == length - 1:
            arr[i][j] = '*'
        
        # 짝수 열에 있는 사각형 그리기 (한칸 띄고 그리려면 열에 조건 걸어야 함)
        if i % 2 == 0 and (j > i-1 and j < length - i) :
            # 대각선 대칭 사각형 그리기
            arr[i][j] = '*'
            arr[length - i-1][length - j-1] = '*'

        if j % 2 == 0 and (i > j - 1 and i < length - j):
            arr[i][j] = '*'
            arr[length - i-1][length - j-1] = '*'

for a in arr:
    for b in a:
        print(*b, end = "")
    print("")



