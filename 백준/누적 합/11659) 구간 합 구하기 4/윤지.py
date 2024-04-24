from pprint import pprint
from collections import deque

N, M = map(int, input().split())

numbers = list(map(int, input().split()))
results = []

# 완탐 -> 시간 초과 / 누적합 사용
# 구간 별 누적합 배열 생성
numbers_sum = [0]*(N+1)
for i in range(1, N+1):
    numbers_sum[i] = numbers_sum[i-1] + numbers[i-1]

for _ in range(M):
    # 구간 입력
    i, j = map(int, input().split())

    result = numbers_sum[j] - numbers_sum[i - 1]
    results.append(result)

for result in results:
    print(result)
