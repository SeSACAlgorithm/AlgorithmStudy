from collections import deque
from pprint import pprint

N = int(input())

num_arr = [0] * 10
loc_arr = [' '] * 10

for n in range(N):
    num, loc = map(int, input().split())

    if loc_arr[num - 1] == ' ':
        loc_arr[num - 1] = loc
        continue

    if loc_arr[num - 1] != loc:
        num_arr[num - 1] += 1
        loc_arr[num - 1] = loc

print(sum(num_arr))
