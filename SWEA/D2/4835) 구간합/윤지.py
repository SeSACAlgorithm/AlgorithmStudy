from pprint import pprint
from collections import deque

for test_case in range(1, int(input()) + 1):
    N, M = map(int, input().split())

    numbers = list(map(int, input().split()))

    prefix_sum = sum(numbers[:M])
    max_sum, min_sum = prefix_sum, prefix_sum
    for i in range(1, N-M+1):
        prefix_sum = sum(numbers[i:M+i])
        if max_sum < prefix_sum:
            max_sum = prefix_sum

        if min_sum > prefix_sum:
            min_sum = prefix_sum

    ans = max_sum - min_sum

    print(f'#{test_case} {ans}')
