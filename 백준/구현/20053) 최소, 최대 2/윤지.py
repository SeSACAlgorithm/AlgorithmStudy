from pprint import pprint
import sys
input = sys.stdin.readline

T = int(input())

for t in range(T):
    N = int(input())
    arr = list(map(int, input().split()))

    max_num = arr[0]
    min_num = arr[0]

    for i in range(1, len(arr)):
        if arr[i] <= min_num:
            min_num = arr[i]
        if arr[i] >= max_num:
            max_num = arr[i]

    print(f"{min_num} {max_num}")
