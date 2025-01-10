dr = [-1, 1, 0, 0]
dc = [0, 0, -1, 1]

R, C, N = map(int, input().split())
board = [list(input()) for _ in range(R)]
answer = []

def plant_bombs(board):
    for row in board:
        for r in row:
            if r == '.':
                r = 'O'
    return board

def bombs(board):
    tmp_board = list(['O'] * C for _ in range(R))

    for r in range(R):
        for c in range(C):
            if board[r][c] == 'O':
                tmp_board[r][c] = '.'
                for d in range(4):
                    nr, nc = r + dr[d], c + dc[d]
                    if 0 <= nr < R and 0 <= nc < C:
                        tmp_board[nr][nc] = '.'
    return tmp_board

if N == 1:
    answer = board
elif N % 2 == 0:
    answer = list(['O'] * C for _ in range(R))
else:
    state_after_3 = bombs(plant_bombs(board))
    state_after_5 = bombs(plant_bombs(state_after_3))
    if (N // 2) % 2 == 1:
        answer = state_after_3
    else:
        answer = state_after_5

for a in answer:
    print(''.join(a))
