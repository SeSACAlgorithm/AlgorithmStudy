from collections import deque
from pprint import pprint

N, M = map(int, input().split())

train_arr = [['0']*20 for _ in range(N)]

for m in range(M):
    tmp_arr = list(map(int, input().split()))

    if len(tmp_arr) == 3:
        cmd = tmp_arr[0]
        train = tmp_arr[1]
        sit = tmp_arr[2]
    else:
        cmd = tmp_arr[0]
        train = tmp_arr[1]

    if cmd == 1:
        train_arr[train - 1][sit - 1] = '1'
    elif cmd == 2:
        train_arr[train - 1][sit - 1] = '0'
    elif cmd == 3:
        train_arr[train - 1].insert(0, '0')
        train_arr[train - 1].pop(20)

    elif cmd == 4:
        train_arr[train - 1].insert(20, '0')
        train_arr[train - 1].pop(0)

answers = set()

for train in train_arr:
    answers.add("".join(train))

print(len(answers))
