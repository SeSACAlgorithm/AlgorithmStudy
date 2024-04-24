from collections import deque
from pprint import pprint

# 가로, 세로, 부분 문자열 전부 포함임

def check_palindrom(w):
    left = 0
    right = m - 1
    while left < right:
        if w[left] != w[right]:
            return False
            break
        left += 1
        right -= 1

    return True

def find_palindrom(strings):
    for text in strings:
        for i in range(n-m+1):
            words = text[i:i+m]
            if check_palindrom(words):
                return words
    return ''


T = int(input())

for t in range(T):
    n, m = map(int, input().split())

    strings = [list(map(str, input())) for _ in range(n)]

    board = [''.join(line) for line in strings]
    if find_palindrom(board):
        print(f'#{t+1} {find_palindrom(board)}')
        continue

    rotated_board = [''.join(line) for line in zip(*strings)]
    if find_palindrom(rotated_board):
        print(f'#{t+1} {find_palindrom(rotated_board)}')

